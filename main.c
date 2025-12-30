/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:14:09 by olmatske          #+#    #+#             */
/*   Updated: 2025/12/30 23:59:38 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int main(int argc, char **argv)
{
	t_node *stack_A;
	t_node *stack_B;
	char	**tokens;

	stack_A = NULL;
	stack_B = NULL;
	if (argc != 2)
	{
		if (input_check(1, argv) != 0 || no_dupes(argv) != 0)
			return (ft_printf("Error\n"),free_stack(&stack_A), 1);
		stack_A = stack_init(stack_A, &argv[1]);
	}
	else
	{
		tokens = ft_split(argv[1], ' ');
		if (!tokens)
			return (ft_printf("Error\n"), 1);
		if (input_check(0, tokens) != 0 || no_dupes(tokens) != 0)
			return (free_char_array(tokens), ft_printf("Error\n"), 1);
		stack_A = stack_init(stack_A, tokens);
	}
	sort_it(&stack_A, &stack_B, stack_len(stack_A));
	list_stack_A(stack_A);
	free_stack(&stack_A);
	return (free_char_array(tokens), 0);
}

void	free_stack(t_node **a)
{
	t_node	*tmp;

	tmp = (*a);
	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		(*a) = tmp;
	}
}

void	free_char_array(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
