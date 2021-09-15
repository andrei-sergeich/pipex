/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 22:26:59 by cmero             #+#    #+#             */
/*   Updated: 2021/09/14 21:00:17 by cmero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	**splitting_paths(char *envp[])
{
	int		it;
	char	**paths;

	it = 0;
	while (envp[it])
	{
		if (!ft_strncmp(envp[it], "PATH=", 5))
		{
			paths = ft_split(envp[it] + 5, ':');
			return (paths);
		}
		it++;
	}
	return (NULL);
}

char	*ft_strjoin_mod(char const *s1, char connector, char const *s2)
{
	char	*str;
	size_t	x;
	size_t	y;

	if (!s1 || !s2)
		return (NULL);
	str = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!str)
		return (NULL);
	x = 0;
	y = 0;
	while (s1[y])
		str[x++] = s1[y++];
	str[x++] = connector;
	y = 0;
	while (s2[y])
		str[x++] = s2[y++];
	str[x] = '\0';
	return (str);
}

void	liberator(char **free_me)
{
	int		it;

	it = 0;
	while (free_me[it])
	{
		free(free_me[it]);
		it++;
	}
	free(free_me);
}
