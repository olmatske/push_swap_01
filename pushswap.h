/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:10:48 by olmatske          #+#    #+#             */
/*   Updated: 2025/12/20 12:13:44 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include "./lib/ft_printf/ft_printf.h"


typedef struct s_node {
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
} t_node;


////////////// main.c ////////////////////
int 	main(int argc, char **argv);

////////////// validate.c ////////////////
int		input_check(char **tokens);
long	ft_atol(const char *str);
int		no_dupes(char **tokens);

////////////// stack.c //////////////////////////////////////////////
t_node	*stack_init(t_node *stack, char **tokens);
t_node	*add_node(t_node *stack, char **tokens, long stack_index);
void	list_stack_A(t_node *stack_A);
void	list_stack_B(t_node *stack_B);
int		stack_len(t_node *stack);

////////////// swap_push_rotate.c ///////////////////////////////////
void	swap(t_node **stack);
void	push(t_node **pushed, t_node **dest, char flag);
void	rotate_up(t_node **stack);
void	rotate_down(t_node **stack);

////////////// wrapper.c //////////////////////////////////////////////
void	wrapper(t_node **stack_A, t_node **stack_B, char operation, char flag);
void	wrapper_rotate(t_node **stack_A, t_node **stack_B, char operation, char flag);

////////////// index_sort.c //////////////////////////////////////////////
void	i_sort(t_node *stack);
int	find_smallest(t_node *stack);
void	list_index(t_node *stack);

////////////// tiny_sort.c //////////////////////////////////////////////
void	three_sort(t_node **a, t_node **b);
int		pos_index(t_node *a, int target);
void	bring_to_top(t_node **a, t_node **b, int idx, int len);
void	five_sort(t_node **a, t_node **b);


#endif

// k sort