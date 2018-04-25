/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:36:33 by akaseris          #+#    #+#             */
/*   Updated: 2018/04/25 20:29:38 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
