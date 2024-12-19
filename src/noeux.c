/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noeux.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:33:06 by cle-berr          #+#    #+#             */
/*   Updated: 2024/11/25 14:40:50 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

void	append_node(t_node **stack, t_node *new_node)
{
	t_node	*temp;

	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new_node;
}

int	parse_and_add(char *arg, t_node **stack)
{
	char	**numbers;
	int		value;
	t_node	*new_node;
	int		i;

	numbers = ft_split(arg, ' ');
	if (!numbers)
		return (0);
	i = 0;
	while (numbers[i])
	{
		if (!is_number(numbers[i]))
			return (add_error(stack, numbers));
		value = ft_atoi(numbers[i]);
		if (!has_duplicate(*stack, value))
			return (add_error(stack, numbers));
		new_node = create_node(value);
		if (!new_node)
			return (add_error(stack, numbers));
		append_node(stack, new_node);
		i++;
	}
	ft_free_split(numbers);
	return (1);
}

t_node	*parse_arguments(int argc, char **argv)
{
	t_node	*stack;
	int		i;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		if (!parse_and_add(argv[i], &stack))
			return (NULL);
		i++;
	}
	return (stack);
}

int	node(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc < 2)
		return (error());
	stack_a = parse_arguments(argc, argv);
	if (!stack_a)
		return (1);
	stack_b = NULL;
	controller(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
