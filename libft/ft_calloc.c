/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:26:18 by cmero             #+#    #+#             */
/*   Updated: 2021/08/13 13:30:56 by cmero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	x;

	x = 0;
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	while (x < count * size)
	{
		ptr[x] = 0;
		x++;
	}
	return ((void *)ptr);
}
