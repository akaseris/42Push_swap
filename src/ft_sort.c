/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:00:36 by akaseris          #+#    #+#             */
/*   Updated: 2018/04/01 21:03:01 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_ishalfsort(t_stack *stk, int piv, int side)
{
	t_stack *tmp;

	tmp = stk;
	while (stk->nb <= max && stk->next != NULL)
	{
		if (stk->nb >= min)
		{
			if (stk->nb > stk->next->nb)
				return (0);
		}
		stk = stk->next;
	}
	ft_printf("\n%d   ,   %d\n", min, max);
	ft_print(tmp);
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
	return ((c) ? ((i > j) ? 2 : 1) : 0);
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

void    ft_pushhalf(t_stack **src, t_stack **dst, int min, int max)
{
	int		piv;
	int		c;

	piv = (min + max) / 2;
	while ((c = ft_stknext(*src, min, max)))
	{
		if ((*src)->nb < piv)
		{
			if ((*src)->nb > (*src)->next->nb && (*src)->next->nb < piv)
				ft_stkswap(src, "sa\n");
			ft_stkpush(src, dst, "pb\n");
		}
		else if (c == 1)
			ft_stkrot(src, "ra\n");
		else
			ft_stkrevrot(src, "rra\n");
	}/*
	ft_printf("\n**%d**\n", piv);
	ft_print(*src);
	ft_printf("\n-----------------------------%d-------------------------------------", c);*/
}

void		ft_stksort(t_stack **sta, t_stack **stb, int min, int max)
{
	int		piv;

	piv = (min + max) / 2;
	ft_pushhalf(sta, stb, min, max);
	while (*stb)
		ft_stkpush(stb, sta, "pa\n");
	if (piv == min + 1 || piv == max - 1)
		return ;
	if (!ft_ishalfsort(*sta, min, piv))
		ft_stksort(sta, stb, min, piv);
	if (!ft_ishalfsort(*sta, piv, max))
		ft_stksort(sta, stb, piv, max);
}
