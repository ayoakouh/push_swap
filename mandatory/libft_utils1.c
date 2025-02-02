/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoakouh <ayoakouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:51:33 by ayoakouh          #+#    #+#             */
/*   Updated: 2025/02/02 08:12:10 by ayoakouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// void	ft_lstadd_front(t_stack **lst, t_stack *new)
// {
// 	if (!new || !lst)
// 		return ;
// 	if (*lst == NULL)
// 	{
// 		*lst = new;
// 		return ;
// 	}
// 	new->next = *lst;
// 	*lst = new;
// }

t_stack	*creatnew_node(int value)
{
	t_stack	*new;

	new = NULL;
	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new ->data = value;
	new ->index = -1;
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