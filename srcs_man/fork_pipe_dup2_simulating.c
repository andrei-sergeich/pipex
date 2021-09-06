//#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include "../libft/libft.h"
#include <sys/wait.h>
#include <errno.h>
#include <time.h>

int	main(int argc, char *argv[])
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (pipe(fd) == -1)
		ft_perror("ERROR");
	pid1 = fork();
	if (pid1 == -1)
		ft_perror("ERROR");
	if (pid1 == 0)
	{
		// Child process 1 (ping)
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("ping", "ping", "-c", "3", "google.com", NULL);
	}
	pid2 = fork();
	if (pid2 == -1)
		ft_perror("ERROR");
	if (pid2 == 0)
	{
		// Child process 1 (grep)
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("grep", "grep", "rtt", NULL);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
