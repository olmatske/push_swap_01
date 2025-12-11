/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:10:48 by olmatske          #+#    #+#             */
/*   Updated: 2025/12/10 14:16:07 by olmatske         ###   ########.fr       */
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
	int			lis_flag;
	struct s_node	*prev;
	struct s_node	*next;
} t_node;

int 	main(int argc, char **argv);
int		input_check(char **tokens);
long	ft_atol(const char *str);
void	stack_init(t_node *stack, char **tokens, long len);
t_node	*add_node(t_node *stack, char **tokens, long len);



#endif

// k sort