/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:58:35 by cle-berr          #+#    #+#             */
/*   Updated: 2024/12/13 11:17:33 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	error(void)
{
	ft_printf("Error\n");
	exit(1);
}

int	main(int argc, char **argv)
{
	node(argc, argv);
	return (0);
}
