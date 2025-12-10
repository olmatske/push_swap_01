/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 20:54:06 by olmatske          #+#    #+#             */
/*   Updated: 2025/12/09 19:00:03 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// validate input
// validate stack
// 

int	input_check(char **tokens)
{
	int		i;
	int		k;
	long	n;

	k = 0;
	while (tokens[k])
	{
		i = 0;
		if (tokens[k][i] == '-' || tokens[k][i] == '+')
			i++;
		if (!tokens[k][i])
			return (ft_printf("Invalid input - please parse a string of numbers\n"), 1);
		while (tokens[k][i])
		{
			if (!ft_isdigit((unsigned char)tokens[k][i]))
				return (ft_printf("Invalid input\n"), 1);
			i++;
		}
		n = ft_atol(tokens[k]);
		if (n > INT_MAX || n < INT_MIN)
			return (ft_printf("Invalid Input\n"), 1);
		k++;
	}
	return (0);
}

long	ft_atol(const char *str)
{
	long	res;
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
