/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:45:00 by cmero             #+#    #+#             */
/*   Updated: 2021/08/13 13:45:01 by cmero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	st;
	size_t	en;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	st = 0;
	en = ft_strlen(s1);
	while (ft_strchr(set, s1[st]) && s1[st])
		st++;
	while (ft_strchr(set, s1[en - 1]) && en > st)
		en--;
	str = (char *) malloc(sizeof(char) * (en - st + 1));
	if (!str)
		return (NULL);
	str = ft_substr(s1, st, en - st);
	return (str);
}
