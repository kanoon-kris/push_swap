/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 15:16:33 by kboonkos          #+#    #+#             */
/*   Updated: 2026/11/08 00:15:56 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_payload
{
	int	value;
	int	rank;
}		t_payload;

typedef enum e_strategy
{
	UNSET,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}		t_strategy;

typedef struct s_flag
{
	t_strategy	strategy;
	bool		bench;
}		t_flag;

// Stack operations for the push_swap helpers
void		push(t_list **lst, t_list *new);
t_list		*pop(t_list **lst);
int			peek(t_list *lst);
bool		is_empty(t_list *lst);

// push_swap helpers for push_swap wrappers
bool		push_top(t_list **dst, t_list **src);
bool		swap(t_list **lst);
bool		rotate(t_list **lst);
bool		reverse_rotate(t_list **lst);

// push_swap wrappers for push_swap operations
void		pa(t_list **a, t_list **b);
void		pb(t_list **b, t_list **a);

void		sa(t_list **a);
void		sb(t_list **b);
void		ss(t_list **a, t_list **b);

void		ra(t_list **a);
void		rb(t_list **b);
void		rr(t_list **a, t_list **b);

void		rra(t_list **a);
void		rrb(t_list **b);
void		rrr(t_list **a, t_list **b);

// Parsers
bool		parse_int(const char *s, int *out);
bool		is_valid_flag(const char *str);

// Payload
t_payload	*parse_payload(int value, int rank);
void		print_payload(void *content);
int			get_value(t_list *lst);
int			get_rank(t_list *lst);

// Disorder
void	print_disorder(long long h);
void	compute_mistake_and_total_pair(t_list *lst, long long *mistake,
long long *total_pair);
void	compute_disorder(t_list *lst);

// Etc
int			ft_strcmp(const char *s1, const char *s2);

#endif
