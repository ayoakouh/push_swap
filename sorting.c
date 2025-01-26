#include "push_swap.h"
t_stack *find_min(t_stack **lst)
{
    t_stack *min = NULL;
    t_stack *current;
    
    current = *lst;
    while(current)
    {
        if(current ->index == -1 && (min == NULL || current-> data < min-> data))
            min = current;
        current = current ->next;
    }
    return(min);
}
void indexing_node(t_stack **lst)
{
    int index;
    t_stack *min = NULL;

    index = 0;
    while((min = find_min(lst)) != NULL)
    {
        min ->index = index;
        index++;
    }
}
int size_range(t_stack **a)
{
    int range;
    if(ft_lstsize(*a) <= 100)
        range = 17;
    if(ft_lstsize(*a) > 100)
        range = 39;
    return(range);
}
void smale_sort(t_stack **a, t_stack **b)
{
    int i;
    int range;

    i = 0;
    range = size_range(a);
 
    while((*a) != NULL)
    {
        if((*a) ->index <= i){
            push_b(a, b);
            i++;
        }
        else if((*a) ->index <= (i + range))
            {
                push_b(a, b);
                if(ft_lstsize(*b) > 1)
                {
                    rot_b(b);
                }
                i++;
            }
        else
            rot_a(a);
    }
}
t_stack *find_max_value(t_stack **b)
{
    if (b == NULL || *b == NULL)
        exit(0);
    t_stack *max = NULL;
    t_stack *current;
    
    current = *b;
    while(current)
    {
        if(max == NULL || current->data > max->data)
            max = current;
        current = current->next;
    }
    return(max);
}
int check_of_max_is_top(t_stack **b, int index)
{
    if(*b &&(*b)->index == index)
    {
        return(0);
    }
    return(1);
}
int check_of_max_is_last(t_stack **b, int index)
{
    if ((*b) == NULL || (b) == NULL)
        return 0;
    while((*b)->next != NULL)
    {
        *b = (*b)->next;
    }
    if((*b)->index == index)
        return(1);
    return(0);
}
int calcul_move(t_stack **b, int index)
{
    t_stack *tmp;
    int i;

    i = 0;
    tmp = *b;
    while(tmp && tmp->index != index)
    {
        tmp = tmp->next;
        i++;
    }
    return(i);
}
int form_max_to_last(t_stack **b, int index)
{
     t_stack *tmp;
    int i;
    int j;
    j = 0;
    i = 0;
    tmp = *b;
    while(tmp && tmp->index != index)
    {
        i++;
        tmp = tmp->next;
    }

    while (tmp)
    {
        j++;
        tmp = tmp->next;
    }
    return(j);
}

void sort_all(t_stack **a, t_stack **b)
{
    int len = ft_lstsize(*b);
    while(len > 0)
    {
        int max_index = len - 1;
        int move_forward = calcul_move(b, max_index);
        int move_backward = form_max_to_last(b, max_index);

        if (move_forward <= move_backward)
        {
            while ((*b)->index != max_index)
                rot_b(b);
        }
        else
        {
            while ((*b)->index != max_index)
                r_rot_b(b);
        }

        push_a(a, b);
        len--;
    }
}

// int find_position(t_stack **b)
// {
//     t_stack *current;
//     t_stack *max;
//     int position;

//     position = 0;
//     max = find_max_value(b);
//     current = *b;
//     while(max != NULL && *b != NULL)
//     {
//         if(current->data == max->data)
//             return(position);
//         position++;
//         current = current->next;
//     }
//     return(position);
// }