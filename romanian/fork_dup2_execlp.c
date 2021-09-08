#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include "libft.h"
#include <sys/wait.h>
#include <errno.h>
#include <time.h>

int	main(int argc, char *argv[])
{
	int	pid;
	int	err;
	int	wtstat;
	int	statCode;
	int	file;

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
		err = execlp("ping", "ping", "-c", "3", "google.com", NULL);
		if (err == -1)
		{
			printf("Could not find program to execute\n");
			return (1);
//			ft_perror("Could not find program to execute");
		}
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
