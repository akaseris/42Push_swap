/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:47:54 by akaseris          #+#    #+#             */
/*   Updated: 2018/05/21 15:46:19 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_printmoves(char *moves, char *flags)
{
	char	*tmp;
	char	*col;
	int		i;

	i = 0;
	while ((tmp = ft_strchr(moves, '\n')))
	{
		*tmp++ = '\0';
		col = (ft_strchr(flags, 'c')) ? ft_strjoin(ft_color(moves), moves)
				: ft_strdup(moves);
		col = (ft_strchr(flags, 'c')) ? ft_strjoinfree(col, col, "\033[0m")
				: col;
		if (!ft_strchr(flags, 'h'))
			ft_printf("%s\n", col);
		i++;
		moves = tmp;
		free(col);
	}
	return (i);
}

static void	ft_printstacks(t_stack *stainit, t_stack *sta)
{
	ft_printf("\033[1;32mstack A before:\t\t\tstack A after:\033[0m\n");
	while (sta)
	{
		ft_printf("%d\t\t\t\t%d\n", stainit->nb, sta->nb);
		stainit = stainit->next;
		sta = sta->next;
	}
}

void		ft_printusage(void)
{
	ft_printf("Usage:\n./push_swap \"50 40 60\" OR ./checker \"50 40 60\"\n");
	ft_printf("flags allowed: [-c (colored moves)] [-v (view stacks)]");
	ft_printf("[-l (moves count)]\n\t\t[-h (hide moves)] [-u (view usage)]\n");
	ft_printf("Combined use:\n./push_swap \"50 40 60\" | ");
	ft_printf("./checker \"50 40 60\"\n(flags use with");
	ft_printf(" pipe to other executables leads to undefined behaviour)\n");
}

void		ft_printres(t_stack *sta, char **av, char *moves, char *flags)
{
	int		i;
	t_stack *tmp;
	t_stack	*stainit;

	if (ft_strchr(flags, 'u'))
	{
		ft_printusage();
		return ;
	}
	stainit = NULL;
	i = ft_printmoves(moves, flags);
	stainit = ft_fillsta(stainit, av);
	if (ft_strchr(flags, 'v'))
		ft_printstacks(stainit, sta);
	if (ft_strchr(flags, 'l'))
		ft_printf("\033[1;32mTotal moves:\033[0m\t%d\n", i);
	while (stainit)
	{
		tmp = (stainit)->next;
		free(stainit);
		stainit = tmp;
	}
}
