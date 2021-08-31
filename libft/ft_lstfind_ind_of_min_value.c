/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind_ind_of_min_value.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:50:45 by cmero             #+#    #+#             */
/*   Updated: 2021/08/13 13:50:46 by cmero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstfind_ind_of_min_value(t_list *lst)
{
	int	min_value;
	int	min_ind;
	int	it;

	min_ind = 0;
	min_value = (int)lst->content;
	lst = lst->next;
	it = 1;
	while (lst)
	{
		if ((int)lst->content < min_value)
		{
			min_ind = it;
			min_value = (int)lst->content;
		}
		lst = lst->next;
		it++;
	}
	return (min_ind);
}
