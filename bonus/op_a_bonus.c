/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_a_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoakouh <ayoakouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:24:36 by ayoakouh          #+#    #+#             */
/*   Updated: 2025/02/08 13:15:23 by ayoakouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap_a(t_stack **a)
{
	int	tmp;

	if (!a || !(*a) || !((*a)->next))
		return ;
	tmp = (*a)-> data;
	(*a)-> data = (*a)->next->data;
	(*a)->next->data = tmp;
}

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!(*b) || !b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
}

void	rot_a(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*help;

	if (!(*a) || !(*a)->next || ft_lstsize(*a) < 2)
		return ;
	tmp = *a;
	*a = (*a)->next;
	help = ft_lstlast(*a);
	help->next = tmp;
	tmp->next = NULL;
}

void	r_rot_a(t_stack **a)
{
	t_stack	*current;
	t_stack	*prev;

	if (!(*a) || !(*a)->next || ft_lstsize(*a) < 2)
		return ;
	current = *a;
	prev = NULL;
	while (current ->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	prev ->next = NULL;
	current ->next = *a;
	*a = current;
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (stack == NULL)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}
