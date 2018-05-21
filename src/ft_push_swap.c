/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:36:54 by akaseris          #+#    #+#             */
/*   Updated: 2018/05/21 15:49:57 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free(t_stack **sta, t_stack **stb)
{
	t_stack	*tmp;

	while (*sta)
	{
		tmp = (*sta)->next;
		free(*sta);
		*sta = tmp;
	}
	while (*stb)
	{
		tmp = (*stb)->next;
		free(*stb);
		*stb = tmp;
	}
}

static void	ft_initlist(t_stack **sta, t_stack **stb, char **av)
{
	ft_free(sta, stb);
	*sta = NULL;
	*stb = NULL;
	*sta = ft_fillsta(*sta, av);
}

static int	ft_checkinit(t_stack **sta, t_stack **stb, char **av, char **flags)
{
	if ((*sta == NULL || !ft_checkdup(*sta)) && !ft_strchr(*flags, 'u'))
	{
		ft_printf("Error\n");
		ft_free(sta, stb);
		ft_strdel(flags);
		return (0);
	}
	if (ft_strchr(*flags, 'u'))
	{
		ft_free(sta, stb);
		ft_strdel(flags);
		ft_printusage();
		return (0);
	}
	if (ft_checksort(*sta, *stb))
	{
		ft_printres(*sta, av, "", *flags);
		ft_free(sta, stb);
		ft_strdel(flags);
		return (0);
	}
	return (1);
}

static void	ft_stkprocess(char **av, char *flags, t_stack **sta, t_stack **stb)
{
	char	*str;
	char	*prev;
	int		inc;
	int		step;
	int		max;

	inc = ft_stksum(*sta);
	step = inc;
	max = ft_stkdif(*sta, inc);
	prev = ft_stksort(sta, stb, step);
	while (step <= max)
	{
		ft_initlist(sta, stb, av);
		str = ft_stksort(sta, stb, step);
		step = step + inc;
		if (ft_strlen(str) < ft_strlen(prev))
		{
			free(prev);
			prev = ft_strdup(str);
		}
		free(str);
	}
	ft_printres(*sta, av, prev, flags);
	free(prev);
}

int			main(int ac, char **av)
{
	t_stack	*sta;
	t_stack	*stb;
	char	*flags;

	av++;
	ft_initlist(&sta, &stb, av);
	if ((!ft_validinp(av) || !ft_checkdup(sta) || !(flags = ft_flags(av)))
		&& ac > 1)
	{
		ft_free(&sta, &stb);
		ft_strdel(&flags);
		return (ft_printf("Error\n"));
	}
	if (ac > 1 && !ft_checkinit(&sta, &stb, av, &flags))
		return (0);
	if (ac < 2)
		return (0);
	if (ft_stklen(sta) < 6)
		ft_smallsort(&sta, &stb, av, flags);
	else
		ft_stkprocess(av, flags, &sta, &stb);
	ft_free(&sta, &stb);
	ft_strdel(&flags);
	return (0);
}
