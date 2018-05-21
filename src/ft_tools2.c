/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 15:55:11 by akaseris          #+#    #+#             */
/*   Updated: 2018/05/20 17:41:34 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_validflag(char *split, char **str)
{
	int j;

	j = 1;
	while (split[j] != '\0')
	{
		if (split[0] == '-' && ft_strchr("cvluh", split[j]))
			*str = ft_strjoinfree(*str, *str, &split[j]);
		if (!ft_strchr("cvluh", split[j]) && !ft_isdigit(split[j]))
			return (0);
		j++;
	}
	return (1);
}

int		ft_over(char *s)
{
	int				i;
	long long int	nb;
	char			*tmp;

	i = (ft_strchr("+-", s[0])) ? 1 : 0;
	if (!ft_isdigit(s[1]))
		return (1);
	while (s[i] == '0')
		i++;
	if (s[i] == '\0')
		return (1);
	nb = ft_atoli(s + i);
	tmp = ft_itoa_base(nb, 10);
	nb = (s[0] == '-') ? -nb : nb;
	if (ft_strlen(s + i) != ft_strlen(tmp) || nb < -2147483648
		|| nb > 2147483647)
	{
		ft_strdel(&tmp);
		return (0);
	}
	ft_strdel(&tmp);
	return (1);
}

int		ft_checkdup(t_stack *sta)
{
	int		i;
	int		c;
	t_stack	*tmp;
	t_stack	*dup;

	tmp = sta;
	while (sta)
	{
		c = 0;
		i = sta->nb;
		dup = tmp;
		while (dup)
		{
			if (dup->nb == i)
				c++;
			dup = dup->next;
		}
		sta = sta->next;
		if (c > 1)
			return (0);
	}
	return (1);
}
