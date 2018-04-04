/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 16:36:54 by akaseris          #+#    #+#             */
/*   Updated: 2018/04/03 17:42:37 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_stack	*sta;
	t_stack	*stb;
	//int	len;

	if (ac < 2 || !ft_validinp(av))
		return (ft_printf("Error\n"));
	sta = NULL;
	stb = NULL;
	sta = ft_fillsta(sta, av);
	//len = ft_stklen(sta);
	ft_stksort(&sta, &stb);
	//ft_print(sta);
	return (0);
}
