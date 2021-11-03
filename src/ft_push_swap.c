/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:00:32 by dabel-co          #+#    #+#             */
/*   Updated: 2021/11/03 19:10:45 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_list	*ft_fill(char *argv, t_list *stack)
{
	int		p;

	while (*argv != '\0')
	{
		if (ft_atoi_pointer(argv, &p) == -1 || (!ft_isnumber(*argv) && *argv != ' '))
		{
			printf("bad parse\n");
			exit(0);
		}
		ft_lstadd_back(&stack, ft_lstnew((void *)(long)p));
		while (ft_isnumber(*argv) && *argv != ' ' && *argv != '\0')
			argv++;
		if (*argv == ' ')
			argv++;
	}
	return (stack);
}

int	main (int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	int i = 1;
	while (i < argc)
	{
		argv++;
		a = ft_fill(*argv, a);
		i++;
	}
	printf("%d\n", ft_lstsize(a));
	//ft_swap(&a, &b, 'a');
	while (a != NULL)
	{
		printf("%d\n", a->content);
		a = a->next;
	}
}
