/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfindmax_val.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:50:48 by cmero             #+#    #+#             */
/*   Updated: 2021/08/13 13:50:49 by cmero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstfindmax_val(t_list *lst)
{
	int	max_value;

	max_value = (int)lst->content;
	while (lst)
	{
		if (max_value < (int)lst->content)
			max_value = (int)lst->content;
		lst = lst->next;
	}
	return (max_value);
}
