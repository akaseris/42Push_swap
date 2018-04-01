/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:46:25 by akaseris          #+#    #+#             */
/*   Updated: 2018/04/01 21:03:02 by akaseris         ###   ########.fr       */
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
void			ft_stkswap(t_stack **stk, char *s);
void			ft_stkpush(t_stack **src, t_stack **dst, char *s);
void			ft_stkrot(t_stack **stk, char *s);
void			ft_stkrevrot(t_stack **stk, char *s);
int				ft_checksort(t_stack *sta, t_stack *stb);
void			ft_stksort(t_stack **sta, t_stack **stb, int min, int max);
int     		ft_stknext(t_stack *stk, int min, int max);
void			ft_pivot(t_stack *stk, int *min, int *max);
void			ft_pushhalf(t_stack **src, t_stack **dst, int min, int max);
int				ft_ishalfsort(t_stack *stk, int piv, int side);


void			ft_print(t_stack *sta);

#endif
