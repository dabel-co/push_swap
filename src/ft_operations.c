/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:10:39 by dabel-co          #+#    #+#             */
/*   Updated: 2021/11/03 19:10:49 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **a, t_list **b, char mode)
{
	void	*aux;
	
	if ((mode == 'a' || mode == 's') && ft_lstsize(*a) > 1)
	{
		aux = (*a)->content;
		(*a)->content = (*a)->next->content;
		(*a)->next->content = aux;
		if (mode == 'a')
			write(1, "sa\n", 3);
	}
	if ((mode == 'b' || mode == 's') && ft_lstsize(*b) > 1)
	{
		aux = (*b)->content;
		(*b)->content = (*b)->next->content;
		(*b)->next->content = aux;
		if (mode == 'b')
			write(1, "sb\n", 3);
	}
	if (mode == 's')
		write (1, "ss\n", 3);
}

void	ft_push(t_list **a, t_list **b, char mode)
{
	if (mode == 'a' && ft_lstsize(*b) > 0)
	{	
	}
}
