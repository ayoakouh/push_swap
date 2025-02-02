/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_AB.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoakouh <ayoakouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:11:25 by ayoakouh          #+#    #+#             */
/*   Updated: 2025/02/01 17:29:01 by ayoakouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_a_b(t_stack **a, t_stack **b)
{
	swap_a(a);
	swap_b(b);
}

void	rot_a_b(t_stack **a, t_stack **b)
{
	rot_a(a);
	rot_b(b);
}

void	reverse_rot_ab(t_stack **a, t_stack **b)
{
	r_rot_a(a);
	r_rot_b(b);
	write(1, "rrr\n", 4);
}


// #include "push_swap.h"

// void swap_a_b(t_stack **a, t_stack **b)
// {
//     swap_a(a);
//     swap_b(b);
//     write(1, "ss\n", 3);
// }
// void rot_a_b(t_stack **a, t_stack **b)
// {
//     rot_a(a);
//     rot_b(b);
//     write (1, "rr\n", 3);
// }
// void reverse_rot_ab(t_stack **a, t_stack **b)
// {
//     r_rot_a(a);
//     r_rot_b(b);
//     write(1, "rrr\n", 4);
// }
