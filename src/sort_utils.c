/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:24:24 by cle-berr          #+#    #+#             */
/*   Updated: 2024/12/16 12:50:24 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_3(t_node **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

static int	find_position_in_b(t_node **stack_b, int nb)
{
	t_node	*current;
	int		pos;

	current = *stack_b;
	pos = 0;
	while (current)
	{
		if (current->value > nb)
			break ;
		pos++;
		current = current->next;
	}
	return (pos);
}

static int	calculate_cost(int pos_a, int pos_b, int size_a, int size_b)
{
	int	cost_a;
	int	cost_b;

	cost_a = pos_a;
	if (pos_a > size_a / 2)
		cost_a = size_a - pos_a;
	cost_b = pos_b;
	if (pos_b > size_b / 2)
		cost_b = size_b - pos_b;
	return (cost_a + cost_b);
}

int	find_the_cheapest(t_node **stack_a, t_node **stack_b)
{
	t_node	*current;
	int		best_value;
	int		pos_a;
	int		min_cost;
	int		cost;

	current = *stack_a;
	best_value = current->value;
	pos_a = 0;
	min_cost = 2147483647;
	while (current)
	{
		cost = calculate_cost(pos_a,
				find_position_in_b(stack_b, current->value),
				stack_size(*stack_a), stack_size(*stack_b));
		if (cost < min_cost)
		{
			min_cost = cost;
			best_value = current->value;
		}
		current = current->next;
		pos_a++;
	}
	return (best_value);
}

t_node	*get_last(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
