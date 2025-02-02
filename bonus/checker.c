/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoakouh <ayoakouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:35:50 by ayoakouh          #+#    #+#             */
/*   Updated: 2025/02/02 16:54:51 by ayoakouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void f()
{
    system("leaks checker");
}
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
    t_stack *current = *ops;
    
    while (current)
    {
        check_input(current->operation, a, b);
        current = current->next;
    }
}

t_stack *add_operation(t_stack **input, char *line)
{
    t_stack *new_node;
    t_stack *current;

    if (!input || !line)
        return NULL;

    new_node = malloc(sizeof(t_stack));
    if (!new_node)
        return (NULL);

    new_node->operation = ft_strdup(line);
    new_node->next = NULL;
    if (!*input)
    {
        *input = new_node;
        free(line);
        return (*input);
    }
    current = *input;
    while (current->next != NULL)
        current = current->next;
    current->next = new_node;
    return (free(line), *input);
}

int main(int ac, char **av)
{
    atexit(f);
    t_stack *a = NULL;
    t_stack *b = NULL;
    t_stack *input = NULL;
    char *line; 
    
    if (ac < 2)
        exit(1);

    if (!check_args(ac, av))
        return 0;

    initialz_stack_a(&a, av);

    while ((line = get_next_line(0)) != NULL)
    {
        // free(line);
       add_operation(&input, line);
    }
    execute_operations(&input, &a, &b);

    if (check_sorted(&a) == 1 && !b)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
    free_stack(&a);
    free_operation(&input);
    return 0;
}
// void check_input(t_stack **input, t_stack **a, t_stack **b)
// {
//     // if(!input || (*input) || !a || (*a))
//     //     return ;
//     // //    t_stack *current = *input;
//     // while(*input)
//     // {
//         if (ft_strcmp((*input)->operation, "pa\n") == 0)
//             push_a(a, b);
//         else if (ft_strcmp((*input)->operation, "ra\n") == 0)
//             rot_a(a);
//         else if (ft_strcmp((*input)->operation, "rra\n") == 0)
//             r_rot_a(a);
//         else if (ft_strcmp((*input)->operation, "sa\n") == 0)
//             swap_a(a);
//         else if (ft_strcmp((*input)->operation, "pb\n") == 0)
//             push_b(a, b);
//         else if (ft_strcmp((*input)->operation, "rb\n") == 0)
//             rot_b(b);
//         else if (ft_strcmp((*input)->operation, "rrb\n") == 0)
//             r_rot_b(b);
//         else if (ft_strcmp((*input)->operation, "sb\n") == 0)
//             swap_b(b);
//         else
//             write(1, "Error\n", 6);
//         // *input = (*input)->next;
//     // }
// }
// void execute_operations(t_stack **ops, t_stack *a, t_stack *b)
// {
//     while (*ops)
//     {
//         check_input((*ops)->operation, &a, &b);
//         *ops = (*ops)->next;
//     }
// }
// t_stack *add_operation(t_stack **input, char *line)
// {
//     t_stack *new_node;
//     t_stack *current;

//     if (!input || !line)
//         return NULL;

//     new_node = malloc(sizeof(t_stack));
//     if (!new_node)
//         return NULL;

//     new_node->operation = ft_strdup(line);
//     new_node->next = NULL;

//     if (!*input)
//     {
//         *input = new_node;
//     }
//     current = *input;
//     while(current->next != NULL)
//     {
//         current = current->next;
//     }
//     current->next = new_node;
//     new_node->next = NULL;
//     free(line);
//     return (*input);
// }

// int main(int ac, char **av)
// {
//     t_stack *a = NULL;
//     t_stack *b = NULL;
//     t_stack *input = NULL;
//     char *line; 
//     if (ac < 2)
//         exit(1);

//     if (!check_args(ac, av))
//         return 0;

//     initialz_stack_a(&a, av);

//     while ((line = get_next_line(0)) != NULL)
//     {
//         add_operation(&input, line);
//     }
//     execute_operations(&input, a, b);
//     // check_input(&input, &a, &b);

//     // Check if stack is sorted
    
//     if (check_sorted(&a) == 1 && !b)
//         write(1, "OK\n", 3);
//     else
//         write(1, "KO\n", 3);

//     return 0;
// }
// t_stack    **add_operation(t_stack **head, char *line)
// {
//     t_stack *node;
//     t_stack *tmp;

//     if(!head || !(*head) || !line)
//         return(NULL);
//     node = malloc(sizeof(t_stack));
//     if(!node)
//         return(NULL);
//     node->operation = line;
//     node->next = NULL;
//     if(!(*head))
//         *head = node;
//     else
//     {
//         tmp = *head;
//         while(tmp->next != NULL)
//             tmp = tmp->next;
//         tmp->next = node;
//         // node->next = NULL;
//     }
//     return(head);  
// }
// int main(int ac , char **av)
// {
//     t_stack **tmp;
//     t_stack *a = NULL;
//     t_stack *b = NULL;
//     t_stack **input = NULL;
//     char *line;
//     if(ac < 2)
//         exit(1);
//     if (!check_args(ac, av))
//         return (0);
//     initialz_stack(&a, av);
//     if(check_sorted(&a) == 0)
//         return(0);
//     while((line = get_next_line(0)) != NULL)
//         tmp = add_operation(input, line);
//     check_input(tmp, &a, &b);
//     printf("heloo\n");
//     if((check_sorted(&a) == 0) && !b)
//     {
//         write(1, "OK\n", 3);
//         // return(free(input),0);
//     }
//     else
//     {
//         write(1, "KO\n", 3);
//         // return(free(input), 0);
//     }
//     // tmp = a;
//     while(a)
//     {
//         printf("%d\n", a->data);
//         a = a-> next;
//     }
// }
//******************************
// void read_instraction(t_stack **head, char *line)
// {
//     int i = 0;
//     while((line = get_next_line(0)) != NULL)
//     {
//         add_operation(head, line);
//     }
// }
    // f();
// char    **read_instraction()
// {
//     int i = 0;
//     int help = 5;
//     char *line = NULL;
//     char **str = NULL;
//     char *tmp;

//     str = malloc(sizeof(char *) * (help + 1));
//     if(!str)
//         return (free(str), NULL);
//     while ((line = get_next_line(0)) != NULL)
//     {
//         if(i >= help)
//         {
//             help += 1;
//             tmp = malloc(sizeof(char *) * (help + 1));
//             tmp = ft_strjoin(tmp, str);
//             if(!tmp)
//             {
//                 return(free(tmp), NULL);
//             }
//         }
//         str[i++] = line;
//         free(&tmp);
//     }
//     i = 0;
//     while(str[i])
//     {
//         printf("%s\n", str[i]);
//         i++;
//     }
//     return(tmp);
// }