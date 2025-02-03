/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoakouh <ayoakouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:30:28 by ayoakouh          #+#    #+#             */
/*   Updated: 2025/02/03 10:47:07 by ayoakouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	int				index;
}	t_stack;

long	ft_atoi(char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
int		ft_strlen(const char *s);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
int		ft_isdigit(char c);
void	swap_a(t_stack **a);
void	push_a(t_stack **a, t_stack **b);
void	rot_a(t_stack **a);
void	r_rot_a(t_stack **a);
void	swap_b(t_stack **b);
void	push_b(t_stack **a, t_stack **b);
void	rot_b(t_stack **b);
void	r_rot_b(t_stack **b);
int		is_valide(char *str);
int		is_range_valide(char *str);
int		duplicate(char **str);
t_stack	*creatnew_node(int value);
int		ft_parssing(int ac, char **av);
int		is_all_digits(char *str);
int		ft_lstsize(t_stack *lst);
int		check_empty(char **av);
t_stack	*find_min(t_stack **lst);
void	indexing_node(t_stack **lst);
void	smale_sort(t_stack **a, t_stack **b);
void	sort_all(t_stack **a, t_stack **b);
void	sort_tree(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);
int		check_sorted(t_stack **a);
void	free_stack(t_stack **stack);

#endif

// #ifndef PUSH_SWAP_H
// # define PUSH_SWAP_H

// #include<stdio.h>
// #include<stdlib.h>
// #include<unistd.h>
// #include<limits.h>

// typedef struct s_stack
// {
//     int data;
//     struct s_stack *next;
//     int index;
// }  t_stack;

// long ft_atoi(char *str);
// char	**ft_split(char const *s, char c);
// char	*ft_strjoin(char *s1, char *s2);
// char	*ft_strdup(const char *s);
// int	ft_strlen(const char *s);
// void	ft_lstadd_front(t_stack **lst, t_stack *new);
// void	ft_lstadd_back(t_stack **lst, t_stack *new);
// t_stack	*ft_lstlast(t_stack *lst);
// int	ft_isdigit(char c);
// int	ft_strlen(const char *s);
// void swap_a(t_stack **a);
// void push_a(t_stack **a, t_stack **b);
// void rot_a(t_stack **a);
// void r_rot_a(t_stack **a);
// void swap_b(t_stack **b);
// void push_b (t_stack **a, t_stack **b);
// void rot_b(t_stack **b);
// void r_rot_b(t_stack **b);
// int is_valide(char *str);
// int is_range_valide(char *str);
// int duplicate(char **str); 
// t_stack *creatnew_node(int value);
// int ft_parssing(int ac, char **av);
// int is_all_digits(char *str);
// int	ft_lstsize(t_stack *lst);
// int check_empty(char **av);
// t_stack *find_min(t_stack **lst);
// void indexing_node(t_stack **lst);
// void smale_sort(t_stack **a, t_stack **b);
// void sort_all(t_stack **a, t_stack **b);
// // void position(t_stack **b);
// void free_stack(t_stack **a);
// void sort_tree(t_stack **a);
// void sort_five(t_stack **a, t_stack **b);

// int check_sorted(t_stack **a);
// #endif