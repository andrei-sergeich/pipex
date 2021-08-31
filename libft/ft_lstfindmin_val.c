/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfindmin_val.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:50:50 by cmero             #+#    #+#             */
/*   Updated: 2021/08/13 13:50:51 by cmero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstfindmin_val(t_list *lst)
{
	int	min_value;

	min_value = (int)lst->content;
	while (lst)
	{
		if (min_value > (int)lst->content)
			min_value = (int)lst->content;
		lst = lst->next;
	}
	return (min_value);
}
