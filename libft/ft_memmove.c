/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:37:14 by cmero             #+#    #+#             */
/*   Updated: 2021/08/13 13:37:15 by cmero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t l)
{
	size_t	x;

	if (src == dst)
		return (dst);
	if (src < dst)
	{
		x = l;
		while (x--)
			*((char *)dst + x) = *((char *)src + x);
	}
	else
	{
		x = 0;
		while (x < l)
		{
			*((char *)dst + x) = *((char *)src + x);
			x++;
		}
	}
	return (dst);
}
