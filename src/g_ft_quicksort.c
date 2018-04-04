/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_ft_quicksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:53:43 by akaseris          #+#    #+#             */
/*   Updated: 2018/04/03 17:36:09 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_ishalfsort(t_stack *stk, int piv, int side)
{
	if (side)
	{
		while (stk->nb < piv)
			stk = stk->next;
		while (stk->next)
		{
			if (stk->nb > stk->next->nb)
				return (0);
			stk = stk->next;
		}
	}
	else
	{
		while (stk->nb < piv)
		{
			if (stk->nb > stk->next->nb)
				return (0);
			stk = stk->next;
		}
	}
	return (1);
}

int		ft_stknext(t_stack *stk, int min, int max)
{
	int piv;
	int c;
	int i;
	int j;

	piv = (min + max) / 2;
	c = 0;
	i = 0;
	j = 0;
	while (stk)
	{
		if (!c)
		{
			if (stk->nb < piv)
				c = 1;
			i++;
		}
		else
			j++;
		stk = stk->next;
	}
	piv = (i > j) ? 2 : 1;
	return ((c) ? piv : 0);
}

void	ft_pivot(t_stack *stk, int *min, int *max)
{
	*min = 0;
	*max = 0;
	while (stk)
	{
		*min = (stk->nb < *min) ? stk->nb : *min;
		*max = (stk->nb > *max) ? stk->nb : *max;
		stk = stk->next;
	}
}

void	ft_pushhalf(t_stack **src, t_stack **dst, int min, int max)
{
	int		piv;
	int		c;

	piv = (min + max) / 2;
	while ((c = ft_stknext(*src, min, max)))
	{
		if ((*src)->nb < piv)
		{
			if ((*src)->next != NULL && (*src)->nb > (*src)->next->nb
				&& (*src)->next->nb < piv)
				ft_stkswap(src, "sa\n");
			ft_stkpush(src, dst, "pb\n");
			if ((*dst)->next != NULL && (*dst)->nb < (*dst)->next->nb)
				ft_stkswap(dst, "sb\n");
		}
		else if (c == 1)
			ft_stkrot(src, "ra\n");
		else
			ft_stkrevrot(src, "rra\n");
	}
}

void	ft_stksort(t_stack **sta, t_stack **stb, int min, int max)
{
	int		piv;

	piv = (min + max) / 2;
	if (piv == min + 1 || piv == max - 1)
		return ;
	if (!ft_ishalfsort(*sta, piv, 0))
		ft_stksort(sta, stb, min, piv);
	if (!ft_ishalfsort(*sta, piv, 1))
		ft_stksort(sta, stb, piv, max);
	ft_pushhalf(sta, stb, min, max);
	while (*stb)
	{
		if ((*stb)->next != NULL && (*stb)->nb < (*stb)->next->nb)
			ft_stkswap(stb, "sb\n");
		ft_stkpush(stb, sta, "pa\n");
	}
}
