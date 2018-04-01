/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:36:33 by akaseris          #+#    #+#             */
/*   Updated: 2018/04/01 13:54:28 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_rule	*ft_getrules(t_rule *srule)
{
	int		r;
	char	*tmp;

	while ((r = get_next_line(0, &tmp)))
	{
		if (r == 2)
		{
			if (!(srule = ft_addrule(srule, tmp)) || !(ft_validrl(tmp)))
				return (NULL);
			free(tmp);
		}
		else if (tmp[0] != '\0')
			return (NULL);
	}
	return (srule);
}

int				main(int ac, char **av)
{
	t_rule	*srule;
	t_stack	*sta;
	t_stack	*stb;

	if (ac < 2 || !ft_validinp(av))
		return (ft_printf("Error\n"));
	srule = NULL;
	if (!(srule = ft_getrules(srule)))
		return (ft_printf("Error\n"));
	sta = NULL;
	stb = NULL;
	sta = ft_fillsta(sta, av);
	ft_apply(srule, &sta, &stb);
	(ft_checksort(sta, stb)) ? ft_printf("OK\n") : ft_printf("KO\n");
	return (0);
}
