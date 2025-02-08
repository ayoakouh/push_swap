/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoakouh <ayoakouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:35:50 by ayoakouh          #+#    #+#             */
/*   Updated: 2025/02/08 13:13:39 by ayoakouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	check_input(char *operation, t_stack **a, t_stack **b)
{
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
	else if (ft_strcmp(operation, "ss\n") == 0)
		swap_a_b(a, b);
	else if (ft_strcmp(operation, "rr\n") == 0)
		rot_a_b(a, b);
	else if (ft_strcmp(operation, "rrr\n") == 0)
		reverse_rot_ab(a, b);
	else
		(write(2, "Error\n", 6), exit(1));
}

static void	execute_operations(t_stack **ops, t_stack **a, t_stack **b)
{
	t_stack	*current;

	current = *ops;
	while (current)
	{
		check_input(current->operation, a, b);
		current = current->next;
	}
}

static void	add_operation(t_stack **input, char *line)
{
	t_stack	*new_node;
	t_stack	*current;

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

static void	print_ok_ko(t_stack **a, t_stack **b)
{
	if ((*a)->data && (*a)->next == NULL)
		write(1, "OK\n", 3);
	else if (*a && (*a)->next != NULL && check_sorted(a) == 1 && !(*b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*input;
	char	*line;

	a = NULL;
	b = NULL;
	input = NULL;
	if (ac < 2)
		exit(0);
	av = check_args(ac, av);
	initialz_stack_a(&a, av);
	line = get_next_line(0);
	while (line != NULL)
	{
		add_operation(&input, line);
		line = get_next_line(0);
	}
	execute_operations(&input, &a, &b);
	print_ok_ko(&a, &b);
	free_stack(&a);
	free_stack(&b);
	free_operation(&input);
	free_av(av);
	return (0);
}
