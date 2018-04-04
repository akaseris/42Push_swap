/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:00:36 by akaseris          #+#    #+#             */
/*   Updated: 2018/04/03 18:09:23 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_stklen(t_stack *stk)
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

int		ft_stknext(t_stack *stk, int *ind)
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

void	ft_stksort(t_stack **sta, t_stack **stb)
{
	int i;
	int ind;

	i = 0;
	while ((*sta))
		ft_stkpush(sta, stb, "pb\n");
	while ((*stb))
	{
		if (ft_stknext(*stb, &ind))
		{
			while ((*stb)->nb != ind)
				ft_stkrot(stb, "rb\n");
		}
		else
		{
			while ((*stb)->nb != ind)
				ft_stkrevrot(stb, "rrb\n");
		}
		ft_stkpush(stb, sta, "pa\n");
	}
}
