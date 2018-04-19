/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:36:54 by akaseris          #+#    #+#             */
/*   Updated: 2018/04/19 21:12:33 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_initlist(t_stack **sta, t_stack **stb, char **av)
{
	*sta = NULL;
	*sta = ft_fillsta(*sta, av);
	*stb = NULL;
}

int			main(int ac, char **av)
{
	t_stack	*sta;
	t_stack	*stb;
	char	*str;
	char	*prev;
	int		step;

	if (ac < 2 || !ft_validinp(av))
		return (ft_printf("Error\n"));
	step = 20;
	ft_initlist(&sta, &stb, av);
	prev = ft_stksort(&sta, &stb, step);
	while (step < 350)
	{
		ft_initlist(&sta, &stb, av);
		str = ft_stksort(&sta, &stb, step);
		step = step + 20;
		if (ft_strlen(str) < ft_strlen(prev))
		{
			free(prev);
			prev = ft_strdup(str);
			free(str);
		}
	}
	ft_putstr(prev);
	return (0);
}
