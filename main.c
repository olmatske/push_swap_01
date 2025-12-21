/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:09 by olmatske          #+#    #+#             */
/*   Updated: 2025/12/21 19:14:43 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int argc, char **argv)
{
	t_node *stack_A;
	t_node *stack_B;
	char	**tokens;
	long	i;

	i = 0;
	stack_A = NULL;
	stack_B = NULL;
	if (argc != 2 || !argv[1][0] || argv[1][0] == ' ')
		return (ft_printf("Invalid input - Parse a string of numbers\n"), 1);
	tokens = ft_split(argv[1], ' ');
	if (!tokens)
		return (ft_printf("Tokenization error\n\n"));
	if (input_check(tokens) != 0 || no_dupes(tokens) != 0)
		return (free(tokens), ft_printf("Invalid Input\n\n"), 1);
	ft_printf("Successful Input\n\n");
	stack_A = stack_init(stack_A, tokens);

	// i_sort(stack_A);
	sort_it(&stack_A, &stack_B, stack_len(stack_A));
	list_stack_A(stack_A);


	// ft_printf("Before sort:\n");
	// ft_printf("After sort:\n");
	// if (stack_len(stack_A) == 3)
	// 	three_sort(&stack_A, &stack_B);
	// list_stack_A(stack_A);
	
	// ft_printf("Operations:\n\n");
	// wrapper(&stack_A, &stack_B, 'p', 'b');
	// wrapper(&stack_A, &stack_B, 'p', 'b');
	// wrapper_rotate(&stack_A, &stack_B, 'r', 'r');
	list_stack_B(stack_B);
	is_sorted(&stack_A);
	return (0);
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

