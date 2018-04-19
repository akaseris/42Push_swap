/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 15:34:41 by akaseris          #+#    #+#             */
/*   Updated: 2018/04/19 15:09:16 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print(t_stack *sta)
{
	while (sta)
	{
		ft_printf("%d\n", sta->nb);
		sta = sta->next;
	}
}

void	ft_stkswap(t_stack **stk)
{
	int tmp;

	if (!(*stk) || !((*stk)->next))
		return ;
	tmp = (*stk)->nb;
	(*stk)->nb = (*stk)->next->nb;
	(*stk)->next->nb = tmp;
}

void	ft_stkpush(t_stack **src, t_stack **dst)
{
	t_stack *tmp;

	if (!*src)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dst;
	*dst = *src;
	*src = tmp;
}

void	ft_stkrot(t_stack **stk)
{
	t_stack *tmp;
	t_stack *sec;

	if (!(*stk) || !((*stk)->next))
		return ;
	tmp = *stk;
	sec = tmp->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stk;
	(*stk)->next = NULL;
	*stk = sec;
}

void	ft_stkrevrot(t_stack **stk)
{
	t_stack *tmp;
	t_stack *sec;

	if (!(*stk) || !((*stk)->next))
		return ;
	tmp = *stk;
	while (tmp->next->next)
		tmp = tmp->next;
	sec = tmp;
	tmp->next->next = *stk;
	*stk = tmp->next;
	sec->next = NULL;
}
