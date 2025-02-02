/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoakouh <ayoakouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:26:05 by ayoakouh          #+#    #+#             */
/*   Updated: 2025/02/02 13:52:15 by ayoakouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include<stdlib.h>
#include<unistd.h>
#include<limits.h>
#include<stdio.h>

typedef struct s_stack
{
    int             data;
    char            *operation;
    struct s_stack *next;
} t_stack;

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
int	ft_strlen(const char *s);
int	ft_isdigit(char c);
long	ft_atoi(char *str);
int	ft_strcmp(char *s1, char *s2);
void	swap_a(t_stack **a);
void	push_a(t_stack **a, t_stack **b);
void	rot_a(t_stack **a);
void	r_rot_a(t_stack **a);
void	swap_b(t_stack **b);
void	push_b(t_stack **a, t_stack **b);
void	rot_b(t_stack **b);
void	r_rot_b(t_stack **b);
t_stack	*creatnew_node(int value);
int	ft_lstsize(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
int check_args(int ac, char **av);   //here;
char	**ft(int ac, char **av);   //here;
int	check_empty(char **av);
int	duplicate(char **str);
int	is_range_valide(char *str);
int	is_valide(char *str);
t_stack	*initialz_stack_a(t_stack **a, char **av);
void	swap_a_b(t_stack **a, t_stack **b);
void	rot_a_b(t_stack **a, t_stack **b);
void	reverse_rot_ab(t_stack **a, t_stack **b);
int	check_sorted(t_stack **a);
char	*get_next_line(int fd);





#endif