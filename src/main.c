/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 09:21:13 by ohamadou          #+#    #+#             */
/*   Updated: 2023/04/30 15:27:50 by ohamadou         ###   ########.fr       */
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
	else if (stack_n > 3 && !sort_checked(*stack_a))
		sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_n;

	if (ac < 2)
		return (0);
	if (!input_okay(av))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = stack_values(ac, av);
	stack_n = stack_size(stack_a);
	indexation(stack_a, stack_n + 1);
	push_swap(&stack_a, &stack_b, stack_n);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
