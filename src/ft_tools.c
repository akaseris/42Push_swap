/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 18:18:55 by akaseris          #+#    #+#             */
/*   Updated: 2018/04/25 20:34:07 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stklen(t_stack *stk)
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

int	ft_stkdif(t_stack *stk, int inc)
{
	int i;
	int j;

	i = stk->nb;
	j = stk->nb;
	while (stk)
	{
		i = (i > stk->nb) ? stk->nb : i;
		j = (j < stk->nb) ? stk->nb : j;
		stk = stk->next;
	}
	return (j + inc);
}

int	ft_stksum(t_stack *stk)
{
	int sum;
	int total;
	int count;

	sum = 0;
	count = 0;
	total = 0;
	while (stk->next)
	{
		sum = (stk->nb + stk->next->nb) / 2;
		sum = (sum < 0) ? -sum : sum;
		total = total + sum;
		count++;
		stk = stk->next;
	}
	return ((total / count) / 4);
}

int	ft_pivot(t_stack *stk, int step)
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

int	ft_checksort(t_stack *sta, t_stack *stb)
{
	if (stb != NULL)
		return (0);
	while (sta->next)
	{
		if (sta->nb > sta->next->nb)
			return (0);
		sta = sta->next;
	}
	return (1);
}
