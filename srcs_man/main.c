//#include <stdio.h>
#include <string.h>
//#include <stdlib.h>
#include "../libft/libft.h"

int main()
{
	int	id;
	int	n;
	int	i;

	id = fork();
	if (id == 0)
		n = 1;
	else
		n = 6;
	if (id != 0)
		wait(&id);
	i = n;
	while (i < n + 5)
	{
		printf("%d ", i);
		fflush(stdout);
		i++;
	}
	printf("\n");
	return (0);
}

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
//	}
////	exit(EXIT_SUCCESS);
//}