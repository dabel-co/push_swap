/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:17:42 by dabel-co          #+#    #+#             */
/*   Updated: 2021/11/18 11:33:17 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../Libft/src/libft.h"
# include <stdio.h>
# include <stdlib.h>

void	checking(t_list **a, t_list **b);
void	ft_swap(t_list **a, t_list **b, char mode);
void	ft_push(t_list **a, t_list **b, char mode);
void	ft_rotate(t_list **a, t_list **b, char mode);
void	ft_rotate_rev(t_list **a, t_list **b, char mode);
void	ft_rotate_rev_r(t_list **a, t_list **b, char mode);
void	ft_small_short(t_list **a, t_list **b);
#endif
