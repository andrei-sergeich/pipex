#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <string.h>
# include <sys/wait.h>
# include <errno.h>

typedef struct s_lst
{
	char	**env;
	char	*path;
}	t_lst;

void	pipex(int argc, char *argv[], char *envp[]);
void	parsing_path(t_lst *var, char *envp[]);


char	*ft_strjoin_mod(char const *s1, char connector, char const *s2);

#endif
