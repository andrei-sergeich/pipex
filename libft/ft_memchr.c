/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:36:51 by cmero             #+#    #+#             */
/*   Updated: 2021/08/13 13:36:52 by cmero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		x;

	x = 0;
	while (x < n)
	{
		if (*((unsigned char *)s + x) == (unsigned char)c)
			return ((unsigned char *)s + x);
		x++;
	}
	return (NULL);
}
