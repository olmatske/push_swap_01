#include "pushswap.h"

typedef struct t_node
{
	int				value;
	struct t_node	*next;
}					t_node;

t_node	*create_and_fill(int numbers[], int len)
{
	t_node	*start;
	int		i;
	t_node	*current;
	t_node *new_node;

	start = malloc(sizeof(t_node));
	if (len >= 1)
		start->value = numbers[0];
	else
		start->value = 0;
	start->next = NULL;
	i = 1;
	current = start;
	// loop to malloc new struct and append to linked list start
	while (i < len)
	{
		new_node = malloc(sizeof(t_node));
		new_node->value = numbers[i];
		new_node->next = NULL;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
		i++;
	}
	return (start);
}

void	compare_and_print(t_node *start_node)
{
	t_node	*current;

	current = start_node;
	// loop to check current->value with current->next->value
	while (current->next != NULL)
	{
		if (current->value < current->next->value)
			printf("Our value %d is smaller than the next %d\n", current->value,
				current->next->value);
		else
			printf("Our value %d is greater or equal than the next %d\n",
				current->value, current->next->value);
		current = current->next;
	}
}

// int	main(void)
// {
// 	int numbers[] = {3, 5, 2};
// 	int len = sizeof(numbers) / sizeof(numbers[0]);

// 	// declare variable that we can give in each function
// 	t_node *start_node;

// 	// functions to create, fill and compare
// 	start_node = create_and_fill(numbers, len);
// 	compare_and_print(start_node);
// }