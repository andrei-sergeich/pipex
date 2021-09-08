#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <string.h>
# include <sys/wait.h>
# include <errno.h>

//typedef struct s_lst
//{
//	int		fd[2];
//	char	**env;
//	char	**cmd;
//	char	*path;
//}	t_lst;

void	pipex(int argc, char *argv[], char *envp[]);
void	first_command_executing(int *fd, char *argv[], char *envp[]);
void	second_command_executing(int *fd, char *argv[], char *envp[]);

void	executer(char *cmd, char *envp[]);
char	**splitting_paths(char *envp[]);
char	*ft_strjoin_mod(char const *s1, char connector, char const *s2);
void	liberator(char **free_me);

void	here_doc(char *argv[], char *envp[]);

#endif
