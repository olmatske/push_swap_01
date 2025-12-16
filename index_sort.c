/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:49:15 by olmatske          #+#    #+#             */
/*   Updated: 2025/12/16 17:12:47 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void test_func(t_node *finder)
{
	while(finder)
	{
		ft_printf("value: %d\n", finder->value);
		ft_printf("index %d\n", finder->index);
		finder = finder->next;
	}
}

void	i_sort(t_node *stack)
{
	int		i;
	int		smallest;
	t_node	*finder;

	i = 0;
	smallest = stack->value;
	smallest = find_smallest(stack, smallest);
	finder = stack;
	while (finder)
	{
		smallest = find_smallest(stack, smallest);
		while (finder && finder->index >= finder->next->index) // until the value is the same as smallest and stack exists
		{
			if (finder->value == smallest)
			{
				finder->index = i;
				i++;
				break;
			}
			finder = finder->next;
		}
		if (i == stack_len(stack))
			break;
		finder = stack;
	}
	test_func(finder);
}

int	find_smallest(t_node *stack, int smallest)
{
	t_node	*finder;

	finder = stack;
	while (finder)
	{
		while (finder->index != -1 && finder->value > smallest)
			finder = finder->next;
		smallest = finder->value;
		break;
	}
	return (smallest);
}

t_node	*iterator(t_node *stack, int smallest)
{
	
}



	