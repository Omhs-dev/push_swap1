/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 06:30:15 by ohamadou          #+#    #+#             */
/*   Updated: 2023/04/30 08:32:49 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

//checks if the argument is a number
static int	arg_nbr_check(char *av)
{
	int	i;

	i = 0;
	if (ft_issign(av[i]) && av[i + i] != '\0')
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] != '\0' && !ft_isdigit(av[i]))
		return (0);
	return (1);
}

//checks if there is a duplicated number
static int	duplicates_check(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && ft_strcmp_nb(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*it checks if argument is a zero.
avoid anything else*/
static int	arg_zero(char *av)
{
	int	i;

	i = 0;
	if (ft_issign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

//checks if the arguments are all numbers
int	input_okay(char **av)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (av[i])
	{
		if (!arg_nbr_check(av[i]))
			return (0);
		j += arg_zero(av[i]);
		i++;
	}
	if (j > 1)
		return (0);
	if (duplicates_check(av))
		return (0);
	return (1);
}
