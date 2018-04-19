/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 14:14:22 by akaseris          #+#    #+#             */
/*   Updated: 2018/04/19 15:09:49 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_rule	*ft_addrule(t_rule *srule, char *str)
{
	t_rule *ntmp;
	t_rule *stmp;

	stmp = srule;
	ntmp = (t_rule*)malloc(sizeof(*ntmp));
	ntmp->s = ft_strdup(str);
	ntmp->next = NULL;
	if (!srule)
		srule = ntmp;
	else
	{
		while (stmp->next)
			stmp = stmp->next;
		stmp->next = ntmp;
	}
	return (srule);
}

void	ft_apply(t_rule *srule, t_stack **sta, t_stack **stb)
{
	while (srule)
	{
		if (ft_strcmp("ss", srule->s) == 0 || ft_strcmp("sa", srule->s) == 0)
			ft_stkswap(sta);
		if (ft_strcmp("ss", srule->s) == 0 || ft_strcmp("sb", srule->s) == 0)
			ft_stkswap(stb);
		if (ft_strcmp("pa", srule->s) == 0)
			ft_stkpush(stb, sta);
		if (ft_strcmp("pb", srule->s) == 0)
			ft_stkpush(sta, stb);
		if (ft_strcmp("rr", srule->s) == 0 || ft_strcmp("ra", srule->s) == 0)
			ft_stkrot(sta);
		if (ft_strcmp("rr", srule->s) == 0 || ft_strcmp("rb", srule->s) == 0)
			ft_stkrot(stb);
		if (ft_strcmp("rrr", srule->s) == 0 || ft_strcmp("rra", srule->s) == 0)
			ft_stkrevrot(sta);
		if (ft_strcmp("rrr", srule->s) == 0 || ft_strcmp("rrb", srule->s) == 0)
			ft_stkrevrot(stb);
		srule = srule->next;
	}
}

int		ft_checksort(t_stack *sta, t_stack *stb)
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
