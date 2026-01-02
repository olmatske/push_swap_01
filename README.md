_This project had been created as part of the 42 curriculum by olmatske_

# Description
__Project:__ Write a program that sorts numbers using two stacks and a limited set of operations, aiming to achieve the lowest possible number of actions.

__Goal:__ Sorting numbers parsed form the command line in an ascending order.

# __Overview__
__Algorithm:__ _Radix_ sort using _bitwise operations_

__Execution:__

1. Checking whether input consists of only digits - anything but digits and spaces returns an error
2. Checking for duplicates - if any are found, program returns error
3. Initiating stack A and making a (linked) list using the parsed values
4. Indexing the list from 0 to n, 0 being the smallest value, n being the biggest value without actually sorting it
5. Checking whether the list is already sorted
	- if the list is sorted we exit the function, not putting anything out, as per Subject Requirement
	- however if the list is not sorted, we initialize either one of the tiny sorts (if we have 2, 3 or 5 numbers) or the Radix sort
6. Returning nothing but the operations or "Error" if an error occurs, exiting the program

### List of Operations
	- sa (swap a): Swap the first 2 elements at the top of stack a.
		Do nothing if there is only one element or none.

	- sb (swap b): Swap the first 2 elements at the top of stack b.
		Do nothing if there is only one element or none.

	- ss : sa and sb at the same time.

	- pa (push a): Take the first element at the top of b and put it at the top of a.
		Do nothing if b is empty.

	- pb (push b): Take the first element at the top of a and put it at the top of b.
		Do nothing if a is empty.

	- ra (rotate a): Shift up all elements of stack a by 1.
		The first element becomes the last one.

	- rb (rotate b): Shift up all elements of stack b by 1.
		The first element becomes the last one.

	- rr : ra and rb at the same time.

	- rra (reverse rotate a): Shift down all elements of stack a by 1.
		The last element becomes the first one.

	- rrb (reverse rotate b): Shift down all elements of stack b by 1.
		The last element becomes the first one.

	- rrr : rra and rrb at the same time

---
### __Checklist__

The follwing is my personal checklist I used to track progress and write To-Do's

	- [X] Error checking
	- [X] No dupes!!!
	- [X] put everything in tokens
	- [X] put tokens in stack_a
	- [X] write all the helper functions (like sa, ra etc pp)

		Do nothing if there is only one element or none.
		- [X] sa (swap a): Swap the first 2 elements at the top of stack a.
		- [X] sb (swap b): Swap the first 2 elements at the top of stack b.
		- [X] ss : sa and sb at the same time.

		Do nothing if a/b is empty.
		- [X] pa (push a): Take the first element at the top of b and put it at the top of a.
		- [X] pb (push b): Take the first element at the top of a and put it at the top of b.

		The first element becomes the last one.
		- [X] ra (rotate a): Shift up all elements of stack a by 1.
		- [X] rb (rotate b): Shift up all elements of stack b by 1.
		- [X] rr : ra and rb at the same time.
		The last element becomes the first one.
		- [X] rra (reverse rotate a): Shift down all elements of stack a by 1.
		- [X] rrb (reverse rotate b): Shift down all elements of stack b by 1.
		- [X] rrr : rra and rrb at the same time.

	- [X] decide on alrogrithm
	- [X] write indexer
	- [X] write algorithm logic
		- [X] bitwise operation functions
		- [X] write radix logic
	- [X] write tiny sort ( for 3 and 5 numbers)
	- [X] is sorted function
		> is value > next->value


	- [X] ft_free
	- [X] only 1 number??
	- [X] double number doesn't work if it has a 0 before it
	- [X] are rra and ra right?
	- [X] ft_printf fix in wrapper
	- [X] write main
	- [X] test against a push_swap checker (random 10/100/500 cases, leaks, edge cases like already sorted, reverse sorted, duplicates rejected before)
	- [X] fsanitize flags remove and check leaks
---
### Instructions
1. Clone this project into a new folder
2. Go inside the folder where you cloned the project and type `make` into the command line
3. To start the program after compilation (which you have done with `make`) type `./push_swap` followed up by a space and numbers either inside a string (= inside double quotes) or as arguments (loose numbers)

	__Examples for testing the function:__

	- `./push_swap "1 5 3 734 2"`
	- `./push_swap 645 21 6 36 73 -89 64`

# Resources
- [Push_Swap Visualizer](https://github.com/o-reo/push_swap_visualizer#)
- [Markdown Guide](https://commonmark.org/help/)
- [42 Gitbook](https://42-cursus.gitbook.io/guide/2-rank-02/push_swap)
- [YouTube Push_Swap Guide by Thuggonaut](https://youtu.be/wRvipSG4Mmk?si=DMFgTHkdm8W0bKzA)
- [YouTube Radix Explanation](https://youtu.be/XiuSW_mEn7g?si=R_Ke41c7Q6mRmWPr)
- [Stack Overflow](https://stackoverflow.com/questions)
- Peers
- Perplexity AI usage:

	- Finding minor bugs if my peers and I couldn't find them
	- Checking if my logic would work as indended if no peers present to help ([rubber duck debugging method](https://en.wikipedia.org/wiki/Rubber_duck_debugging))
	- Explaining Terminology if no peers present to help and Internet was of no help
