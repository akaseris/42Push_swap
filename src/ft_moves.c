/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 15:34:41 by akaseris          #+#    #+#             */
/*   Updated: 2018/04/26 17:02:35 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_color(char *s)
{
	if (ft_strstr(s, "sb"))
		return ("\e[32m");
	else if (ft_strstr(s, "sa"))
		return ("\e[42m");
	else if (ft_strstr(s, "pb"))
		return ("\e[34m");
	else if (ft_strstr(s, "pa"))
		return ("\e[44m");
	else if (ft_strstr(s, "rrb"))
		return ("\e[35m");
	else if (ft_strstr(s, "rra"))
		return ("\e[45m");
	else if (ft_strstr(s, "rb"))
		return ("\e[31m");
	else if (ft_strstr(s, "ra"))
		return ("\e[41m");
	return ("");
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
