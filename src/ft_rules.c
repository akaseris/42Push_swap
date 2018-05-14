/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:14:22 by akaseris          #+#    #+#             */
/*   Updated: 2018/05/14 16:39:41 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_checkdup(t_stack *sta)
{
	int		i;
	int		c;
	t_stack	*tmp;
	t_stack	*dup;

	tmp = sta;
	while (sta)
	{
		c = 0;
		i = sta->nb;
		dup = tmp;
		while (dup)
		{
			if (dup->nb == i)
				c++;
			dup = dup->next;
		}
		sta = sta->next;
		if (c > 1)
			return (0);
	}
	return (1);
}

int		ft_validrl(char *str)
{
	char	*rls;
	int		i;

	rls = "sa,sb,ss,pa,pb,ra,rb,rr,rra,rrb,rrr";
	if (ft_strstr(rls, str))
	{
		i = 0;
		while (str[i] != '\0')
		{
			if (str[i] == ',')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int		ft_getrules(t_stack **sta, t_stack **stb)
{
	int		r;
	int i = 1;
	char	*tmp;

	while ((r = get_next_line(0, &tmp)))
	{
		if (r == 2)
		{
			if (!(ft_validrl(tmp)))
				return (0);
			ft_apply(tmp, sta, stb);
			ft_strdel(&tmp);
		}
		else if (r == 1 && tmp[0] != '\0')
		{
			ft_strdel(&tmp);
			return (0);
		}
		if (!(i--))
			while(1);
	}
	return (1);
}

void	ft_apply(char *rule, t_stack **sta, t_stack **stb)
{
	if (ft_strcmp("ss", rule) == 0 || ft_strcmp("sa", rule) == 0)
		ft_stkswap(sta);
	if (ft_strcmp("ss", rule) == 0 || ft_strcmp("sb", rule) == 0)
		ft_stkswap(stb);
	if (ft_strcmp("pa", rule) == 0)
		ft_stkpush(stb, sta);
	if (ft_strcmp("pb", rule) == 0)
		ft_stkpush(sta, stb);
	if (ft_strcmp("rr", rule) == 0 || ft_strcmp("ra", rule) == 0)
		ft_stkrot(sta);
	if (ft_strcmp("rr", rule) == 0 || ft_strcmp("rb", rule) == 0)
		ft_stkrot(stb);
	if (ft_strcmp("rrr", rule) == 0 || ft_strcmp("rra", rule) == 0)
		ft_stkrevrot(sta);
	if (ft_strcmp("rrr", rule) == 0 || ft_strcmp("rrb", rule) == 0)
		ft_stkrevrot(stb);
}
