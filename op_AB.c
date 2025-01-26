#include "push_swap.h"

void swap_a_b(t_stack **a, t_stack **b)
{
    swap_a(a);
    swap_b(b);
    write(1, "ss\n", 3);
}
void rot_a_b(t_stack **a, t_stack **b)
{
    rot_a(a);
    rot_b(b);
    write (1, "rr\n", 3);
}
void reverse_rot_ab(t_stack **a, t_stack **b)
{
    r_rot_a(a);
    r_rot_b(b);
    write(1, "rrr\n", 4);
}