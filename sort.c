/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:15:22 by olmatske          #+#    #+#             */
/*   Updated: 2025/12/21 20:23:37 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	max_bit(t_node **stack)
{
	int	max_bit;
	int	max_num;

	max_bit = 0;
	max_num = stack_len(*stack);
	while ((max_num >> max_bit))
		max_bit++;
	// printf("\nCHECKPOINT max bits\n");
	return (max_bit);
}

int	is_sorted(t_node **a)
{
	if (stack_len(*a) == 1)
		return 0;
	while (*a && (*a)->next)
	{
		if ((*a)->index > (*a)->next->index)
			return (1);
		(*a) = (*a)->next;
	}
	// printf("\nCHECKPOINT is sorted\n");
	return (0);
}

void	sort_it(t_node **a, t_node **b, int len)
{
	i_sort(*a);
	if (len == 3)
		three_sort(a, b);
	else if (len == 5)
		five_sort(a, b);
	else
		radix(a, b);
	// printf("\nCHECKPOINT sort it\n");
}

void	radix(t_node **a, t_node **b)
{
	int	i;
	int	stack_iterator;
	int	len;
	int	bit;

	i = 0;
	stack_iterator = 0;
	len = stack_len(*a);
	bit = max_bit(a);
	// printf("\nCHECKPOINT radix 1 \n");
	while(i < bit)
	{
		if (is_sorted(a) == 0)
			return;
		stack_iterator = 0;
		while (stack_iterator < len && *a)
		{
			if ((*a)->index >> i & 1)
				wrapper_rotate(a, b, 'R', 'a');
			else
				wrapper(a, b, 'p', 'b');
			stack_iterator++;
		}
		while(*b)
			wrapper(a, b, 'p', 'a');
		i++;
	}
	// printf("\nCHECKPOINT radix 2 \n");
}