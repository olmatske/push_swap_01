/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 17:39:01 by olmatske          #+#    #+#             */
/*   Updated: 2026/01/02 22:30:29 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	**tokens;

	a = NULL;
	b = NULL;
	tokens = NULL;
	if (argc != 2)
	{
		if (input_check(1, argv) != 0 || no_dupes(1, argv) != 0)
			return (ft_printf("Error\n"), free_stack(&a), 1);
		a = stack_init(a, &argv[1], 0);
	}
	else
	{
		tokens = ft_split(argv[1], ' ');
		if (!tokens)
			return (ft_printf("Error\n"), 1);
		if (input_check(0, tokens) != 0 || no_dupes(0, tokens) != 0)
			return (free_char_array(tokens), ft_printf("Error\n"), 1);
		a = stack_init(a, tokens, 1);
	}
	sort_it(&a, &b, stack_len(a));
	return (free_stack(&a), 0);
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
	while (tokens && tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
