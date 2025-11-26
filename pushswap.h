/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olmatske <olmatske@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 13:10:48 by olmatske          #+#    #+#             */
/*   Updated: 2025/11/19 14:51:04 by olmatske         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

#include <stdio.h>
#include <unistd.h>
#include "./lib/ft_printf/ft_printf.h"


typedef struct node {

	int			index;
	int			value;
	int			lis_flag;
	struct node	*prev;
	struct node	*next;
} t_node;

// void test(struct stack *s){
// 	s->size = 3;
// }

// int main()
// {
// 	struct node	*A;
// 	struct node	*B;
// 	// struct node	*head = malloc(sizeof(struct node));
// 	head->prev = NULL;
// 	head->index = //function or stack
// 	head->next = NULL;
// 	B->
// 	A.first = malloc(sizeof(struct node));
// 	test(&A);
// }

#endif

// k sort