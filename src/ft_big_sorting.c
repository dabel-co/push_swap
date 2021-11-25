/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:40:50 by dabel-co          #+#    #+#             */
/*   Updated: 2021/11/23 19:17:58 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* The modes work as follow :
 * mode 2 to get the smallest value
 * mode 3 to get the position of the smallest value
 * mode 4 to get the biggest value
 * mode 5 to get the position of the biggest value */
int	ft_find_number(t_list **a, int mode)
{
	t_list	*aux;
	int		i;
	int		r;
	int		value;

	i = 0;
	r = 0;
	aux = *a;
	value = *(int *)aux->content;
	while (aux != NULL)
	{
		if ((value > *(int *)aux->content && mode <= 3)
			|| (value < *(int *)aux->content && mode >= 4))
		{
			r = i;
			value = *(int *)aux->content;
		}
		i++;
		aux = aux->next;
	}
	if (mode % 2 == 0)
		return (value);
	else
		return (r);
}
void	ft_step_2(t_list **a, t_list **b)
{
	int i;

	while (ft_lstsize(*b) != 0)
	{
		i = ft_find_number(b, 5);
		while (*(int *)(*b)->content != ft_find_number(b, 4))
		{
			if (i >= ft_lstsize(*b) / 2)
				ft_rotate_rev(a, b, 'b');
			else
				ft_rotate(a, b, 'b');
		}
		ft_push(a, b, 'a');
		if (ft_lstsize(*b) == 0)
			break;
		i = ft_find_number(b, 3);
		while (*(int *)(*b)->content != ft_find_number(b, 2))
		{
			if (i >= ft_lstsize(*b) / 2)
				ft_rotate_rev(a, b, 'b');
			else
				ft_rotate(a, b, 'b');
		}
		ft_push(a, b, 'a');
		ft_rotate(a, b, 'a');
	}
}
void	ft_step_1(t_list **a, t_list **b, t_param *d, int ratio)
{
	d->min = ft_find_number(a, 2) + (ratio * (d->progress - 1));
	d->max = ft_find_number(a, 2) + (ratio * d->progress);
	while (d->rotations > 0)
	{
		if (*(int *)(*a)->content <= d->max && *(int *)(*a)->content >= d->min)
			ft_push(a, b, 'b');
		else
			ft_rotate(a, b, 'a');
		d->rotations--;
	}
	while (d->mode != 0)
	{
		ft_rotate_rev(a, b, 'a');
		d->mode--;
	}
	ft_step_2(a, b);
}

void	ft_big_short(t_list **a, t_list **b, int chunks, int ratio)
{
	t_param	d;

	d.progress = 1;
	d.mode = 0;
	while (d.progress < chunks)
	{
			
	}
}
