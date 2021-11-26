/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:00:32 by dabel-co          #+#    #+#             */
/*   Updated: 2021/11/26 18:06:16 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_lst_add_element(int content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = malloc(sizeof(int));
	new->next = NULL;
	*(int *)new->content = content;
	return (new);
}

static	t_list	*ft_fill(char *argv, t_list *stack)
{
	int		p;

	while (*argv != '\0')
	{
		if (ft_atoi_pointer(argv, &p) == -1
			|| (!ft_isnumber(*argv) && *argv != ' '))
		{
			printf("bad parse\n");
			exit(0);
		}
		ft_lstadd_back(&stack, ft_lst_add_element(p));
		if (ft_lst_repeat(stack) == -1)
				printf("SAME\n");
		while (ft_isnumber(*argv) && *argv != ' ' && *argv != '\0')
			argv++;
		if (*argv == ' ')
			argv++;
	}
	return (stack);
}
void	checking(t_list **a, t_list **b)
{
	t_list *x = *a;
	t_list *y = *b;
	printf("STACK_A\n");
	while (x != NULL)
	{
//		usleep(100000);
		printf("%d\n", *(int *)x->content);
		x = x->next;
	}
	if (y != NULL)
		printf("STACK_B\n");
	while (y != NULL)
	{
//		usleep(100000);
		printf("%d\n", *(int *)y->content);
		y = y->next;
	}
}
int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		i;

	a = NULL;
	b = NULL;
	i = 1;
	while (i++ < argc && argv++)
		a = ft_fill(*argv, a);
	if (ft_lstsize(a) <= 5)
		ft_small_short(&a, &b);
	else if (ft_lstsize(a) <= 100)
		ft_big_short(&a, &b, 4);
	else
		ft_big_short(&a, &b, 8);
	//add free
	//probably also need free's in the fucking operations, leaks everywhere.
	checking (&a, &b);
}
