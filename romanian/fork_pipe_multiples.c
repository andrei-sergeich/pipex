//#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include <sys/wait.h>
#include <errno.h>
#include <time.h>

int	main(int argc, char *argv[])
{
	int	fd[3][2];
	int	i;
	int	pid1;
	int	pid2;

	i = 0;
	while (i < 3)
	{
		if (pipe(fd[i]) == -1)
			return (1);
		i++;
	}
	pid1 = fork();
	if (pid1 == -1)
		return (2);
	if (pid1 == 0)
	{
		// Child process 1
		int	x;
		close(fd[0][1]);
		close(fd[1][0]);
		close(fd[2][0]);
		close(fd[2][1]);
		if (read(fd[0][0], &x, sizeof(int)) == -1)
		{
			return (3);
		}
		x += 5;
		if (write(fd[1][1], &x, sizeof(int)) == - 1)
		{
			return (4);
		}
		close(fd[0][0]);
		close(fd[1][1]);
		return (0);
	}
	pid2 = fork();
	if (pid2 == -1)
	{
		return (5);
	}
	if (pid2 == 0)
	{
		// Child process 2
		int	x;
		close(fd[0][0]);
		close(fd[0][1]);
		close(fd[1][1]);
		close(fd[2][0]);
		if (read(fd[1][0], &x, sizeof(int)) == -1)
		{
			return (6);
		}
		x += 5;
		if (write(fd[2][1], &x, sizeof(int)) == - 1)
		{
			return (7);
		}
		close(fd[1][0]);
		close(fd[2][1]);
		return (0);
	}
	// Parent process
	close(fd[0][0]);
	close(fd[1][0]);
	close(fd[1][1]);
	close(fd[2][1]);
	int	x;
	printf("Input number: ");
	scanf("%d", &x);
	if (write(fd[0][1], &x, sizeof(int)) == -1)
	{
		return (8);
	}
	if (read(fd[2][0], &x, sizeof(int)) == -1)
		return (9);
	printf("Result is %d", x);
	close(fd[0][1]);
	close(fd[2][0]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
