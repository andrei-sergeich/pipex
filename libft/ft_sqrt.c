/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 17:55:37 by cmero             #+#    #+#             */
/*   Updated: 2021/08/19 13:06:25 by cmero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	// int x;
	// int y;

	// x = 0;
	// y = 0;
	// if (nb < 1)
	// 	return (0);
	// while (y <= nb)
	// {
	// 	y = x * x;
	// 	x++;
	// }
	// if ((x - 2) * (x - 2) == nb)
	// 	return (x - 2);
	// else
	// 	return (0);

	// int	racine;
	// int	sqrt;

	// racine = 1;
	// sqrt = 0;
	// while (racine <= nb / 2)
	// {
	// 	sqrt = racine * racine;
	// 	if (sqrt == nb)
	// 		return (racine);
	// 	racine = racine + 1;
	// }
	// return (0);

	// int	i;

	// i = 0;
	// while (i * i < nb)
	// 	i++;
	// if (i * i == nb)
	// 	return (i);
	// else
	// 	return (0);

	int	i;

	i = 0;
	if (nb <= 0)
		return (0);
	while (++i < 46341)
		if (i * i == nb)
			return (i);
	return (0);

	// int	begin;
	// int	end;
	// int	mid;

	// begin = 0;
	// end = ft_find_max(1, nb);
	// while (end - begin > 1)
	// {
	// 	mid = begin + (end - begin) / 2;
	// 	if (nb > mid * mid)
	// 		begin = mid;
	// 	else
	// 		end = mid;
	// }
	// return (mid);
}
