/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 20:54:06 by olmatske          #+#    #+#             */
/*   Updated: 2025/12/22 18:40:11 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	input_check(int start, char **tokens)
{
	int		i;
	long	n;

	while (tokens[start])
	{
		i = 0;
		if (tokens[start][i] == '-' || tokens[start][i] == '+')
			i++;
		if (!tokens[start][i])
			return (ft_printf("Error\n"), 1);
		while (tokens[start][i])
		{
			if (!ft_isdigit((unsigned char)tokens[start][i]))
				return (ft_printf("Error\n"), 1);
			i++;
		}
		n = ft_atol(tokens[start]);
		if (n > INT_MAX || n < INT_MIN)
			return (ft_printf("Error\n"), 1);
		start++;
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

int	no_dupes(char **tokens)
{
	long	i;
	long	k;
	long	len;

	i = 0;
	k = 1;
	len = 0;
	while (tokens[len])
		len++;
	while (tokens[i])
	{
		k = i + 1;
		while (tokens[k])
		{
			if (ft_strncmp(tokens[i], tokens[k], len) == 0)
			{
				ft_printf("Error\n");
				return (1);
			}
			k++;
		}
		i++;
	}
	return (0);
}
