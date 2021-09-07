//#include <time.h>
#include "../include/pipex.h"

int	ft(t_lst *var, char *argv[])
{
	int	pid;
	int	wtstat;
	int	statCode;
	int	file;

	int	it = 0;
	char	**cmd;

	pid = fork();
	if (pid == -1)
		ft_perror("Error fork");
	if (pid == 0)
	{
		// Child process
		file = open("output.txt", O_WRONLY | O_CREAT, 0777);
		if (file == -1)
			return (1);
//			ft_perror("Error open");
		printf("The fd to output.txt is %d\n", file);
		dup2(file, STDOUT_FILENO);
		close(file);
		cmd = ft_split(argv[1], ' ');
		while (var->env[it])
		{
			var->path = ft_strjoin_mod(var->env[it], '/', cmd[0]);
			execve(var->path, cmd, NULL);
			free(var->path);
			it++;
		}
		free(cmd);
		ft_perror("ERROR");
	}
	else
	{
		// Parent process
		wait(&wtstat);
		if (WIFEXITED(wtstat))
		{
			statCode = WEXITSTATUS(wtstat);
			if (statCode == 0)
				printf ("Success!\n");
			else
				printf("Failure with status code %d\n", statCode);
		}
		printf("Some post processing goes here\n");
	}
	return (0);
}

void	parsing_path(t_lst *var, char *envp[])
{
	int	it;

	it = 0;
	while (envp[it])
	{
		if (!ft_strncmp(envp[it], "PATH=", 5))
		{
			var->env = ft_split(envp[it] + 5, ':');
			if (var->env == NULL)
				ft_error("Error: no PATH or bad split");
		}
		it++;
	}
}

void	pipex(int argc, char *argv[], char *envp[])
{
	t_lst	var;

	parsing_path(&var, envp);
	ft(&var, argv);
	free(var.env);
}

int	main(int argc, char *argv[], char *envp[])
{
	if (argc != 2) /* REPLACE ON 5 */
		ft_error("Error: wrong count of arguments");
	pipex(argc, argv, envp);
	return (0);
}