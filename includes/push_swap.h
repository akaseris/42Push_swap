/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:46:25 by akaseris          #+#    #+#             */
/*   Updated: 2018/04/19 21:30:22 by akaseris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/includes/libft.h"

typedef struct	s_stack
{
	int				nb;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_rule
{
	char			*s;
	struct s_rule	*next;
}				t_rule;

int				ft_validinp(char **av);
int				ft_validrl(char *str);
t_stack			*ft_fillsta(t_stack *sta, char **av);
t_rule			*ft_addrule(t_rule *srule, char *str);
void			ft_apply(t_rule *srule, t_stack **sta, t_stack **stb);
void			ft_stkswap(t_stack **stk);
void			ft_stkpush(t_stack **src, t_stack **dst);
void			ft_stkrot(t_stack **stk);
void			ft_stkrevrot(t_stack **stk);
int				ft_checksort(t_stack *sta, t_stack *stb);
char			*ft_stksort(t_stack **sta, t_stack **stb, int step);
char			*ft_stkcustomsort(t_stack **sta, t_stack **stb);
void			ft_print(t_stack *sta);

#endif
