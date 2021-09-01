//#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
#include "../libft/libft.h"
#include <sys/wait.h>
#include <errno.h>

int	main(int argc, char *argv[])
{
	int	id1;
	int	id2;

	id1 = fork();
	id2 = fork();
	if (id1 == 0)
	{
		if (id2 == 0)
			printf("We are process Y\n");
		else
			printf("We are process X\n");
	}
	else
	{
		if (id2 == 0)
			printf("We are process Z\n");
		else
			printf("We are the Parent process\n");
	}
	while (wait(NULL) != -1 || errno != ECHILD);
//		printf("Waited for a child to finish\n");
	return (0);
}

//int	main(void)
//{
//	int	id;
//	int	res;
//
//	id = fork();
//	if (id == 0)
//		sleep(1);
//	printf("Current ID: %d, Parent ID: %d\n", getpid(), getppid());
//	res = wait(NULL);
//	if (res == -1)
//		printf("No children to wait for\n");
//	else
//		printf("%d finished execution\n", res);
//	return (0);
//}

//int main()
//{
//	int	id;
//	int	n;
//	int	i;
//
//	id = fork();
//	if (id == 0)
//		n = 1;
//	else
//		n = 6;
//	if (id != 0)
//		wait(NULL);
//	i = n;
//	while (i < n + 5)
//	{
//		printf("%d ", i);
//		fflush(stdout);
//		i++;
//	}
//	if (id != 0)
//		printf("\n");
//	return (0);
//}

//int main()
//{
//	int	id;
//
//	id = fork();
//	if (id == 0)
//		printf("hello from child\n");
//	else
//	{
//		fork();
//		printf("hello from main\n");
//	}
////	printf("%s\n", envp[0]);
//	return (0);
//}

//int	main(int argc, char *argv[], char *envp[])
//{
//	int	j;
//
//	if (argc < 2)
//		ft_perror("Error");
//	else
//	{
//		for (j = 0; j < argc; j++)
//			printf("argv[%d]: %s\n", j, argv[j]);
//		for (j = 0; envp[j]; j++)
//			if (!ft_strncmp(envp[j], "PATH=", 5))
//				printf("%s\n", envp[j]);
//	}
//	exit(EXIT_SUCCESS);
//}
