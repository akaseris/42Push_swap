/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:36:33 by akaseris          #+#    #+#             */
/*   Updated: 2018/05/20 16:05:31 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_free(t_stack **sta)
{
	t_stack	*tmp;

	while (*sta)
	{
		tmp = (*sta)->next;
		free(*sta);
		*sta = tmp;
	}
}

int			main(int ac, char **av)
{
	t_stack	*sta;
	t_stack	*stb;
	char	*flags;

	av++;
	if (ac < 2)
		return (0);
	sta = NULL;
	stb = NULL;
	sta = ft_fillsta(sta, av);
	flags = ft_flags(av);
	if (!ft_validinp(av) || !ft_checkdup(sta) || !flags || flags[0] != '\0'
		|| !ft_getrules(&sta, &stb))
	{
		ft_strdel(&flags);
		ft_free(&sta);
		return (ft_printf("Error\n"));
	}
	(ft_checksort(sta, stb)) ? ft_printf("OK\n") : ft_printf("KO\n");
	ft_free(&sta);
	ft_strdel(&flags);
	return (0);
}
