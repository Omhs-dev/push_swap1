/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:21:13 by ohamadou          #+#    #+#             */
/*   Updated: 2023/06/04 08:49:44 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//is the stack sorted ?
int	sort_checked(t_stack *stack)
{
	while (stack -> next != NULL)
	{
		if (stack -> data > stack -> next -> data)
			return (0);
		stack = stack -> next;
	}
	return (1);
}

//sort depending on the number of values (stack_n)
static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_n)
{
	if (stack_n == 2 && !sort_checked(*stack_a))
		swap_a(stack_a);
	else if (stack_n == 3)
		sort_three(stack_a);
	else
		sort(stack_a, stack_b);
	return ;
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_n;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	stack_a = stack_values(argc, argv);
	stack_n = stack_size(stack_a);
	// if (!input_okay(argv))
	// {
	// 	write(2, "Error\n", 6);
	// 	exit(EXIT_FAILURE);
	// }
	if (sort_checked(stack_a))
		return (0);
	indexation(stack_a, stack_n + 1);
	push_swap(&stack_a, &stack_b, stack_n);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}