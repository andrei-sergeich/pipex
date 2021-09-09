#include "../include/pipex_bonus.h"

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
				ft_perror("ERROR - 7");
		}
		free(the_way);
		it++;
	}
	liberator(command);
	liberator(paths);
	perror("ERROR - 8");
}

//void	here_doc(int argc, char *argv[], char *envp[])
//{
//	char	*line;
//	(void)argv;
//	(void)envp;
//
//	if (argc < 6)
//		ft_error("Error: wrong count of arguments");
//
//	ft_putstr_fd("pipe heredoc> ", 1);
//	while (get_next_line(0, &line))
//	{
//		ft_putstr_fd("pipe heredoc> ", 1);
//		if (ft_strcmp(argv[2], line) == 0)
//		{
////			printf("%s\n", line);
//			break ;
//		}
////		ft_putendl_fd(line, 1);
//		free(line);
//	}
//	free(line);
//}

void	command_executing(char *cmd, char *envp[])
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		ft_perror("ERROR - 3");
	pid = fork();
	if (pid == -1)
		ft_perror("ERROR - 4");
	if (pid == 0)
	{
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			ft_perror("ERROR - 5");
		executer(cmd, envp);
	}
	else
	{
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			ft_perror("ERROR - 6");
		waitpid(pid, NULL, 0);
	}
}


void	pipex(int argc, char *argv[], char *envp[])
{
	int	num;
	int	fd_in;
	int	fd_out;


	if (argc < 5)
		ft_error("Error: wrong count of arguments");

//	if (ft_strcmp(argv[1], "here_doc") == 0)
//		here_doc(argc, argv, envp);
	fd_in = opener(argv[1], 'I');
	fd_out = opener(argv[argc - 1], 'O');

	if (dup2(fd_in, STDIN_FILENO) == -1)
		ft_perror("ERROR - 1");

	num = 2;
	while (num < argc - 2)
	{
		command_executing(argv[num], envp);
		num++;
	}

	if (dup2(fd_out, STDOUT_FILENO) == -1)
		ft_perror("ERROR - 2");

	executer(argv[argc - 2], envp);
}
