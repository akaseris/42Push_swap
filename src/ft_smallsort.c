/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_smallsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:44:03 by akaseris          #+#    #+#             */
/*   Updated: 2018/05/21 14:29:48 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_getmin(t_stack *stk, int *ind)
{
	int		min;
	int		i;

	min = stk->nb;
	i = 0;
	while (stk)
	{
		if (min > stk->nb)
		{
			min = stk->nb;
			*ind = i;
		}
		i++;
		stk = stk->next;
	}
	return (min);
}

static void	ft_pushmin(t_stack **sta, t_stack **stb, char **str)
{
	int		ind;
	int		min;

	min = ft_getmin(*sta, &ind);
	while ((*sta)->nb != min)
	{
		if (ind < 2)
		{
			ft_stkrot(sta);
			*str = ft_strjoinfree(*str, *str, "ra\n");
		}
		else
		{
			ft_stkrevrot(sta);
			*str = ft_strjoinfree(*str, *str, "rra\n");
		}
	}
	ft_stkpush(sta, stb);
	*str = ft_strjoinfree(*str, *str, "pb\n");
}

static void	ft_three(t_stack **sta, char **str)
{
	if ((*sta)->nb > (*sta)->next->nb)
	{
		ft_stkswap(sta);
		*str = ft_strjoinfree(*str, *str, "sa\n");
	}
	if ((*sta)->next->next->nb < (*sta)->nb ||
		(*sta)->next->next->nb < (*sta)->next->nb)
	{
		ft_stkrevrot(sta);
		*str = ft_strjoinfree(*str, *str, "rra\n");
	}
	if ((*sta)->nb > (*sta)->next->nb)
	{
		ft_stkswap(sta);
		*str = ft_strjoinfree(*str, *str, "sa\n");
	}
}

static void	ft_two(t_stack **sta, char **str)
{
	if ((*sta)->nb > (*sta)->next->nb)
	{
		ft_stkswap(sta);
		*str = ft_strjoinfree(*str, *str, "sa\n");
	}
}

void		ft_smallsort(t_stack **sta, t_stack **stb, char **av, char *flags)
{
	char	*str;
	int		i;

	i = 2;
	str = ft_strnew(0);
	while (!ft_checksort(*sta, NULL))
	{
		if (ft_stklen(*sta) > 3)
		{
			while (i--)
				ft_pushmin(sta, stb, &str);
		}
		if (ft_stklen(*sta) == 3)
			ft_three(sta, &str);
		if (ft_stklen(*sta) == 2)
			ft_two(sta, &str);
	}
	while (*stb)
	{
		ft_stkpush(stb, sta);
		str = ft_strjoinfree(str, str, "pa\n");
	}
	ft_printres(*sta, av, str, flags);
	ft_strdel(&str);
}
