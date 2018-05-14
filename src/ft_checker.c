/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:36:33 by akaseris          #+#    #+#             */
/*   Updated: 2018/05/14 16:36:55 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack *sta)
{
	t_stack	*stb;

	while (sta)
	{
		stb = sta;
		sta = sta->next;
		free(stb);
	}
}

int		main(int ac, char **av)
{
	t_stack	*sta;
	t_stack	*stb;

	av++;
	if (ac < 2)
		return (0);
	sta = NULL;
	stb = NULL;
	sta = ft_fillsta(sta, av);
	if (!ft_validinp(av) || !ft_checkdup(sta) || !ft_getrules(&sta, &stb))
		return (ft_printf("Error\n"));
	(ft_checksort(sta, stb)) ? ft_printf("OK\n") : ft_printf("KO\n");
	ft_free(sta);
	return (0);
}
