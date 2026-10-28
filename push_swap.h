/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kboonkos <kboonkos@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 15:16:33 by kboonkos          #+#    #+#             */
/*   Updated: 2026/10/26 02:29:16 by kboonkos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_payload
{
	int	value;
	bool	is_processed;
}		t_payload;

// Basic stack operations to form the push_swap operations
void	push(t_list **lst, t_list *new);
t_list	*pop(t_list **lst);
int	peek(t_list *lst);
bool	is_empty(t_list *lst);

// push_swap operations
void	p(t_list **dst, t_list **src);
void	s(t_list **lst);
void	r(t_list **dst, t_list **src);
void	rr(t_list **dst, t_list **src);

void	pa();
void	pb();
void	sa();
void	sb();
void	ss();
void	ra();
void	rb();
void	rr();
void	rra();
void	rrb();
void	rrr();

#endif
