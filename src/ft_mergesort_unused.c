/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mergesort_unused.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 14:45:09 by akaseris          #+#    #+#             */
/*   Updated: 2018/04/21 15:22:12 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_stklen(t_stack *stk)
{
	int i;

	i = 0;
	while (stk)
	{
		i++;
		stk = stk->next;
	}
	return (i);
}

static int	ft_ishalfsort(t_stack *stk, int min, int max)
{
	int gap;

	gap = max - min;
	while (min--)
		stk = stk->next;
	while (gap-- && stk->next)
	{
		if (stk->nb > stk->next->nb)
			return (0);
		stk = stk->next;
	}
	return (1);
}

static void	ft_merge(t_stack **src, t_stack **dst, int piv)
{
	while (piv--)
	{
		if ((*src)->next != NULL && (*src)->nb > (*src)->next->nb)
			ft_stkswap(src, "sa\n");
		ft_stkpush(src, dst, "pb\n");
		if ((*dst)->next != NULL && (*dst)->nb < (*dst)->next->nb)
			ft_stkswap(dst, "sb\n");
	}
	while (*dst)
	{
		ft_stkpush(dst, src, "pa\n");
		if ((*src)->nb > (*src)->next->nb)
			ft_stkswap(src, "sa\n");
	}
}

void		ft_stksort(t_stack **sta, t_stack **stb, int min, int max)
{
	int piv;

	if (max - min < 2 || ft_checksort(*sta, *stb))
		return ;
	piv = (min + max) / 2;
	if (!ft_ishalfsort(*sta, min, piv))
		ft_stksort(sta, stb, min, piv);
	if (!ft_ishalfsort(*sta, piv, max))
		ft_stksort(sta, stb, piv, max);
	ft_merge(sta, stb, min, max, piv);
}
