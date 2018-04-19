/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_ft_customsort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:00:36 by akaseris          #+#    #+#             */
/*   Updated: 2018/04/19 21:30:19 by akaseris         ###   ########.fr       */
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

static int	ft_stkisnext(t_stack *stk, int *ind)
{
	int i;
	int j;
	int c;

	i = 0;
	c = 0;
	j = ft_stklen(stk) / 2;
	*ind = stk->nb;
	while (stk)
	{
		if (*ind < stk->nb)
		{
			*ind = stk->nb;
			c = i;
		}
		i++;
		stk = stk->next;
	}
	return ((c <= j) ? 1 : 0);
}

char		*ft_stkcustomsort(t_stack **sta, t_stack **stb)
{
	int		ind;
	int		pos;
	char	*str;

	str = ft_strnew(0);
	while ((*stb))
	{
		pos = ft_stkisnext(*stb, &ind);
		while ((*stb)->nb != ind)
		{
			if (pos)
			{
				ft_stkrot(stb);
				str = ft_strjoinfree(str, str, "rb\n");
			}
			else
			{
				ft_stkrevrot(stb);
				str = ft_strjoinfree(str, str, "rrb\n");
			}
		}
		ft_stkpush(stb, sta);
		str = ft_strjoinfree(str, str, "pa\n");
	}
	return (str);
}
