/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:37:10 by cmero             #+#    #+#             */
/*   Updated: 2021/08/13 13:37:11 by cmero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t l)
{
	size_t	x;

	x = 0;
	if (!dst && !src)
		return (0);
	while (x < l)
	{
		*((char *)dst + x) = *((const char *)src + x);
		x++;
	}
	return (dst);
}
