#include "push_swap.h"

t_stack *initialz_stack(t_stack **a, char **av)
{
    int i = 0;
    t_stack *node1 = NULL;
    while(av[i])
    {
        node1 = creatnew_node(ft_atoi(av[i]));
        ft_lstadd_back(a,node1);
        i++;
    }
    return(*a);
}

char **ft(int ac, char **av)
{
    char **split_string = NULL;
    char *tmp;
    char *str;
    int i;

    i = 2;
    if(ac >= 2)
    {
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
        split_string = ft_split(str, 32);
        free(str);
    }
    else
        split_string = ft_split(av[1], 32);
    return (split_string);
}
#include<stdio.h>

int main(int ac, char **av)
{
    t_stack *a = NULL;
    int    i;

    i = 1;
    t_stack *b = NULL;
    if(ac < 2)
        return(0);
    av = ft(ac, av);
    if(check_empty(av, ac) == 0 || duplicate(av) == 0)
        return(write(1, "ERROR\n", 6), 0);
    while(av[i])
    {
        if(av[i] && (is_valide(av[i]) == 0 || is_range_valide(av[i]) == 0))
            return(write(1, "ERROR\n", 6), 0);
        i++;
    }
    initialz_stack(&a, av);
    indexing_node(&a);
    smale_sort(&a, &b);
    sort_all(&a, &b);
    // system("leaks push_swap");
    // while(a)
    // {
    //     printf("------%d\n", a->data);
    //     // printf("----->%d\n", a->position);
    //     a = a->next;
    // }
}







    // ft_algo(a, b);

// int main(int ac,char **av)
// {
//     //parsing ac av 
//     parse_one(ac,av);
//     //creer stack a --> while av ,satck b-->NULL //duplicate;
//     //parsing stack
//     //algorithme
//     return 0;
// }
// void sorting()
// {
//     push_to_b();
//     push_to_a()
// }
// void ft_algo(t_stack **a, t_stack **b)
// {
//     fonction_index(*a);
//     if(ft_lstsize(a) == 2 && not_sorted(a))
//         sa(a);
//     // else if (ft_lstsize(a) == 3 && not_sorted(a))
//     //     ....
//     else
//         sorting(*a, *b);

// }
