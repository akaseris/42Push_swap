/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:53:43 by akaseris          #+#    #+#             */
/*   Updated: 2018/04/19 21:14:36 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_stknext(t_stack *stk, int piv)
{
	int c;
	int i;
	int j;

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

static int	ft_pivot(t_stack *stk, int step)
{
	int min;
	int max;
	int piv;

	min = stk->nb;
	max = stk->nb;
	while (stk)
	{
		min = (stk->nb < min) ? stk->nb : min;
		max = (stk->nb > max) ? stk->nb : max;
		stk = stk->next;
	}
	piv = (max - min > step) ? min + step : (min + max) / 2;
	return (piv);
}

static char	*ft_pushhalf(t_stack **src, t_stack **dst, int piv)
{
	int		c;
	char	*str;

	str = ft_strnew(0);
	while ((c = ft_stknext(*src, piv)))
	{
		if ((*src)->nb < piv)
		{
			ft_stkpush(src, dst);
			str = ft_strjoinfree(str, str, "pb\n");
		}
		else if (c == 1)
		{
			ft_stkrot(src);
			str = ft_strjoinfree(str, str, "ra\n");
		}
		else
		{
			ft_stkrevrot(src);
			str = ft_strjoinfree(str, str, "rra\n");
		}
	}
	return (str);
}

char	*ft_stksort(t_stack **sta, t_stack **stb, int step)
{
	int		piv;
	char	*str;

	str = ft_strnew(0);
	while ((*sta)->next)
	{
		piv = ft_pivot((*sta), step);
		str = ft_strjoinfree(str, str, ft_pushhalf(sta, stb, piv));
	}
	str = ft_strjoinfree(str, str, ft_stkcustomsort(sta, stb));
	return (str);
}
