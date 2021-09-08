#include "../include/pipex.h"

int	main(int argc, char *argv[], char*envp[])
{
	if (argc != 5)
		ft_error("Error: wrong count of arguments");
	pipex(argv, envp);
	return (0);
}
