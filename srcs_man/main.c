//#include <stdio.h>
#include <string.h>
//#include <stdlib.h>
#include "../libft/libft.h"

int main()
{
	int	id;

	id = fork();
	if (id == 0)
		printf("hello from child\n");
	else
	{
		fork();
		printf("hello from main\n");
	}
//	printf("%s\n", envp[0]);
	return (0);
}

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