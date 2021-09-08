//#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include "libft.h"
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
		return (2);
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		// Child process
		int	n, i;
		int	arr[10];

		close(fd[0]);
		i = 0;
		srand(time(NULL));
		n = rand() % 10 + 1;
		printf("Generated: ");
		while (i < n)
		{
			arr[i] = rand() % 11;
			printf("%d ", arr[i]);
			i++;
		}
		printf("\n");
		if (write(fd[1], &n, sizeof(int)) == -1)
			return (4);
		printf("Sent n = %d\n", n);
		if (write(fd[1], arr, sizeof(int) * n) == -1)
			return (3);
		printf("Sent array\n");
		close(fd[1]);
	}
	else
	{
		// Parent process
		int	n, i, sum;
		int	arr[10];

		close(fd[1]);
		i = 0;
		sum = 0;
		if (read(fd[0], &n, sizeof(int)) == -1)
			return (5);
		printf("Received n = %d\n", n);
		if (read(fd[0], arr, sizeof(int) * n) == -1)
			return (6);
		printf("Received array\n");
		close(fd[0]);
		while (i < n)
		{
			sum += arr[i];
			i++;
		}
		printf("result is %d\n", sum);
		wait(NULL);
	}

	return (0);
}
