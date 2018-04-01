/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_ft_bubblesort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 18:00:36 by akaseris          #+#    #+#             */
/*   Updated: 2018/04/01 18:43:46 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int     ft_stklen(t_stack *stk)
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

void			ft_stksort(t_stack **sta, t_stack **stb)
{
	int		c;
	int		i;

	c = ft_stklen((*sta));
	i = 0;
    str = ft_strnew(0);
	while (i < c)
	{
		if ((*sta)->nb > (*sta)->next->nb)
			ft_stkswap(sta, "sa\n");
		ft_stkrot(sta, "ra\n");
		i++;
		if (i == c - 1)
		{
			ft_stkrot(sta, "ra\n");
			if (ft_checksort((*sta), (*stb)) == 0)
				i = 0;
			else
				i = c;
		}
	}
    ft_putstr(str);
}
