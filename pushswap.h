/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:10:48 by olmatske          #+#    #+#             */
/*   Updated: 2025/12/02 20:52:54 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include "./lib/ft_printf/ft_printf.h"


typedef struct node {

	int			index;
	int			value;
	int			lis_flag;
	struct node	*prev;
	struct node	*next;
} t_node;

int main(int argc, char **argv);
int	input_check(char **tokens);
long	ft_atol(const char *str);


#endif

// k sort