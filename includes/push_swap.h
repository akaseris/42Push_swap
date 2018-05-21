/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:46:25 by akaseris          #+#    #+#             */
/*   Updated: 2018/05/21 15:46:17 by akaseris         ###   ########.fr       */
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

int				ft_validinp(char **av);
int				ft_validrl(char *str);
int				ft_checkdup(t_stack *sta);
int				ft_over(char *str);
t_stack			*ft_fillsta(t_stack *sta, char **av);
int				ft_getrules(t_stack **sta, t_stack **stb);
void			ft_apply(char *rule, t_stack **sta, t_stack **stb);
void			ft_stkswap(t_stack **stk);
void			ft_stkpush(t_stack **src, t_stack **dst);
void			ft_stkrot(t_stack **stk);
void			ft_stkrevrot(t_stack **stk);
int				ft_checksort(t_stack *sta, t_stack *stb);
char			*ft_stksort(t_stack **sta, t_stack **stb, int step);
char			*ft_stkcustomsort(t_stack **sta, t_stack **stb);
void			ft_smallsort(t_stack **sta, t_stack **stb, char **av,
					char *flags);
int				ft_pivot(t_stack *stk, int step);
int				ft_stklen(t_stack *stk);
int				ft_stksum(t_stack *stk);
int				ft_stkdif(t_stack *stk, int inc);
char			*ft_flags(char **av);
int				ft_validflag(char *split, char **str);
char			*ft_color(char *s);
void			ft_printres(t_stack *sta, char **av, char *moves, char *flags);
void			ft_printusage(void);

#endif
