/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoakouh <ayoakouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:54:09 by ayoakouh          #+#    #+#             */
/*   Updated: 2025/02/08 17:11:10 by ayoakouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*initialz_stack(t_stack **a, char **av)
{
	int		i;
	t_stack	*node1;

	node1 = NULL;
	i = 0;
	while (av[i])
	{
		node1 = creatnew_node(ft_atoi(av[i]));
		ft_lstadd_back(a, node1);
		i++;
	}
	free_av(av);
	return (*a);
}

static char	*join_args(int ac, char **av)
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

static char	**spliting(int ac, char **av)
{
	char	*str;
	char	**split_string;

	split_string = NULL;
	if (ac >= 2)
	{
		str = join_args(ac, av);
		split_string = ft_split(str, 32);
		free(str);
	}
	else
		split_string = ft_split(av[1], 32);
	return (split_string);
}

static void	sorting(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) == 2)
		sort_two(a);
	else if (ft_lstsize(*a) == 3)
		sort_tree(a);
	else if (ft_lstsize(*a) == 4)
		sort_foor(a);
	else if (ft_lstsize(*a) == 5)
		sort_five(a, b);
	else if (ft_check_reverse_number(a) == 1)
		sort_reverse(a, b);
	else
	{
		smale_sort(a, b);
		sort_all(a, b);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	i = -1;
	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (check_empty(av) == 0)
		return (write(2, "Error\n", 6), 1);
	av = spliting(ac, av);
	while (av[++i])
	{
		if (av[i] && (is_valide(av[i]) == 0 || is_range_valide(av[i]) == 0))
			return (write(2, "Error\n", 6), free_av(av), 1);
	}
	if (duplicate(av) == 0)
		return (write(2, "Error\n", 6), free_av(av), 1);
	initialz_stack(&a, av);
	if (check_sorted(&a) == 0)
		return (free_stack(&a), 0);
	indexing_node(&a);
	sorting(&a, &b);
	free_stack(&a);
}
