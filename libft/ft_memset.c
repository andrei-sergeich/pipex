/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:37:17 by cmero             #+#    #+#             */
/*   Updated: 2021/08/13 13:37:18 by cmero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int x, size_t len)
{
	size_t			z;
	unsigned char	*nstr;

	z = 0;
	nstr = (unsigned char *)str;
	while (z < len)
	{
		nstr[z] = (unsigned char)x;
		z++;
	}
	return (str);
}
