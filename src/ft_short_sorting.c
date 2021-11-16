/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short_sorting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:51:53 by dabel-co          #+#    #+#             */
/*   Updated: 2021/11/16 15:52:07 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_short_five(t_list **a, t_list **b)
{
	ft_push(a, b, 'a');
	if ((*a)->content > (*a)->next->next->next->content)
		ft_rotate(a, b, 'a');
	if ((*a)->content > (*a)->next->next->content && (*a)->content <
			(*a)->next->next->next->content)
		ft_rotate_rev(a, b, 'a');
	if ((*a)->content > (*a)->next->content)
		ft_swap(a, b, 'a');
	if (ft_lst_order(*a) == -1)
	{
		ft_rotate(a, b ,'a');
		ft_rotate(a, b ,'a');
	}
}

void	ft_small_short(t_list **a, t_list **b)
{
	while (ft_lstsize(*a) > 3)
		ft_push(a, b, 'b');
	if ((*a)->content > (*a)->next->content &&
			(*a)->content < (*a)->next->next->content)
		ft_swap(a, b, 'a');
	if ((*a)->content > (*a)->next->content &&
			(*a)->next->content > (*a)->next->next->content)
		ft_swap(a, b, 'a');
	if ((*a)->content < (*a)->next->content &&
			(*a)->content < (*a)->next->next->content &&
			(*a)->next->content > (*a)->next->next->content)
		ft_swap(a, b, 'a');
	if ((*a)->content < (*a)->next->content &&
			(*a)->content > (*a)->next->next->content)
		ft_rotate_rev(a, b, 'a');
	if ((*a)->content > (*a)->next->content &&
			(*a)->next->content < (*a)->next->next->content)
		ft_rotate(a, b, 'a');
	if (ft_lstsize(*b) != 0)
		ft_short_five(a, b);
}

