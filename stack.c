/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 20:40:23 by olmatske          #+#    #+#             */
/*   Updated: 2025/12/17 16:12:39 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// stack_init
// search_stack (validate?)
// stack_sorted
// stack_len
// free_stack

// need to reassign the stack indexes when changing the stack!! or something like that idk

#include "pushswap.h"

int	stack_len(t_node *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

t_node	*stack_init(t_node *stack, char **tokens)
{
	long	stack_index;
	long	len;

	stack_index = 0;
	len = 0;
	while (tokens[len])
		ft_printf("%s ", tokens[len++]);
	while (stack_index < len)
	{
		stack = add_node(stack, tokens, stack_index);
		stack_index++;
	}
	printf("\nThis is the amount of tokens we have: %ld\n", len);
	// list_stack(stack);
	return (stack);
}

t_node	*add_node(t_node *stack, char **tokens, long stack_index)
{
	t_node	*new_node;
	t_node	*tail;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (ft_printf("Allocation failed while allocating new node.\n"), stack);
	new_node->index = -1;
	new_node->value = ft_atol(tokens[stack_index]);
	// new_node->lis_flag = test;
	new_node->next = NULL;
	new_node->prev = NULL; 
	if (!stack)
		return (new_node);         /////////// I don't even know if this is neccessary ///////////
	tail = stack;
	while (tail->next)            //////////// loop to find the actual tail ////////////
		tail = tail->next;
	tail->next = new_node;
	new_node->prev = tail;
	return (stack);
}

void	list_stack_A(t_node *stack_A)
{
	t_node	*curr;

	curr = stack_A;
	ft_printf("This is stack: ");
	while (curr != NULL)
	{
		ft_printf("%d", curr->value);
		if (curr->next != NULL)
			ft_printf(" -> ");
		curr = curr->next;
	}
	ft_printf("\n");
	list_index(stack_A);
}
void	list_stack_B(t_node *stack_B)
{
	t_node	*curr;

	curr = stack_B;
	ft_printf("This is stack B:\n");
	while (curr != NULL)
	{
		ft_printf("%d", curr->value);
		if (curr->next != NULL)
			ft_printf(" -> ");
		curr = curr->next;
	}
	ft_printf("\n");
}