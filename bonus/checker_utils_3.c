/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoakouh <ayoakouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:10:51 by ayoakouh          #+#    #+#             */
/*   Updated: 2025/02/03 18:13:23 by ayoakouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return (s1[i] - s2[j]);
}

t_stack	*initialz_stack_a(t_stack **a, char **av)
{
	int		i;
	t_stack	*node1;

	node1 = NULL;
	i = 0;
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
void free_av(char **av)
{
	int i = 0;
	while (av[i])
		free(av[i++]);
	free(av);
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
int	is_range_valide(char *str)
{
	long	number;

	number = ft_atoi(str);
	if (number < INT_MIN || number > INT_MAX)
		return (0);
	return (1);
}