/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validinp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 17:14:06 by akaseris          #+#    #+#             */
/*   Updated: 2018/04/01 14:10:15 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_validinp(char **av)
{
	int i;
	int j;

	i = 1;
	while (av[i])
	{
		j = 1;
		if (av[i][0] != '-' && !ft_isdigit(av[i][0]))
			return (0);
		while (ft_isdigit(av[i][j]))
			j++;
		if (av[i][j] != '\0')
			return (0);
		i++;
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

t_stack	*ft_fillsta(t_stack *sta, char **av)
{
	t_stack *ntmp;
	t_stack *stmp;
	int		i;

	i = 1;
	while (av[i])
	{
		stmp = sta;
		ntmp = (t_stack*)malloc(sizeof(*ntmp));
		ntmp->nb = ft_atoi(av[i]);
		ntmp->next = NULL;
		if (!sta)
			sta = ntmp;
		else
		{
			while (stmp->next)
				stmp = stmp->next;
			stmp->next = ntmp;
		}
		i++;
	}
	return (sta);
}
