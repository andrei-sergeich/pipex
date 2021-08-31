//#include <stdio.h>
#include <string.h>
//#include <stdlib.h>
#include "../libft/libft.h"

//int main(int argc, char **argv, char **envp)
//{
//	if (argc < 2)
//		ft_perror("Error: ");
//	else
//		printf("%s\n", envp[0]);
//	return 0;
//}

int main(int argc, char *argv[])
{
	int	j;

	if (argc < 2)
		ft_perror("Error");
	else
	{
		for (j = 0; j < argc; j++)
			printf("argv[%d]: %s\n", j, argv[j]);
	}
//	exit(EXIT_SUCCESS);
}