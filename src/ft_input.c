/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 17:14:06 by akaseris          #+#    #+#             */
/*   Updated: 2018/05/20 17:25:15 by akaseris         ###   ########.fr       */
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

static int	ft_checkarg(char *s)
{
	int		j;

	j = 1;
	if ((!ft_strchr("+-", s[0]) && !ft_isdigit(s[0])) ||
		(ft_strchr("+-", s[0]) && s[1] == '\0') || !ft_over(s))
		return (0);
	while (ft_isdigit(s[j]))
		j++;
	if (s[j] != '\0' && j != 1)
		return (0);
	while (!ft_isdigit(s[j]) && s[j] != '\0')
		j++;
	if (s[j] != '\0' && j != 1)
		return (0);
	return (1);
}

int			ft_validinp(char **av)
{
	int		k;
	int		e;
	char	**split;

	e = 0;
	while (*av)
	{
		split = ft_strsplit(*av, ' ');
		k = 0;
		while (split && split[k])
		{
			if (!ft_checkarg(split[k]))
			{
				ft_deltab(split);
				return (0);
			}
			k++;
		}
		e = (k != 0) ? 1 : e;
		ft_deltab(split);
		av++;
	}
	return ((e) ? 1 : 0);
}

char		*ft_flags(char **av)
{
	char	*str;
	int		k;
	char	**split;

	str = ft_strnew(0);
	while (*av)
	{
		split = ft_strsplit(*av, ' ');
		k = 0;
		while (split && split[k])
		{
			if (!ft_validflag(split[k], &str))
			{
				ft_strdel(&str);
				ft_deltab(split);
				return (NULL);
			}
			k++;
		}
		av++;
		ft_deltab(split);
	}
	return (str);
}

t_stack		*ft_fillsta(t_stack *sta, char **av)
{
	t_stack *ntmp;
	t_stack *stmp;
	char	**split;
	int		i;
	int		j;

	i = 0;
	while (av[i])
	{
		j = 0;
		split = ft_strsplit(av[i], ' ');
		while (split && split[j])
		{
			if (!(split[j][0] == '-' && !ft_isdigit(split[j][1])))
				ft_addlst(&ntmp, &stmp, &sta, split[j]);
			j++;
		}
		i++;
		ft_deltab(split);
	}
	return (sta);
}
