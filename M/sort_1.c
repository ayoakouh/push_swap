/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoakouh <ayoakouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 18:13:37 by ayoakouh          #+#    #+#             */
/*   Updated: 2025/02/08 17:58:22 by ayoakouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_min(t_stack **lst)
{
	t_stack	*min;
	t_stack	*current;

	min = NULL;
	current = *lst;
	while (current)
	{
		if (current->index == -1 && (min == NULL || current->data < min->data))
			min = current;
		current = current->next;
	}
	return (min);
}

void	indexing_node(t_stack **lst)
{
	int		index;
	t_stack	*min;

	index = 0;
	min = find_min(lst);
	while (min)
	{
		min->index = index;
		min = find_min(lst);
		index++;
	}
}

int	size_range(t_stack **a)
{
	int	range;

	if (ft_lstsize(*a) <= 100)
		range = 11;
	if (ft_lstsize(*a) > 100)
		range = 40;
	return (range);
}

void	smale_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	range;

	i = 0;
	range = size_range(a);
	while ((*a) != NULL)
	{
		if ((*a)->index <= i)
		{
			push_b(a, b);
			i++;
		}
		else if ((*a)->index <= (i + range))
		{
			push_b(a, b);
			if (ft_lstsize(*b) > 1)
				rot_b(b);
			i++;
		}
		else if (ft_mini_sort(*a))
			r_rot_a(a);
		else
			rot_a(a);
	}
}
