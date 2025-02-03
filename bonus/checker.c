/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoakouh <ayoakouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:35:50 by ayoakouh          #+#    #+#             */
/*   Updated: 2025/02/03 18:48:50 by ayoakouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void free_operation(t_stack **input)
{
	t_stack *current;
	t_stack *tmp;
	if(input == NULL)
		return ;
	current = *input;
	while(current)
	{
		tmp = current->next;
		free(current->operation);
		free(current);
		current = tmp;
	}
	*input = NULL;
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
void check_input(char *operation, t_stack **a, t_stack **b)
{
	if (!operation || !a || !b)
		return;

	if (ft_strcmp(operation, "pa\n") == 0)
		push_a(a, b);
	else if (ft_strcmp(operation, "ra\n") == 0)
		rot_a(a);
	else if (ft_strcmp(operation, "rra\n") == 0)
		r_rot_a(a);
	else if (ft_strcmp(operation, "sa\n") == 0)
		swap_a(a);
	else if (ft_strcmp(operation, "pb\n") == 0)
		push_b(a, b);
	else if (ft_strcmp(operation, "rb\n") == 0)
		rot_b(b);
	else if (ft_strcmp(operation, "rrb\n") == 0)
		r_rot_b(b);
	else if (ft_strcmp(operation, "sb\n") == 0)
		swap_b(b);
	else
		write(1, "Error\n", 6);
}

void execute_operations(t_stack **ops, t_stack **a, t_stack **b)
{
	t_stack *current;

	current = *ops;
	while (current)
	{
		check_input(current->operation, a, b);
		current = current->next;
	}
}

void add_operation(t_stack **input, char *line)
{
	t_stack *new_node;
	t_stack *current;
	// t_stack *tmp;
	if (!input || !line)
		return ;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;

	new_node->operation = ft_strdup(line);
	new_node->next = NULL;
	if (!*input)
	{
		*input = new_node;
		free(line);
		return ;
	}
	current = *input;
	while (current->next != NULL)
		current = current->next;
	current->next = new_node;
	free(line);
}
void f()
{
	system("leaks checker");
}
int main(int ac, char **av)
{
	// atexit(f);
    t_stack *a = NULL;
    t_stack *b = NULL;
    t_stack *input = NULL;
    char *line; 
    
    if (ac < 2)
        exit(1);
    av = check_args(ac, av);
    initialz_stack_a(&a, av);
    while ((line = get_next_line(0)) != NULL)
        add_operation(&input, line);
    execute_operations(&input, &a, &b);
	// tmp = a;
	// while(tmp)
	// {
	// 	printf("%d\n",tmp->data);
	// 	tmp = tmp->next;
	// }
    if (check_sorted(&a) == 1 && !b)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
    free_stack(&a);
    free_stack(&b);
    free_operation(&input);
	free_av(av);
    return 0;
}