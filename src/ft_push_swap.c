/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:36:54 by akaseris          #+#    #+#             */
/*   Updated: 2018/05/14 15:00:53 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_initlist(t_stack **sta, t_stack **stb, char **av)
{
	t_stack *tmp;

	while (*sta)
	{
		tmp = (*sta)->next;
		free(*sta);
		*sta = tmp;
	}
	*sta = NULL;
	*sta = ft_fillsta(*sta, av);
	*stb = NULL;
}

static int	ft_checkinit(t_stack *sta, t_stack *stb)
{
	if (sta == NULL || !ft_checkdup(sta))
	{
		ft_printf("Error\n");
		return (0);
	}
	if (ft_checksort(sta, stb))
		return (0);
	return (1);
}

static void	ft_stkprocess(char **av, char *flags, t_stack **sta, t_stack **stb)
{
	char	*str;
	char	*prev;
	int		inc;
	int		step;
	int		max;

	step = 0;
	inc = ft_stksum(*sta);
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
	if (ac < 2)
		return (0);
	flags = ft_flags(av);
	ft_initlist(&sta, &stb, av);
	if (!ft_validinp(av) || !ft_checkdup(sta))
		return (ft_printf("Error\n"));
	if (!ft_checkinit(sta, stb))
		return (0);
	ft_stkprocess(av, flags, &sta, &stb);
	return (0);
}
