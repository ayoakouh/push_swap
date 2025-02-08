/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoakouh <ayoakouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:34:05 by ayoakouh          #+#    #+#             */
/*   Updated: 2025/02/08 11:39:40 by ayoakouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valide(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] == '\0')
		return (0);
	if (str != NULL && (str[i] == '-'
			|| str[i] == '+') && ft_isdigit(str[i + 1]) == 1)
		i++;
	while (str && str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_range_valide(char *str)
{
	long	number;

	number = ft_atoi(str);
	if (number < INT_MIN || number > INT_MAX)
		return (0);
	return (1);
}

int	is_same_number(char *str1, char *str2)
{
	int	num1;
	int	num2;

	num1 = ft_atoi(str1);
	num2 = ft_atoi(str2);
	if (num1 == num2)
		return (0);
	return (1);
}

int	duplicate(char **str)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (is_same_number(str[i], str[j]) == 0)
				count++;
			j++;
		}
		i++;
	}
	if (count == 0)
		return (1);
	return (0);
}

int	check_empty(char **av)
{
	int	i;
	int	j;

	i = 0;
	if (!av)
		return (0);
	while (av[i])
	{
		j = 0;
		while (av[i][j] == 32)
			j++;
		if (av[i][j] == '\0')
			return (0);
		i++;
	}
	return (1);
}
