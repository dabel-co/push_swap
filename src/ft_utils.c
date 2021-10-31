/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabel-co <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:33:41 by dabel-co          #+#    #+#             */
/*   Updated: 2021/10/27 11:55:36 by dabel-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
//add to libft

int ft_isnumber(int c)
{
	if (c == '-' || c == '+')
		return (1);
	if (47 < c && c < 58)
		return (1);
	return (0);
}
int	ft_atoi_pointer(char *str, int *p)
{
	int			i;
	int			n;
	long long	x;

	x = 0;
	n = 1;
	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		n = -1;
		i++;
	}
	while (str[i] != ' ' && str[i] != '\0')
	{
		x = x * 10 + (str[i] - '0');
		i++;
	}
	x = x * n;
	if (x > 2147483647 || x < -2147483648)
		return (-1);
	*p = x;
	return (0);
}
