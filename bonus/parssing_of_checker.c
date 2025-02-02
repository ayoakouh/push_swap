/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing_of_checker.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoakouh <ayoakouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:19:30 by ayoakouh          #+#    #+#             */
/*   Updated: 2025/02/02 16:52:37 by ayoakouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_valide(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] == '\0')
		return (0);
	if ((str[i] == '-' || str[i] == '+') && (str[i + 1] == '0'))
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
int    is_same_number(char *str1, char *str2)
{
    int    num1;
    int    num2;

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

char	**ft(int ac, char **av)
{
	char	**split_string;
	char	*tmp;
	char	*str;
	int		i;

	i = 2;
	str = NULL;
	split_string = NULL;
	if (ac >= 2)
	{
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
		split_string = ft_split(str, 32);
		free(str);
	}
	else
		split_string = ft_split(av[1], 32);
	return (split_string);
}

int check_args(int ac, char **av)
{
    int i;

    i = 1;
    if (ac < 2)
        return (0);
    if (check_empty(av) == 0)
        return (write(2, "Error\n", 6), 0);
    av = ft(ac, av);
    if(duplicate(av) == 0)
        return (write(2, "Error\n", 6), 0);
    while (av[i])
    {
        if (av[i] && (is_valide(av[i]) == 0 || is_range_valide(av[i]) == 0))
            return (write(2, "Error\n", 6), 0);
        i++;
    }
	i = 0;
	while (av[i])
		free(av[i++]);
	free(av);
    return (1);
}

t_stack	*initialz_stack_a(t_stack **a, char **av)
{
	int		i;
	t_stack	*node1;

	node1 = NULL;
	i = 1;
	if(!a || (*a))
		return(NULL);
	while (av[i])
	{
		node1 = creatnew_node(ft_atoi(av[i]));
		ft_lstadd_back(a, node1);
		i++;
	}
	return (*a);
}