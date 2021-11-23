/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_short_sorting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:51:53 by dabel-co          #+#    #+#             */
/*   Updated: 2021/11/22 17:42:15 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_move(t_list **a, t_list **b)
{
	if (ft_find_number(a, 3) == 1)
		ft_swap(a, b, 'a');
	if (ft_find_number(a, 3) == 2)
	{
		ft_rotate(a, b, 'a');
		ft_rotate(a, b, 'a');
	}
	if (ft_find_number(a, 3) == 3)
		ft_rotate_rev(a, b, 'a');
	if (ft_find_number(a, 3) == 4 || (ft_find_number(a, 3) == 3
			&& ft_lstsize(*a) == 5))
		ft_rotate_rev(a, b, 'a');
	ft_push(a, b, 'b');
}

void	ft_small_short(t_list **a, t_list **b)
{
	while (ft_lstsize(*a) > 3)
		ft_move(a, b);
	if (*(int *)(*a)->content > *(int *)(*a)->next->content
		&& *(int *)(*a)->content < *(int *)(*a)->next->next->content)
		ft_swap(a, b, 'a');
	if (*(int *)(*a)->content > *(int *)(*a)->next->content
		&& *(int *)(*a)->next->content > *(int *)(*a)->next->next->content)
		ft_swap(a, b, 'a');
	if (*(int *)(*a)->content < *(int *)(*a)->next->content
		&& *(int *)(*a)->content < *(int *)(*a)->next->next->content
		&& *(int *)(*a)->next->content > *(int *)(*a)->next->next->content)
		ft_swap(a, b, 'a');
	if (*(int *)(*a)->content < *(int *)(*a)->next->content
		&& *(int *)(*a)->content > *(int *)(*a)->next->next->content)
		ft_rotate_rev(a, b, 'a');
	if (*(int *)(*a)->content > *(int *)(*a)->next->content
		&& *(int *)(*a)->next->content < *(int *)(*a)->next->next->content)
		ft_rotate(a, b, 'a');
	while (ft_lstsize(*b) != 0)
		ft_push(a, b, 'a');
}
