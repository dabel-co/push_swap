/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:00:32 by dabel-co          #+#    #+#             */
/*   Updated: 2021/12/02 16:42:09 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    ft_find_position(t_list **a, int find)
{
    t_list    *aux;
    int        i;
    
    aux = *a;
    i = 0;
    while (*(int *)aux->content != find)
    {
        i++;
        aux = aux->next;
    }
    return (i);
}

/* The modes work as follow :
 * mode 2 to get the smallest value
 * mode 3 to get the position of the smallest value
 * mode 4 to get the biggest value
 * mode 5 to get the position of the biggest value */
int    ft_find_number(t_list **a, int mode)
{
    t_list    *aux;
    int        i;
    int        r;
    int        value;

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
			ft_error(&stack);
		ft_lstadd_back(&stack, ft_lst_add_element(p));
		if (ft_lst_repeat(stack) == -1)
		{
			ft_error(&stack);
			printf("joder\n");
		}
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
	if (argc == 1)
		return (0);
	if (ft_strlen(argv[1]) == 0)
		ft_error(&a);
	while (i++ < argc && argv++)
		a = ft_fill(*argv, a);
	if (ft_lst_order(a) == 0)
		return (0) ;
	if (ft_lstsize(a) <= 5)
		ft_small_short(&a, &b);
	else if (ft_lstsize(a) <= 100)
		ft_big_short(&a, &b, 4);
	else
		ft_big_short(&a, &b, 8);
	ft_free(&a, &b);
	system("leaks push_swap");
//		checking (&a, &b);
}
