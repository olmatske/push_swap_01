/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:25:37 by olmatske          #+#    #+#             */
/*   Updated: 2025/12/12 13:21:03 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(t_node **stack)
{
	// ft_printf("Flag swap.c\n\n");
	t_node	*first;
	t_node	*second;
	t_node	*tmp;

	if (!stack || !(*stack) || !(*stack)->next)   //// is head NULL || is the list empty/first node missing || head has no second node ////
		return;
	first = *stack;
	second = first->next;
	tmp = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = tmp;
	if (tmp)
		tmp->prev = first;
	*stack = second;
}
// void	push(t_node **stack_A, t_node **stack_B, char flag)
// {
	
// }

void	wrapper_swap(t_node **stack_A, t_node **stack_B, char flag)
{
	ft_printf("Operations:\n\n");
	if (flag == 'a')
	{
		swap(stack_A);
		ft_printf("sa\n");
	}
	else if (flag == 'b')
	{
		swap(stack_B);
		ft_printf("sb\n");
	}
	else if (flag == 's')
	{
		swap(stack_A);
		swap(stack_B);
		ft_printf("ss\n");
	}
}