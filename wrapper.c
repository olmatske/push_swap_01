/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:51:07 by olmatske          #+#    #+#             */
/*   Updated: 2025/12/21 21:11:15 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//////     R = rotate up   ///   r = rotate down    //////
void	wrapper_rotate(t_node **stack_A, t_node **stack_B, char operation, char flag)
{
	if (operation == 'R' && flag == 'a')
		rotate_up(stack_A);
	else if (operation == 'R' && flag == 'b')
		rotate_up(stack_B);
	else if (operation == 'R' && flag == 'r')
	{
		rotate_up(stack_A);
		rotate_up(stack_B);
	}
	else if (operation == 'r' && flag == 'a')
		rotate_down(stack_A);
	else if (operation == 'r' && flag == 'b')
		rotate_down(stack_B);
	else if (operation == 'r' && flag == 'r')
	{
		rotate_down(stack_A);
		rotate_down(stack_B);
	}
	if (operation == 'R')
		ft_printf("r%c\n", flag);                   //////// FIX THIS SHIT ////////
	if (operation == 'r')
		ft_printf("rr%c\n", flag);
}

void	wrapper(t_node **stack_A, t_node **stack_B, char operation, char flag)
{
	if (operation == 'R' || operation == 'r')
		wrapper_rotate(stack_A, stack_B, operation, flag);
	else if (operation == 's' && flag == 'a')
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
	else
	printf("%c%c\n", operation, flag);                   //////// FIX THIS SHIT ////////
}


