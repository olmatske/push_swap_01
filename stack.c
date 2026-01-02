/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 20:40:23 by olmatske          #+#    #+#             */
/*   Updated: 2026/01/02 17:22:29 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_node	*stack_init(t_node *stack, char **tokens, int flag)
{
	long	stack_index;
	long	len;

	stack_index = 0;
	len = 0;
	while (tokens[len])
		len++;
	while (stack_index < len)
	{
		stack = add_node(stack, tokens, stack_index);
		stack_index++;
	}
	if (flag == 1)
		free_char_array(tokens);
	return (stack);
}

t_node	*add_node(t_node *stack, char **tokens, long stack_index)
{
	t_node	*new_node;
	t_node	*tail;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (stack);
	new_node->index = -1;
	new_node->value = ft_atol(tokens[stack_index]);
	new_node->next = NULL;
	new_node->prev = NULL;
	if (!stack)
		return (new_node);
	tail = stack;
	while (tail->next)
		tail = tail->next;
	tail->next = new_node;
	new_node->prev = tail;
	return (stack);
}

void	list_stack_a(t_node *stack_A)
{
	t_node	*curr;

	curr = stack_A;
	ft_printf("This is stack A: ");
	while (curr != NULL)
	{
		ft_printf("%d", curr->value);
		if (curr->next != NULL)
			ft_printf(" -> ");
		curr = curr->next;
	}
	ft_printf("\n");
}

// void	list_stack_B(t_node *stack_B)
// {
// 	t_node	*curr;

// 	curr = stack_B;
// 	ft_printf("This is stack B: ");
// 	while (curr != NULL)
// 	{
// 		ft_printf("%d", curr->value);
// 		if (curr->next != NULL)
// 			ft_printf(" -> ");
// 		curr = curr->next;
// 	}
// 	ft_printf("\n");
// }