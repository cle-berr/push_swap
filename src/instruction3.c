/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:26:10 by cle-berr          #+#    #+#             */
/*   Updated: 2024/12/13 13:34:45 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_node **a)
{
	t_node	*prev;
	t_node	*tail;

	if (!*a || !(*a)->next)
		return ;
	prev = NULL;
	tail = *a;
	while (tail->next)
	{
		prev = tail;
		tail = tail->next;
	}
	tail->next = *a;
	*a = tail;
	prev->next = NULL;
	ft_printf("rra\n");
}

void	rrb(t_node **b)
{
	t_node	*prev;
	t_node	*tail;

	if (!*b || !(*b)->next)
		return ;
	prev = NULL;
	tail = *b;
	while (tail->next)
	{
		prev = tail;
		tail = tail->next;
	}
	tail->next = *b;
	*b = tail;
	prev->next = NULL;
	ft_printf("rrb\n");
}
