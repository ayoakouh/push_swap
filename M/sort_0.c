/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoakouh <ayoakouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:44:18 by ayoakouh          #+#    #+#             */
/*   Updated: 2025/02/08 12:27:24 by ayoakouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_av(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		free(av[i++]);
	free(av);
}

int	ft_check_reverse_number(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	if (!(*a) || !a)
		return (0);
	while (tmp->next)
	{
		if (tmp->data > tmp->next->data)
			tmp = tmp->next;
		else
			break ;
	}
	if (tmp->next == NULL)
		return (1);
	return (0);
}

void	sort_reverse(t_stack **a, t_stack **b)
{
	int	len;

	len = ft_lstsize(*a);
	while (len > 0)
	{
		push_b(a, b);
		rot_b(b);
		len--;
	}
	len = ft_lstsize(*b);
	while (len > 0)
	{
		push_a(a, b);
		len--;
	}
}
