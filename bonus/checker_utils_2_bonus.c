/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoakouh <ayoakouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 10:15:30 by ayoakouh          #+#    #+#             */
/*   Updated: 2025/02/07 16:06:06 by ayoakouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack	*creatnew_node(int value)
{
	t_stack	*new;

	new = NULL;
	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new ->data = value;
	new ->next = NULL;
	return (new);
}

int	ft_lstsize(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst -> next;
	}
	return (count);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*current;

	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current ->next != NULL)
	{
		current = current->next;
	}
	current ->next = new;
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst ->next != NULL)
	{
		lst = lst ->next;
	}
	return (lst);
}

int	check_sorted(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tmp->data > tmp->next->data)
			break ;
		tmp = tmp->next;
	}
	if (tmp->next == NULL)
		return (1);
	return (0);
}
