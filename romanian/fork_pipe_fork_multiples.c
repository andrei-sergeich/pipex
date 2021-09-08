//#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include <sys/wait.h>
#include <errno.h>
#include <time.h>

#define PROCESS_NUM 10

int	main(int argc, char *argv[])
{
	int	pids[PROCESS_NUM];
	int	pipes[PROCESS_NUM + 1][2];
	int	i;

	i = 0;
	while (i < PROCESS_NUM + 1)
	{
		if (pipe(pipes[i]) == -1)
			return (1);
		i++;
	}
	i = 0;
	while (i < PROCESS_NUM)
	{
		pids[i] = fork();
		if (pids[i] == -1)
			return (2);
		if (pids[i] == 0)
		{
			// Child process
			int	j;
			j = 0;
			while (j < PROCESS_NUM + 1)
			{
				if (i != j)
					close(pipes[j][0]);
				if (i + 1 != j)
					close(pipes[j][1]);
				j++;
			}
			int	x;
			if (read(pipes[i][0], &x, sizeof(int )) == -1)
				return (3);
			printf("(%d) Cot %d\n", i, x);
			x++;
			if (write(pipes[i + 1][1], &x, sizeof(int )) == -1)
				return (4);
			printf("(%d) Sent %d\n", i, x);
			close(pipes[i][0]);
			close(pipes[i + 1][1]);
			return (0);
		}
		i++;
	}
	// Main process
	int	j;
	j = 0;
	while (j < PROCESS_NUM + 1)
	{
		if (j != PROCESS_NUM)
			close(pipes[j][0]);
		if (j != 0)
			close(pipes[j][1]);
		j++;
	}
	int y = 5;
	printf("Main process sent %d\n", y);
	if (write(pipes[0][1], &y, sizeof(int)) == -1)
		return (5);
	if (read(pipes[PROCESS_NUM][0], &y, sizeof(int)) == -1)
		return (6);
	printf("The final result is %d\n", y);
	close(pipes[0][1]);
	close(pipes[PROCESS_NUM][0]);
	i = 0;
	while (i < PROCESS_NUM)
	{
		wait(NULL);
		i++;
	}
	return (0);
}
