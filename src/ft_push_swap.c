/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:36:54 by akaseris          #+#    #+#             */
/*   Updated: 2018/04/25 20:32:48 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_initlist(t_stack **sta, t_stack **stb, char **av)
{
	*sta = NULL;
	*sta = ft_fillsta(*sta, av);
	*stb = NULL;
}

static void	ft_stkprocess(char **av, int step, int max)
{
	t_stack	*sta;
	t_stack	*stb;
	char	*str;
	char	*prev;
	int		inc;

	ft_initlist(&sta, &stb, av);
	inc = ft_stksum(sta);
	max = ft_stkdif(sta, inc);
	prev = ft_stksort(&sta, &stb, step);
	while (step <= max)
	{
		ft_initlist(&sta, &stb, av);
		str = ft_stksort(&sta, &stb, step);
		step = step + inc;
		if (ft_strlen(str) < ft_strlen(prev))
		{
			free(prev);
			prev = ft_strdup(str);
			free(str);
		}
	}
	ft_putstr(prev);
}

int			main(int ac, char **av)
{
	int step;
	int max;

	if (ac < 2 || !ft_validinp(av))
		return (ft_printf("Error\n"));
	step = 0;
	max = 0;
	ft_stkprocess(av, step, max);
	return (0);
}
