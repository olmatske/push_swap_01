/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 20:54:06 by olmatske          #+#    #+#             */
/*   Updated: 2025/12/02 20:53:06 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

// validate input
// validate stack
// 

int	input_check(char **tokens)
{
	char	**tokens;
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (tokens[k])
	{
		if (ft_isdigit(tokens[k][i]) == 1)
			return(ft_printf("Invalid Input"), 1);
		if (ft_atol(tokens[k]) < INT_MIN || ft_atol(tokens[k]) > INT_MAX)
			return (ft_printf("Invalid Input, Overflow"), 1);
		i++;
		if(i == '\0')
		{
			k++;
			i = 0;
		}
	}
	return (tokens);
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
