/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:33:31 by cle-berr          #+#    #+#             */
/*   Updated: 2024/12/13 13:32:19 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int *extract_values(t_node *stack, int size)
{
	int *values;
	int i;

	values = (int *)malloc(sizeof(int) * size);
	if (!values)
		return (NULL);
	i = 0;
	while (stack && i < size)
	{
		values[i++] = stack->value;
		stack = stack->next;
	}
	return (values);
}

int	find_median_chunk(t_node *stack, int chunk_size)
{
	int *values;
	int size;
	int median;
	int i, j, temp;

	if (!stack || chunk_size <= 0)
		return (0);
	size = stack_size(stack);
	if (chunk_size > size)
		chunk_size = size;
	values = extract_values(stack, chunk_size);
	if (!values)
		return (0);
	i = 0;
	while (i < chunk_size - 1)
	{
		j = 0;
		while (j < chunk_size - i - 1)
		{
			if (values[j] > values[j + 1])
			{
				temp = values[j];
				values[j] = values[j + 1];
				values[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	median = values[chunk_size / 2];
	free(values);
	return (median);
}
