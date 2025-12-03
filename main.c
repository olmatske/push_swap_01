/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:09 by olmatske          #+#    #+#             */
/*   Updated: 2025/12/03 19:04:30 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// only accept strings

// validate_stack/input
// three_sort
// 
// stack_init
// search_stack (validate?)
// stack_sorted
// stack_len
// free_stack


int main(int argc, char **argv)
{
	t_node *stack_A;
	t_node *stack_B;
	char	**tokens;
	long	num;

	stack_A = NULL;
	stack_B = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		tokens = ft_split(argv[1], ' ');
	if (iput_check(tokens) != 0)
		return (ft_ptintf("Invalid Input"), 1);
	stack_init(&stack_A, ft_strlen(tokens) + 1);
	if (!stack_sorted(stack_A))
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



