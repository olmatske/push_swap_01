/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:09 by olmatske          #+#    #+#             */
/*   Updated: 2025/12/10 14:05:09 by olmatske         ###   ########.fr       */
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
	char	**tokens; // char even though tokens are numbers????
	long	i;

	i = 0;
	stack_A = NULL;
	stack_B = NULL;
	if (argc != 2 || !argv[1][0])
		return (ft_printf("Invalid input - Please parse a string of numbers\n\n"), 1);
	tokens = ft_split(argv[1], ' ');
	if (!tokens)
		return (ft_printf("Allocation error\n\n"));
	if (input_check(tokens) != 0)
		return (free(tokens), ft_printf("Hurensohn Invalid Input\n\n"), 1);
	ft_printf("Successful Input\n\n");
	while (tokens[i])
		ft_printf("%s\n", tokens[i++]);
	stack_init(stack_A, tokens, i);
	return 0;
}

	// stack_init(&stack_A, tokens); ///////////// previously: stack_init /////////////////
	// if (!stack_sorted(stack_A))
	// {
	// 	if (stack_len(stack_A) == 2)
	// 		sa(&stack_A);
	// 	else if (stack_len(stack_A) == 3)
	// 		three_sort(&stack_A);
	// 	else
	// 		push_swap(&stack_A, &stack_B);
	// }
	// free_stack(&stack_A);

