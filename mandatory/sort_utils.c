/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoakouh <ayoakouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:54:17 by ayoakouh          #+#    #+#             */
/*   Updated: 2025/01/31 19:36:50 by ayoakouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp->next != NULL)
	{
		if (tmp->data > tmp->next->data)
			break ;
		tmp = tmp->next;
	}
	if (tmp->next == NULL)
		return (0);
	return (1);
}

t_stack	*find_max_value(t_stack **a)
{
	t_stack	*max;
	t_stack	*current;

	if (a == NULL || *a == NULL)
		exit(0);
	max = NULL;
	current = *a;
	while (current)
	{
		if (max == NULL || current->data > max->data)
			max = current;
		current = current->next;
	}
	return (max);
}

void	sort_tree(t_stack **a)
{
	t_stack	*tmp;

	tmp = find_max_value(a);
	if (tmp->data == (*a)->data)
		rot_a(a);
	if (tmp->data == (*a)->next->data)
		r_rot_a(a);
	if ((*a)->data > (*a)->next->data)
		swap_a(a);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_lstsize(*a);
	while (size--)
	{
		if ((*a)->index == 0 || (*a)->index == 1)
			push_b(a, b);
		else
			rot_a(a);
	}
	sort_tree(a);
	push_a(a, b);
	push_a(a, b);
	if ((*a)->index > (*a)->next->index)
		swap_a(a);
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

// #include "push_swap.h"

// int	check_sorted(t_stack **a)
// {
// 	t_stack *tmp;

// 	tmp = *a;
// 	while(tmp ->next != NULL)
// 	{
// 		if(tmp->data > tmp->next->data)
// 		{
// 			break;
// 		}
// 		tmp = tmp->next;
// 	}
// 	if(tmp ->next == NULL)
// 		return(0);
// 	return(1);
// } 
// t_stack *find_max_value(t_stack **a)
// {
// 	if (a == NULL || *a == NULL)
// 		exit(0);
// 	t_stack *max = NULL;
// 	t_stack *current;
//***********************************************>>>>>>>>
// 	current = *a;
// 	while(current)
// 	{
// 		if(max == NULL || current->data > max->data)
// 			max = current;
// 		current = current->next;
// 	}
// 	return(max);
// }
// void sort_tree(t_stack **a)
// {
// 	t_stack *tmp;

// 	tmp = find_max_value(a);
// 	if (tmp->data == (*a)->data)
// 		rot_a(a);
// 	if (tmp->data == (*a)->next->data)
// 		r_rot_a(a);
// 	if ((*a)->data > (*a)->next->data)
// 		swap_a(a);
// }
// void sort_five(t_stack **a, t_stack **b)
// {
// 	int size = ft_lstsize(*a);
// 	while(size--)
// 	{
// 		if((*a)->index == 0 || (*a)->index == 1)
// 			push_b(a, b);
// 		else
// 			rot_a(a);
// 	}
// 	sort_tree(a);
// 	push_a(a, b);
// 	push_a(a, b);
// 	if((*a)->index > (*a)->next->index)
// 		swap_a(a);
// }
