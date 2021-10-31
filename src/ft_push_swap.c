/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:00:32 by dabel-co          #+#    #+#             */
/*   Updated: 2021/10/27 15:55:23 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static	t_list	*ft_fill(char *argv, t_list *stack)
{
	int		p;
	
	while (*argv != '\0')
	{
		if (ft_atoi_pointer(argv, &p) == -1)
			printf("joder\n");
		ft_lstadd_back(&stack, ft_lstnew(p));
		while (ft_isnumber(*argv) && *argv != ' ' && *argv != '\0')
			argv++;
		if (*argv == ' ')
			argv++;
	}
	return (stack);
}

int	main (int argc, char **argv)
{
	t_list	*stack;

	stack = NULL;
	int i = 1;
	while (i < argc)
	{
		argv++;
		printf("%s\n", *argv);
		stack = ft_fill(*argv, stack);
		i++;
	}
	while (stack != NULL)
	{
		printf("%d\n", stack->content);
		stack = stack->next;
	}
	//ft_fill(argc, *argv, stack);
}
