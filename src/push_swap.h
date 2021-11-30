/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:17:42 by dabel-co          #+#    #+#             */
/*   Updated: 2021/11/30 14:43:54 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../Libft/src/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_param
{
	int		min;
	int		max;
	int		step;
	int		rest;
	int		last;
	int		progress;
}				t_param;


void	checking(t_list **a, t_list **b);
void	ft_swap(t_list **a, t_list **b, char mode);
void	ft_push(t_list **a, t_list **b, char mode);
void	ft_rotate(t_list **a, t_list **b, char mode);
void	ft_rotate_rev(t_list **a, t_list **b, char mode);
void	ft_rotate_rev_r(t_list **a, t_list **b, char mode);
void	ft_small_short(t_list **a, t_list **b);
void	ft_big_short(t_list **a, t_list **b, int chunks);
int		ft_find_number(t_list **a, int mode);
void	checking(t_list **a, t_list **b);
#endif
