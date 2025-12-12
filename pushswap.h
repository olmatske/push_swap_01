/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:10:48 by olmatske          #+#    #+#             */
/*   Updated: 2025/12/12 13:12:27 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include "./lib/ft_printf/ft_printf.h"


typedef struct s_node {

	int			index;
	int			value;
	// int			lis_flag;
	struct s_node	*prev;
	struct s_node	*next;
} t_node;


////////////// main.c ////////////////////
int 	main(int argc, char **argv);

////////////// validate.c ////////////////
int		input_check(char **tokens);
long	ft_atol(const char *str);

////////////// stack.c //////////////////////////////////////////////
t_node	*stack_init(t_node *stack, char **tokens);
t_node	*add_node(t_node *stack, char **tokens, long stack_index);
void	list_stack(t_node *stack);

////////////// swap_push_rotate.c ///////////////////////////////////
void	swap(t_node **stack);
void	wrapper_swap(t_node **stack_A, t_node **stack_B, char flag);



#endif

// k sort