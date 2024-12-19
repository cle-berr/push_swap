/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:26:00 by cle-berr          #+#    #+#             */
/*   Updated: 2024/12/13 13:35:23 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_node **a)
{
	t_node	*temp;
	t_node	*tail;

	if (!*a || !(*a)->next)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = NULL;
	tail = *a;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = temp;
	ft_printf("ra\n");
}

void	rb(t_node **b)
{
	t_node	*temp;
	t_node	*tail;

	if (!*b || !(*b)->next)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = NULL;
	tail = *b;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = temp;
	ft_printf("rb\n");
}
