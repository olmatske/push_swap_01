/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 20:40:23 by olmatske          #+#    #+#             */
/*   Updated: 2025/12/10 20:08:13 by olmatske         ###   ########.fr       */
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
	


	printf("This is the amount of tokens we have: %ld\n", len);
	// stack = add_node(stack, )
}

t_node	*add_node(t_node *stack, char **tokens, long len)
{
	int	i;
	t_node	*curr;
	t_node	*new_node;
	t_node	*prev;

	curr = NULL;
	prev = NULL;

	stack = malloc(sizeof(t_node));

	i = 0;
	while (i < len)
	{
		new_node = malloc(sizeof(t_node));
		new_node->value = ft_atol(tokens[i]);
		new_node->index = i;
		new_node->lis_flag = ft_lis(tokens[i]);   /////////// need to decide on lis stuff ////////
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = new_node;
		new_node->next = NULL;
		i++;
	}
	return (stack);
}

void	list_stack(t_node *stack)
{
	t_node	*curr;
	int		i;

	while (curr != NULL)
	{
		ft_printf("%d", curr->value);
		if (curr->next != NULL)
			ft_printf(" -> ");
		curr = curr->next;
	}
	ft_printf("\n");
}