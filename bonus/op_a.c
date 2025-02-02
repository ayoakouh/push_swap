#include "checker.h"

void	swap_a(t_stack **a)
{
	int	tmp;

	if (!*a)
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

	if (!(*a) || !(*a)->next)
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

	if (!(*a))
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