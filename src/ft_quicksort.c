/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 13:53:43 by akaseris          #+#    #+#             */
/*   Updated: 2018/05/09 17:28:47 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_stkpivnext(t_stack *stk, int piv)
{
	int i;
	int j;
	int c;

	i = 0;
	c = 0;
	j = ft_stklen(stk) / 2;
	while (stk)
	{
		if (stk->nb <= piv)
		{
			c = i + 1;
			break ;
		}
		i++;
		stk = stk->next;
	}
	piv = (c > j + 1) ? 2 : 1;
	return ((c) ? piv : 0);
}

static char	*ft_pushhalf(t_stack **src, t_stack **dst, int piv)
{
	int		c;
	char	*str;

	str = ft_strnew(0);
	while ((c = ft_stkpivnext(*src, piv)))
	{
		if ((*src)->nb <= piv)
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

char		*ft_stksort(t_stack **sta, t_stack **stb, int step)
{
	int		piv;
	char	*str;
	char	*tmp;

	str = ft_strnew(0);
	while ((*sta)->next && !ft_checksort(*sta, NULL))
	{
		piv = ft_pivot((*sta), step);
		tmp = ft_pushhalf(sta, stb, piv);
		str = ft_strjoinfree(str, str, tmp);
		free(tmp);
	}
	tmp = ft_stkcustomsort(sta, stb);
	str = ft_strjoinfree(str, str, tmp);
	free(tmp);
	return (str);
}
