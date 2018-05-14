/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_customsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:00:36 by akaseris          #+#    #+#             */
/*   Updated: 2018/05/03 15:44:47 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_stkminnext(t_stack *stk, int *ind)
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
	if (c == 1)
		return (2);
	return ((c <= j) ? 1 : 0);
}

static void	ft_move(t_stack **stb, int pos, char **str)
{
	if (pos == 1)
	{
		ft_stkrot(stb);
		*str = ft_strjoinfree(*str, *str, "rb\n");
	}
	else if (pos == 2)
	{
		ft_stkswap(stb);
		*str = ft_strjoinfree(*str, *str, "sb\n");
	}
	else
	{
		ft_stkrevrot(stb);
		*str = ft_strjoinfree(*str, *str, "rrb\n");
	}
}

char		*ft_stkcustomsort(t_stack **sta, t_stack **stb)
{
	int		ind;
	int		pos;
	char	*str;

	str = ft_strnew(0);
	while ((*stb))
	{
		pos = ft_stkminnext(*stb, &ind);
		while ((*stb)->nb != ind)
			ft_move(stb, pos, &str);
		ft_stkpush(stb, sta);
		str = ft_strjoinfree(str, str, "pa\n");
	}
	return (str);
}
