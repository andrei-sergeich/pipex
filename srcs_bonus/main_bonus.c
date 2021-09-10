/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmero <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 22:30:21 by cmero             #+#    #+#             */
/*   Updated: 2021/09/09 22:30:21 by cmero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	main(int argc, char *argv[], char*envp[])
{
	if (argc < 5)
		ft_error("Error: wrong count of arguments");
	pipex(argc, argv, envp);
	return (0);
}
