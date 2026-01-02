/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:25:37 by olmatske          #+#    #+#             */
/*   Updated: 2026/01/02 17:23:56 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*tmp;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
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

void	push(t_node **from, t_node **to, char flag)
{
	t_node	*tmp;

	if (!from || !(*from))
		return ;
	tmp = *from;
	*from = tmp->next;
	if (*from)
		(*from)->prev = NULL;
	tmp->prev = NULL;
	tmp->next = *to;
	if (*to)
		(*to)->prev = tmp;
	*to = tmp;
	if (flag == 'a')
		ft_printf("pa\n");
	else if (flag == 'b')
		ft_printf("pb\n");
	else
		return ;
}

void	rotate_up(t_node **stack)
{
	t_node	*runner;
	t_node	*first;
	t_node	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	runner = *stack;
	first = runner->next;
	last = *stack;
	while (last->next)
		last = last->next;
	runner->prev = last;
	runner->next = NULL;
	first->prev = NULL;
	last->next = runner;
	*stack = first;
}

void	rotate_down(t_node **stack)
{
	t_node	*runner;
	t_node	*first;
	t_node	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	runner = *stack;
	while (runner->next)
		runner = runner->next;
	last = runner->prev;
	last->next = NULL;
	first->prev = runner;
	runner->prev = NULL;
	runner->next = first;
	*stack = runner;
}
