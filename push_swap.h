/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 15:16:33 by kboonkos          #+#    #+#             */
/*   Updated: 2026/11/13 21:41:58 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include "libft/libft.h"

// For state control, the first zero, UNSET, is used to distinguish between
// a flag being unset and set.
typedef enum e_strategy
{
	UNSET,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE,
	STRATEGY_COUNT
}	t_strategy;

typedef struct s_flag
{
	t_strategy	strategy;
	bool		bench;
}	t_flag;

typedef enum e_operation
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	OP_COUNT
}	t_operation;

typedef struct s_context
{
	t_list		*a;
	t_list		*b;
	t_list		*op_log;
	t_list		*op_log_tail;
	t_flag		flags;
	int			count[OP_COUNT];
	int			total_ops;
	bool		is_failed;
	long long	disorder;
	long long	mistake;
	long long	total_pair;
	t_strategy	resolved_strategy;
}	t_context;

typedef struct s_payload
{
	int	value;
	int	rank;
}	t_payload;

// Low-level stack operations for the push_swap helpers
// stack_utility.c
void		push(t_list **lst, t_list *new);
t_list		*pop(t_list **lst);
int			peek(t_list *lst);
bool		is_empty(t_list *lst);

// low-level push_swap helpers for push_swap wrappers
bool		push_top(t_list **dst, t_list **src);
bool		swap(t_list **lst);
bool		rotate(t_list **lst);
bool		reverse_rotate(t_list **lst);

// push_swap wrappers for push_swap operations
void		pa(t_context *ctx);
void		pb(t_context *ctx);

void		sa(t_context *ctx);
void		sb(t_context *ctx);
void		ss(t_context *ctx);

void		ra(t_context *ctx);
void		rb(t_context *ctx);
void		rr(t_context *ctx);

void		rra(t_context *ctx);
void		rrb(t_context *ctx);
void		rrr(t_context *ctx);

// parser.c
bool		parse_int(const char *s, int *out);

// parser_02.c
bool		is_duplicated(int count, int *num_buf);
int			which_strategy_flag(const char *str);
int			parse_valid_int_string_with_flags(int argc, char **argv,
				t_flag *flag, int *num_buf);
t_list		*create_node(int value, int rank);
int			initialize_stack(t_list **lst, int count, int *num_buf);

// payload_utility.c
t_payload	*parse_payload(int value, int rank);
void		print_payload(void *content);
int			get_value(t_list *lst);
int			get_rank(t_list *lst);

// disorder.c
void		print_disorder(long long h);
void		compute_mistake_and_total_pair(t_list *lst, long long *mistake,
				long long *total_pair);
void		compute_disorder(t_context *ctx);

// ft_strcmp.c
int			ft_strcmp(const char *s1, const char *s2);

// record.c
bool		record(t_context *ctx, int op);

// bench.c
bool		op_count(t_context *ctx);
bool		print_bench(t_context *ctx);

// log_printer.c
void		print_log(t_list *op_log);

// cleanup.c
bool		context_clear(t_context *ctx);

// sort_three.c
void		sort_three(t_context *ctx);

// simple_strategy.c
void		simple_sort(t_context *ctx);

// medium_strategy.c
bool		medium_sort(t_context *ctx);

#endif
