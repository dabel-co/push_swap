/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 12:40:50 by dabel-co          #+#    #+#             */
/*   Updated: 2021/11/30 14:43:56 by dabel-co         ###   ########.fr       */
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
int	ft_find_position(t_list **a, int find)
{
	t_list	*aux;
	int		i;
	
	aux = *a;
	i = 0;
	while (*(int *)aux->content != find)
	{
		i++;
		aux = aux->next;
	}
	return (i);
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
void	ft_step_1(t_list **a, t_list **b, t_param *d)
{
	d->min = ft_find_number(a, 2) + (d->step * (d->progress - 1));
	d->max = ft_find_number(a, 2) + (d->step * d->progress) + d->last;
	//printf("vuelta ->%d, min ->%d, max ->%d\n", d->progress, d->min, d->max);
	while (ft_lstsize(*b) != d->step + d->last)
	{
	//	printf("%d %d\n", ft_lstsize(*b), d->step);
	//	printf("vuelta ->%d, min ->%d, max ->%d\n", d->progress, d->min, d->max);
		//if (d->progress == 6)
		//	usleep(1000000);
		if (*(int *)(*a)->content < d->max && *(int *)(*a)->content >= d->min)
			ft_push(a, b, 'b');
		else
			ft_rotate(a, b, 'a');
	}
	if (d->progress == 1)
		return ;
	if (ft_find_position(a, d->min - 1) > ft_lstsize(*a))
	{
		while (ft_find_position(a, d->min - 1) != ft_lstsize(*a) - 1)
			ft_rotate_rev(a, b, 'a');
	}
	else
	{
		while (ft_find_position(a, d->min - 1) != ft_lstsize(*a) - 1)
			ft_rotate(a, b, 'a');
	}

}

void	ft_big_short(t_list **a, t_list **b, int chunks)
{
	t_param	d;
	d.progress = 1;
	d.step = ft_lstsize(*a) / chunks;
	d.rest = ft_lstsize(*a) % chunks;
	d.last = 0;
	//printf("%d\n", d.rest);
	//sleep(2);
	ft_step_1(a, b, &d);
	ft_step_2(a, b);
	d.progress++;
	while (d.progress <= chunks)
	{
		if (d.progress == chunks)
			d.last = d.rest;
		ft_step_1(a, b, &d);
		ft_step_2(a, b);
	//	printf("%d\n", d.progress);
	//	sleep(1);
		d.progress++;
	}
	while (ft_find_position(a, ft_find_number(a, 2) != 0))
			ft_rotate(a, b, 'a');
}
