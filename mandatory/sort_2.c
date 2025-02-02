/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoakouh <ayoakouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:43:17 by ayoakouh          #+#    #+#             */
/*   Updated: 2025/01/31 18:40:53 by ayoakouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calcul_move(t_stack **b, int index)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *b;
	while (tmp && tmp->index != index)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	form_max_to_last(t_stack **b, int index)
{
	t_stack	*tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	tmp = *b;
	while (tmp && tmp->index != index)
	{
		i++;
		tmp = tmp->next;
	}
	while (tmp)
	{
		j++;
		tmp = tmp->next;
	}
	return (j);
}

void	sort_all(t_stack **a, t_stack **b)
{
	int	len;
	int	max_index;
	int	move_forward;
	int	move_backward;

	len = ft_lstsize(*b);
	while (len > 0)
	{
		max_index = len - 1;
		move_forward = calcul_move(b, max_index);
		move_backward = form_max_to_last(b, max_index);
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
// int main(int ac, char **av)
// {
//     t_stack *a;
//     t_stack *b ;
//     int    i;

//     i = 1;
//     a = NULL;
//     b = NULL;
//     if(ac < 2)
//         return(0);
//     av = ft(ac, av);
//     if(check_empty(av, ac) == 0 || duplicate(av) == 0)
//         return(write(2, "Error\n", 6), 0);
//     while(av[i])
//     {
//         if(av[i] && (is_valide(av[i]) == 0 || is_range_valide(av[i]) == 0))
//             return(write(2, "Error\n", 6), 0);
//         i++;
//     }
//     initialz_stack(&a, av);
//     if(check_sorted(&a) == 0)
//         return(0);
//     indexing_node(&a); 
//     if(ft_lstsize(a) == 3)
//         sorte_tree(&a);
//     else
//     {
//         smale_sort(&a, &b);
//         sort_all(&a, &b);
//     }
//     free_stack(&a);
// }
