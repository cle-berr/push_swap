/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_center.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:03:24 by cle-berr          #+#    #+#             */
/*   Updated: 2024/12/16 14:37:25 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	sort_small_stack(t_node **a)
{
	if (stack_size(*a) == 2 && (*a)->value > (*a)->next->value)
		sa(a);
	else if (stack_size(*a) == 3)
	{
		sort_3(a);
	}
}
int	no_values_below_pivot(t_node *stack, int pivot)
{
	while (stack)
	{
		if (stack->value <= pivot)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	push_chunks_to_b(t_node **a, t_node **b, int chunk_size)
{
	int	pivot;
	int	i;

	while (stack_size(*a) > 0)
	{
		pivot = find_median_chunk(*a, chunk_size);
		i = 0;
		while (i < stack_size(*a))
		{
			if (is_sorted(*a, 1))
				return ;
			if ((*a)->value <= pivot)
			{
				pb(a, b);
				if ((*b)->value > pivot / 2)
					rb(b);
			}
			else
				ra(a);
			i++;
		}
	}
}

static void	push_back_to_a(t_node **a, t_node **b)
{
	int	cheapest;
	int	closest;

	while (*b)
	{
		cheapest = find_the_cheapest(b, a);
		value_on_top_b(b, cheapest);
		closest = find_closest_upper(a, b);
		if (!can_push(a, closest))
			value_on_top(a, closest);
		pa(a, b);
	}
	if (!is_sorted(*a, 1))
		value_on_top(a, find_min(*a));
}


void	sort_stack_turk(t_node **a, t_node **b)
{
	int	chunk_size;

	chunk_size = stack_size(*a) / 3;
	push_chunks_to_b(a, b, chunk_size);
	push_back_to_a(a, b);
}

void	controller(t_node **a, t_node **b)
{
	if (is_sorted(*a, 1))
		return ;
	if (stack_size(*a) <= 3)
	{
		sort_small_stack(a);
		return ;
	}
	sort_stack_turk(a, b);
}
