/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 20:40:23 by olmatske          #+#    #+#             */
/*   Updated: 2025/12/03 19:15:27 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// stack_init
// search_stack (validate?)
// stack_sorted
// stack_len
// free_stack

#include "pushswap.h"

void	stack_init(t_node stack, long num)
{
	
}

void	add_node(t_node stack, long num, struct node *prev)
{
	t_node *curr;

	curr = malloc(sizeof(t_node));
	if (!curr)
		return (NULL);
	curr->
}
