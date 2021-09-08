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

	pid = fork();
	if (pid == -1)
		ft_perror("Error fork");
	if (pid == 0)
	{
		// Child process
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
