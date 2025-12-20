/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:49:15 by olmatske          #+#    #+#             */
/*   Updated: 2025/12/20 11:24:21 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void test_func(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	while(tmp)
	{
		ft_printf("value: %d\n", tmp->value);
		ft_printf("index %d\n", tmp->index);
		tmp = tmp->next;
	}
}
void	list_index(t_node *stack)
{
	t_node	*curr;

	curr = stack;
	ft_printf("This is index: ");
	while (curr != NULL)
	{
		ft_printf("%d", curr->index);
		if (curr->next != NULL)
			ft_printf(" -> ");
		curr = curr->next;
	}
	ft_printf("\n");
}

void	i_sort(t_node *stack)
{
	int		i;
	int		n;
	int		smallest;
	t_node	*finder;

	if (!stack)
		return;
	i = 0;
	n = stack_len(stack);
	smallest = find_smallest(stack);
	finder = stack;
	while (i < n)
	{
		smallest = find_smallest(stack);
		finder = stack;
		while (finder) // until the value is the same as smallest and stack exists
		{
			if (finder->index == -1 && finder->value == smallest)
			{
				finder->index = i;
				i++;
				break;
			}
			finder = finder->next;
		}
	}
	// test_func(stack);
}

int	find_smallest(t_node *stack)
{
	int		smallest;
	int		flag;
	t_node	*finder;

	smallest = 0;
	flag = 1;
	finder = stack;
	while (finder)
	{
		if (finder->index == -1)
		{
			if (flag || finder->value < smallest)
			{
				smallest = finder->value;
				flag = 0;
			}
		}
		finder = finder->next;
		// while (finder->index == -1 && finder->value > smallest)
		// smallest = finder->value;
		// break;
	}
	return (smallest);
}
