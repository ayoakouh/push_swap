#include "push_swap.h"

void swap_b(t_stack **b)
{
    int tmp;
    if(!*b)
        return ;
    tmp = (*b) -> data;
    (*b)-> data = (*b) ->next->data;
    (*b)->next->data = tmp;
    write(1, "sb\n", 3);
}
void push_b(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    if (!(*a)) 
        return;

    tmp = *a;
    *a = (*a)->next;
    tmp->next = *b;
    *b = tmp;
    write(1, "pb\n", 3);
}

void rot_b(t_stack **b)
{
    t_stack *tmp;
    t_stack *curr;

    if (!(*b) || !(*b)->next || ft_lstsize(*b) < 2)
        return;
    tmp = *b;
    *b = (*b)->next;
    tmp->next = NULL;

    curr = ft_lstlast(*b);
    curr->next = tmp;

    write(1, "rb\n", 3);
}
void r_rot_b(t_stack **b)
{
    t_stack *current;
    t_stack *prev;
    if(!(*b) || ft_lstsize(*b) < 2)
        return ;
    current = *b;
    prev = NULL;
    while (current ->next  != NULL)
    {
        prev = current;
    
        current = current->next;
    }
    prev ->next = NULL;
    current ->next = *b;
    *b = current;
    write (1, "rrb\n", 4);
}
