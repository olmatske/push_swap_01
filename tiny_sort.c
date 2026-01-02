/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 11:11:56 by olmatske          #+#    #+#             */
/*   Updated: 2026/01/02 17:26:16 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	three_sort(t_node **a, t_node **b)
{
	t_node	*x;
	t_node	*y;
	t_node	*z;

	x = *a;
	y = x->next;
	z = y->next;
	if (x->index > y->index && y->index < z->index && x->index < z->index)
		wrapper(a, b, 's', 'a');
	if (x->index > y->index && y->index > z->index)
	{
		wrapper(a, b, 's', 'a');
		wrapper_rotate(a, b, 'r', 'a');
	}
	else if (x->index > y->index && y->index < z->index && x->index > z->index)
		wrapper_rotate(a, b, 'R', 'a');
	else if (x->index < y->index && y->index > z->index && x->index < z->index)
	{
		wrapper(a, b, 's', 'a');
		wrapper_rotate(a, b, 'R', 'a');
	}
	else if (x->index < y->index && y->index > z->index && x->index > z->index)
		wrapper_rotate(a, b, 'r', 'a');
}

int	pos_index(t_node *a, int target)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->index == target)
			return (i);
		a = a->next;
		i++;
	}
	return (-1);
}

void	bring_to_top(t_node **a, t_node **b, int idx, int len)
{
	int	pos;

	pos = pos_index(*a, idx);
	if (pos <= len / 2)
		while (pos-- > 0)
			wrapper_rotate(a, b, 'R', 'a');
	else
		while (len - pos++ > 0)
			wrapper_rotate(a, b, 'r', 'a');
}

void	five_sort(t_node **a, t_node **b)
{
	int	len;

	len = stack_len(*a);
	bring_to_top(a, b, 0, len);
	wrapper(a, b, 'p', 'b');
	len--;
	bring_to_top(a, b, 1, len);
	wrapper(a, b, 'p', 'b');
	len--;
	three_sort(a, b);
	if ((*b)->index < (*b)->next->index)
		wrapper(a, b, 's', 'b');
	wrapper(a, b, 'p', 'a');
	wrapper(a, b, 'p', 'a');
}
