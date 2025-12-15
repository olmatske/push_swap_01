/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:25:37 by olmatske          #+#    #+#             */
/*   Updated: 2025/12/15 09:24:46 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*tmp;

	if (!stack || !(*stack) || !(*stack)->next)   //// is head NULL || is the list empty/first node missing || head has no second node ////
	{
		ft_printf("Bruh\n");
		exit(1);
	}
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

////////// needs a wrapper to determine pushed and dest!! //////////
void	push(t_node **pushed, t_node **dest, char flag)
{
	t_node	*tmp;

	if (!pushed || !(*pushed))
	{
		ft_printf("Bruh\n");
		exit(1);
	}
	tmp = *pushed;
	*pushed = tmp->next;
	if (*pushed)
		(*pushed)->prev = NULL;
	tmp->prev = NULL;
	tmp->next = *dest;
	if (*dest)
		(*dest)->prev = tmp;
	*dest = tmp;
	if (flag == 'a')
		ft_printf("pa\n");
	else if (flag == 'b')
		ft_printf("pb\n");
	else
		ft_printf("How did you manage to fuck this up????\n");
}

void	rotate_up(t_node **stack)
{
	t_node	*runner;
	t_node	*first;
	t_node	*last;

	if (!stack || !(*stack) || !(*stack)->next)   //// is head NULL || is the list empty/first node missing || head has no second node ////
	{
		ft_printf("Bruh\n");
		exit(1);
	}
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

	if (!stack || !(*stack) || !(*stack)->next)   //// is head NULL || is the list empty/first node missing || head has no second node ////
	{
		ft_printf("Bruh\n");
		exit(1);
	}
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

void	wrapper_swap(t_node **stack_A, t_node **stack_B, char operation, char flag)
{
	ft_printf("Operations:\n\n");
	if (operation == 's' && flag == 'a')
		swap(stack_A);
	else if (operation == 's' && flag == 'b')
		swap(stack_B);
	else if (operation == 's' && flag == 's')
	{
		swap(stack_A);
		swap(stack_B);
	}
	else if (operation == 'p' && flag == 'a')
		push(stack_B, stack_A, 'a');
	else if (operation == 'p' && flag == 'b')
		push(stack_A, stack_B, 'b');
	printf("%c%c\n", operation, flag);                   //////// FIX THIS SHIT ////////
	if (operation == 'R' && flag == 'a')
		rotate_up(stack_A);
	if (operation == 'R' && flag == 'b')
		rotate_up(stack_B);
	if (operation == 'R' && flag == 'r')
	{
		rotate_up(stack_A);
		rotate_up(stack_B);
	}
}


