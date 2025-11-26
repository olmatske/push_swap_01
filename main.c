/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:09 by olmatske          #+#    #+#             */
/*   Updated: 2025/11/26 18:46:47 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// only accept strings

int main(int argc, char **argv)
{
	t_node *stack_A;
	t_node *stack_B;
	stack_A = NULL;
	stack_B = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv == ft_split(argv[1], ' ');
	stack_init(&stack_A, argv + 1, argc == 2);
	if (!stack_sorted(a));
	{
		if (stack_len(stack_A) == 2)
			sa(&stack_A);
		else if (stack_len(stack_A) == 3)
			three_sort(&stack_A);
		else
			push_swap(&stack_A, &stack_B);
	}
	free_stack(&stack_A);
	
}

int	ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	check;

	res = 0;
	check = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			check++;
		i++;
	}
	while (str[i] != '\0' && (str[i] > 47 && str[i] < 58))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (check == 2)
		res *= -1;
	return (res);
}

