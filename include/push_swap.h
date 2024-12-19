/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-berr <cle-berr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:17:33 by cle-berr          #+#    #+#             */
/*   Updated: 2024/12/16 13:18:25 by cle-berr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "../libft-main/libft.h"
# include "../libft-main/ft_printf.h"

/*-------------structure-------------*/
typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

/*---------------Error---------------*/
int		error(void);
int		add_error(t_node **stack, char **numbers);

/*---------------Free----------------*/
void	free_stack(t_node **stack);
void	ft_free_split(char **split);

/*---------------Utils---------------*/
int		is_number(char *str);
int		has_duplicate(t_node *stack, int value);
int		is_sorted(t_node *stack, int ascending);
int		stack_size(t_node *stack);
int		find_max(t_node *stack);
int		find_min(t_node *stack);
int		get_index(t_node *stack, int value);
void	sort_3(t_node **a);

/*---------------Chunks--------------*/
int		find_median_chunk(t_node *stack, int chunk_size);

/*---------------Noeux---------------*/
int		node(int argc, char **argv);

/*-------------Controler-------------*/
void	controller(t_node **a, t_node **b);
int		find_the_cheapest(t_node **stack_a, t_node **stack_b);

/*----------------sort---------------*/
void	value_on_top_b(t_node **b, int value);
int		can_push(t_node **stack_a, int value);
void	value_on_top(t_node **a, int value);
int		find_closest_upper(t_node **stack_a, t_node **stack_b);
int		get_steps_to_value(t_node **b, int nb);

/*------------Instruction------------*/
void	pb(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	sa(t_node **a);
void	sb(t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);

#endif
