/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:10:39 by dabel-co          #+#    #+#             */
/*   Updated: 2021/12/08 17:23:59 by dabel-co         ###   ########.fr       */
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
	t_list	*aux;

	if (mode == 'a' && ft_lstsize(*b) > 0)
	{
		ft_lstadd_front(a, ft_lst_add_element(*(int *)(*b)->content));
		aux = (*b)->next;
		free((*b)->content);
		free((*b));
		(*b) = aux;
		write (1, "pa\n", 3);
	}
	if (mode == 'b' && ft_lstsize(*a) > 0)
	{
		ft_lstadd_front(b, ft_lst_add_element(*(int *)(*a)->content));
		aux = (*a)->next;
		free((*a)->content);
		free((*a));
		(*a) = aux;
		write (1, "pb\n", 3);
	}
}

void	ft_rotate(t_list **a, t_list **b, char mode)
{
	t_list	*aux;

	if ((mode == 'a' || mode == 'r') && ft_lstsize(*a) > 1)
	{
		ft_lstadd_back(a, ft_lst_add_element(*(int *)(*a)->content));
		aux = (*a)->next;
		free((*a)->content);
		free((*a));
		(*a) = aux;
		if (mode == 'a')
			write(1, "ra\n", 3);
	}
	if ((mode == 'b' || mode == 'r') && ft_lstsize(*b) > 1)
	{
		ft_lstadd_back(b, ft_lst_add_element(*(int *)(*b)->content));
		aux = (*b)->next;
		free((*b)->content);
		free((*b));
		(*b) = aux;
		if (mode == 'b')
			write(1, "rb\n", 3);
	}
	if (mode == 'r')
		write (1, "rr\n", 3);
}

void	ft_rotate_rev_aux(t_list **a)
{
	t_list	*aux;

	aux = (*a);
	while (aux->next->next != NULL)
		aux = aux->next;
	ft_lstadd_front(a, ft_lst_add_element(*(int *)aux->next->content));
	free(aux->next->content);
	free(aux->next);
	aux->next = NULL;
}

void	ft_rotate_rev(t_list **a, t_list **b, char mode)
{
	if ((mode == 'a' || mode == 'r') && ft_lstsize(*a) > 1)
	{
		ft_rotate_rev_aux(a);
		if (mode == 'a')
			write(1, "rra\n", 4);
	}
	if ((mode == 'b' || mode == 'r') && ft_lstsize(*b) > 1)
	{
		ft_rotate_rev_aux(b);
		if (mode == 'b')
			write(1, "rrb\n", 4);
	}
}
