/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing_of_checker_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoakouh <ayoakouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:19:30 by ayoakouh          #+#    #+#             */
/*   Updated: 2025/02/08 12:58:51 by ayoakouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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

char	*concat_args(int ac, char **av)
{
	char	*str;
	char	*tmp;
	int		i;

	i = 2;
	str = ft_strdup(av[1]);
	while (i - 1 < ac)
	{
		tmp = str;
		str = ft_strjoin(str, " ");
		free(tmp);
		tmp = str;
		str = ft_strjoin(str, av[i]);
		free(tmp);
		i++;
	}
	return (str);
}

char	**ft(int ac, char **av)
{
	char	**split_string;
	char	*str;

	split_string = NULL;
	if (ac >= 2)
	{
		str = concat_args(ac, av);
		split_string = ft_split(str, 32);
		free(str);
	}
	else
		split_string = ft_split(av[1], 32);
	return (split_string);
}

char	**check_args(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 2)
		return (0);
	if (check_empty(av) == 0)
		(write(2, "Error\n", 7), exit(1));
	av = ft(ac, av);
	if (duplicate(av) == 0)
		(write(2, "Error\n", 7), free_av(av), exit(1));
	while (av[i])
	{
		if (av[i] && (is_valide(av[i]) == 0 || is_range_valide(av[i]) == 0))
			(write(2, "Error\n", 7), free_av(av), exit(1));
		i++;
	}
	return (av);
}
