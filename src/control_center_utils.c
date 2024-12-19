/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_center_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:15:46 by cle-berr          #+#    #+#             */
/*   Updated: 2024/11/25 14:40:25 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stack_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	is_sorted(t_node *stack, int ascending)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (ascending && stack->value > stack->next->value)
			return (0);
		if (!ascending && stack->value < stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	find_max(t_node *stack)
{
	int	max;

	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

int	find_min(t_node *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int	get_index(t_node *stack, int value)
{
	int	index;

	index = 0;
	while (stack)
	{
		if (stack->value == value)
			return (index);
		index++;
		stack = stack->next;
	}
	return (-1);
}
