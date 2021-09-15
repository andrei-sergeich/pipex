/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:44:36 by cmero             #+#    #+#             */
/*   Updated: 2021/09/14 21:01:06 by cmero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	it;

	it = 0;
	while (s1[it] && s2[it] && (s1[it] == s2[it]))
		it++;
	return ((unsigned char)s1[it] - (unsigned char)s2[it]);
}
