/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 12:46:36 by cle-berr          #+#    #+#             */
/*   Updated: 2024/12/16 12:49:12 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	value_on_top(t_node **a, int value)
{
	int	size;
	int	steps;

	steps = 0;
	size = stack_size(*a);
	steps = get_steps_to_value(a, value);
	if (steps <= size / 2)
	{
		while (steps--)
			ra(a);
	}
	else
	{
		while (steps++ < size)
			rra(a);
	}
}

void	value_on_top_b(t_node **b, int value)
{
	int	size;
	int	steps;

	steps = 0;
	size = stack_size(*b);
	steps = get_steps_to_value(b, value);
	if (steps <= size / 2)
	{
		while (steps--)
			rb(b);
	}
	else
	{
		while (steps++ < size)
			rrb(b);
	}
}

int	find_closest_upper(t_node **stack_a, t_node **stack_b)
{
	int		first;
	t_node	*current;
	int		closest_upper;

	first = (*stack_b)->value;
	current = *stack_a;
	closest_upper = INT_MAX;
	while (current)
	{
		if (current->value > first && current->value < closest_upper)
			closest_upper = current->value;
		current = current->next;
	}
	if (closest_upper == INT_MAX)
		return (find_min(*stack_a));
	return (closest_upper);
}

int	can_push(t_node **stack_a, int value)
{
	if (value == (*stack_a)->value)
		return (1);
	return (0);
}

int	get_steps_to_value(t_node **b, int nb)
{
	t_node	*b_temp;
	int		count;

	if (!b || !*b)
		return (0);
	b_temp = *b;
	count = 0;
	while (b_temp)
	{
		if (b_temp->value == nb)
			break ;
		count++;
		b_temp = b_temp->next;
	}
	return (count);
}