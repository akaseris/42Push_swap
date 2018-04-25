/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 17:14:06 by akaseris          #+#    #+#             */
/*   Updated: 2018/04/25 20:32:31 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_addlst(t_stack **ntmp, t_stack **stmp, t_stack **sta, char *s)
{
	*stmp = *sta;
	*ntmp = (t_stack*)malloc(sizeof(**ntmp));
	(*ntmp)->nb = ft_atoi(s);
	(*ntmp)->next = NULL;
	if (!(*sta))
		*sta = *ntmp;
	else
	{
		while ((*stmp)->next)
			*stmp = (*stmp)->next;
		(*stmp)->next = *ntmp;
	}
}

int			ft_validinp(char **av)
{
	int		i;
	int		j;
	int		k;
	char	**split;

	i = 1;
	while (av[i])
	{
		k = 0;
		split = ft_strsplit(av[i], ' ');
		while (split[k])
		{
			j = 1;
			if (split[k][0] != '-' && !ft_isdigit(split[k][0]))
				return (0);
			while (ft_isdigit(split[k][j]))
				j++;
			if (split[k][j] != '\0')
				return (0);
			k++;
		}
		i++;
	}
	return (1);
}

int			ft_validrl(char *str)
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

t_stack		*ft_fillsta(t_stack *sta, char **av)
{
	t_stack *ntmp;
	t_stack *stmp;
	char	**split;
	int		i;
	int		j;

	i = 1;
	while (av[i])
	{
		j = 0;
		split = ft_strsplit(av[i], ' ');
		while (split[j])
		{
			ft_addlst(&ntmp, &stmp, &sta, split[j]);
			j++;
		}
		i++;
	}
	return (sta);
}
