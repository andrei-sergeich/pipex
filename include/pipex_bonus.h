/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 22:30:12 by cmero             #+#    #+#             */
/*   Updated: 2021/09/09 22:30:13 by cmero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <string.h>
# include <sys/wait.h>
# include <errno.h>

void	pipex(int argc, char *argv[], char *envp[]);
void	here_doc(int argc, char *argv[]);
void	write_to_limiter(int *fd, char *limiter);
void	command_executing(char *cmd, char *envp[]);
void	executer(char *cmd, char *envp[]);

char	**splitting_paths(char *envp[]);
char	*ft_strjoin_mod(char const *s1, char connector, char const *s2);
void	liberator(char **free_me);
int		opener(char *path, char flag);

#endif
