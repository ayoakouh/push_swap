/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_AB_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoakouh <ayoakouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:11:25 by ayoakouh          #+#    #+#             */
/*   Updated: 2025/02/07 16:06:29 by ayoakouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
}

void	free_operation(t_stack **input)
{
	t_stack	*current;
	t_stack	*tmp;

	if (input == NULL)
		return ;
	current = *input;
	while (current)
	{
		tmp = current->next;
		free(current->operation);
		free(current);
		current = tmp;
	}
	*input = NULL;
}

int	is_valide(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] == '\0')
		return (0);
	if ((str[i] == '-' || str[i] == '+')
		&& (str[i + 1] == '-' || str[i + 1] == '+'))
		return (0);
	if (str != NULL && (str[i] == '-'
			|| str[i] == '+') && ft_isdigit(str[i + 1]) == 1)
		i++;
	while (str && str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
