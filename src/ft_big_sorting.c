/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:40:50 by dabel-co          #+#    #+#             */
/*   Updated: 2021/12/09 19:11:35 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_test(t_list **a, t_param *d)
{
	int		i;
	t_list	*aux;

	aux = *a;
	i = 0;
	while (aux->next != NULL)
	{
		if (*(int *)aux->content < d->max && *(int *)aux->content >= d->min)
			i++;
		aux = aux->next;
	}
	return (i);
}

static int	ft_find_stop(t_list **a, int number)
{
	t_list	*aux;

	while (1)
	{
		aux = *a;
		while (aux != NULL)
		{
			if (*(int *)aux->content == number)
				return (number);
			aux = aux->next;
		}
		number--;
	}
}

static void	ft_step_2(t_list **a, t_list **b, int i)
{
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
			break ;
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

static void	ft_step_1(t_list **a, t_list **b, t_param *d)
{
	d->min = ft_find_number(a, 2) + (d->step * (d->progress - 1));
	d->max = ft_find_number(a, 2) + (d->step * d->progress) + d->last;
	while (ft_test(a, d) > 0)
	{
		if (*(int *)(*a)->content < d->max && *(int *)(*a)->content >= d->min)
			ft_push(a, b, 'b');
		else
			ft_rotate(a, b, 'a');
	}
	if (d->progress == 1)
		return ;
	d->stop = ft_find_stop(a, d->min - 1);
	if (ft_find_position(a, d->stop) > ft_lstsize(*a))
	{
		while (ft_find_position(a, d->stop) != ft_lstsize(*a) - 1)
			ft_rotate(a, b, 'a');
	}
	else
	{
		while (ft_find_position(a, d->stop) != ft_lstsize(*a) - 1)
			ft_rotate_rev(a, b, 'a');
	}
}

void	ft_big_short(t_list **a, t_list **b, int chunks)
{
	t_param	d;

	d.progress = 1;
	d.step = (ft_find_number(a, 4) - ft_find_number(a, 2)) / chunks;
	d.rest = (ft_find_number(a, 4) - ft_find_number(a, 2)) % chunks;
	d.last = 0;
	while (d.progress <= chunks)
	{
		if (d.progress == chunks)
			d.last = d.rest;
		ft_step_1(a, b, &d);
		ft_step_2(a, b, 0);
		d.progress++;
	}
	while (ft_find_number(a, 3) != 0)
		ft_rotate(a, b, 'a');
}
