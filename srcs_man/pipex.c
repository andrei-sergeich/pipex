/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 22:26:52 by cmero             #+#    #+#             */
/*   Updated: 2021/09/14 21:00:13 by cmero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	ft_perror("ERROR");
}

void	first_command_executing(int *fd, char *argv[], char *envp[])
{
	int	f_in;

	f_in = open(argv[1], O_RDONLY);
	if (f_in < 0)
		ft_perror("ERROR (input file)");
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_perror("ERROR");
	if (dup2(f_in, STDIN_FILENO) == -1)
		ft_perror("ERROR");
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
		ft_perror("ERROR (output file)");
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_perror("ERROR");
	if (dup2(f_out, STDOUT_FILENO) == -1)
		ft_perror("ERROR");
	close(fd[1]);
	close(f_out);
	close(fd[0]);
	executer(argv[3], envp);
}

void	pipex(int argc, char *argv[], char *envp[])
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (argc != 5)
		ft_error("Error: wrong count of arguments");
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
