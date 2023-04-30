/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohamadou <ohamadou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 09:06:09 by ohamadou          #+#    #+#             */
/*   Updated: 2023/04/30 08:35:27 by ohamadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	blanks(const char c)
{
	if (c == ' ' || c == '\n' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

long int	ft_atoi(const char *str)
{
	int			i;
	long int	opr;
	int			sign;

	i = 0;
	while (blanks(str[i]))
		i++;
	if ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
			i++;
	}
	opr = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		opr = opr * 10 + (str[i] - '0');
		i++;
	}
	return (opr * sign);
}
