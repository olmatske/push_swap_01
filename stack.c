/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 20:40:23 by olmatske          #+#    #+#             */
/*   Updated: 2025/12/09 16:58:40 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// stack_init
// search_stack (validate?)
// stack_sorted
// stack_len
// free_stack

#include "pushswap.h"

void	stack_init(t_node *stack, char **tokens, long len)
{

	// stack = malloc(sizeof(t_node));
	if (len >= 1)
		stack->value = tokens[0];
	else
		stack->next = 0;       ///////// wtf is that //////////
	stack->next = NULL;
}

void	add_node(t_node stack, char **tokens, long len)
{
	int	i;
	t_node	*curr;
	t_node	*new_node;

	i = 0;
	while (i < len)
	{
		new_node = malloc(sizeof(t_node));
		new_node->value = ft_atol(tokens[i]);
		new_node->index = i;
		new_node->lis_flag = ft_lis(tokens[i]);   /////////// need to decide on lis stuff ////////
		while (curr->next != NULL)
			curr = curr->next;
		while ()
	}


}
