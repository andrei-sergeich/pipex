#include "../include/pipex.h"

void	executer(char *cmd, char *envp[])
{
	int		it;
	char	**command;
	char	**paths;
	char	*the_way;

	command = ft_split(cmd, ' ');
	paths = splitting_paths(envp);
	if (paths == NULL)
		ft_error("Error: no PATH");
	it = 0;
	while (paths[it])
	{
		the_way = ft_strjoin_mod(paths[it], '/', command[0]);
		if (access(the_way, F_OK) == 0)
		{
			if (execve(the_way, command, NULL) == -1)
				ft_perror("ERROR");
		}
		free(the_way);
		it++;
	}
	liberator(command);
	liberator(paths);
	perror("ERROR");
}

void	first_command_executing(int *fd, char *argv[], char *envp[])
{
	int	f_in;

	f_in = open(argv[1], O_RDONLY);
	if (f_in < 0)
		ft_error("Error: can't open input file");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		perror("ERROR");
	if (dup2(f_in, STDIN_FILENO) == -1)
		perror("ERROR");
	close(fd[0]);
	close(f_in);
	close(fd[1]);
	executer(argv[2], envp);
}

void	second_command_executing(int *fd, char *argv[], char *envp[])
{
	int	f_out;

	f_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (f_out < 0)
		ft_error("Error: can't open output file");
	if (dup2(fd[0], STDIN_FILENO) == -1)
		perror("ERROR");
	if (dup2(f_out, STDOUT_FILENO) == -1)
		perror("ERROR");
	close(fd[1]);
	close(f_out);
	close(fd[0]);
	executer(argv[3], envp);
}

void	here_doc(char *argv[], char *envp[])
{
	char	*line;
	(void)argv;
	(void)envp;

	ft_putstr_fd("pipe heredoc> ", 1);
	while (get_next_line(0, &line))
	{
		ft_putstr_fd("pipe heredoc> ", 1);
		if (ft_strcmp(argv[2], line) == 0)
		{
//			printf("%s\n", line);
			break ;
		}
//		ft_putendl_fd(line, 1);
		free(line);
	}
	free(line);
}

void	pipex(int argc, char *argv[], char *envp[])
{
	int	fd[2];
	int	pid1;
	int	pid2;

//	argc_and_heredoc_check(argc, argv, envp);
	if (argc < 5)
		ft_error("Error: wrong count of arguments");
//	if (ft_strcmp(argv[1], "here_doc") == 0)
//		here_doc(argv, envp);
	if (pipe(fd) == -1)
		ft_perror("ERROR");
	pid1 = fork();
	if (pid1 == -1)
		ft_perror("ERROR");
	if (pid1 == 0)
		first_command_executing(fd, argv, envp);
	pid2 = fork();
	if (pid2 == -1)
		ft_perror("ERROR");
	if (pid2 == 0)
		second_command_executing(fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
