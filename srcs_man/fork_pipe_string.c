//#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include "../libft/libft.h"
#include <sys/wait.h>
#include <errno.h>
#include <time.h>

// 2 processes
// 1) Child process should generate random numbers and send them to the parent
// 2) Parent is going to sum all the numbers and print the result

int	main(int argc, char *argv[])
{
	int	fd[2];
	int	pid;

	if (pipe(fd) == -1)
		return (1);
	pid = fork();
	if (pid == -1)
		return (2);
	if (pid == 0)
	{
		// Child process
		char	str[200];

		close (fd[0]);
		printf("Input string: ");
		fgets(str, 200, stdin);
		str[strlen(str) - 1] = '\0';

		int	len = strlen(str) + 1;

		if (write(fd[1], &len, sizeof(int)) == -1)
			return (3);
		if (write(fd[1], str, sizeof(char) * len) == -1)
			return (4);
		close(fd[1]);
	}
	else
	{
		// Parent process
		char	str[200];
		int	len;

		close(fd[1]);
		if (read(fd[0], &len, sizeof(int)) == -1)
			return (5);
		if (read(fd[0], str, sizeof(char) * len) == -1)
			return (6);
		printf("Received: %s\n", str);
		close(fd[0]);
		wait(NULL);
	}
	return (0);
}
