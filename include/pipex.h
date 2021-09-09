#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <string.h>
# include <sys/wait.h>
# include <errno.h>

void	pipex(int argc, char *argv[], char *envp[]);
void	first_command_executing(int *fd, char *argv[], char *envp[]);
void	second_command_executing(int *fd, char *argv[], char *envp[]);
void	executer(char *cmd, char *envp[]);

char	**splitting_paths(char *envp[]);
char	*ft_strjoin_mod(char const *s1, char connector, char const *s2);
void	liberator(char **free_me);

#endif
