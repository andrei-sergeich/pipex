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

void	here_doc(int argc, char *argv[])
{
	char	*line;
	int		fd[2];
	int		pid;

	if (argc < 6)
		ft_error("Error: wrong count of arguments");
	if (pipe(fd) == -1)
		perror("ERROR - 9");
	pid = fork();
	if (pid == -1)
		ft_perror("ERROR - 10");
	if (pid == 0)
	{
		close(fd[0]);
		line = ft_strdup("");
		while (ft_strcmp(argv[2], line))
		{
			free(line);
			ft_putstr_fd("pipe heredoc> ", 1);
			if (get_next_line(0, &line))
			{
				if (write(fd[1], line, ft_strlen(line)) == -1)
					perror("ERROR - 11");
				if (write(fd[1], "\n", 1) == -1)
					perror("ERROR - 12");
			}
		}
		exit(0);
	}
	else
	{
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			ft_perror("ERROR - 13");
		waitpid(pid, NULL, 0);
	}
}

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
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		num = 3;
		here_doc(argc, argv);
		fd_out = opener(argv[argc - 1], 'h');
	}
	else
	{
		num = 2;
		fd_in = opener(argv[1], 'I');
		fd_out = opener(argv[argc - 1], 'O');
		if (dup2(fd_in, STDIN_FILENO) == -1)
			ft_perror("ERROR - 1");
	}
	while (num < argc - 2)
		command_executing(argv[num++], envp);
	if (dup2(fd_out, STDOUT_FILENO) == -1)
		ft_perror("ERROR - 2");
	executer(argv[argc - 2], envp);
}
