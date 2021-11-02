/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:17:42 by dabel-co          #+#    #+#             */
/*   Updated: 2021/11/02 17:30:28 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
# include "../Libft/src/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int	x;
	struct s_stack *next;
}				t_stack;
int	ft_atoi_pointer(char *str, int *p);
int	ft_isnumber(int c);
#endif

