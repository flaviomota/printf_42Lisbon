/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 16:41:40 by fmota             #+#    #+#             */
/*   Updated: 2021/07/19 16:41:40 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_route(unsigned long nb)
{
	int	index;

	index = 0;
	while (nb > 0)
	{
		nb = nb / 16;
		++index;
	}
	return (index);
}

void	establish_route(unsigned long nb)
{
	if (nb > 15)
	{
		establish_route(nb / 16);
		establish_route(nb % 16);
	}
	else if (nb < 10)
		ft_putchar_fd(nb + '0', 1);
	else
	{
		if (nb == 10)
			ft_putchar_fd('a', 1);
		else if (nb == 11)
			ft_putchar_fd('b', 1);
		else if (nb == 12)
			ft_putchar_fd('c', 1);
		else if (nb == 13)
			ft_putchar_fd('d', 1);
		else if (nb == 14)
			ft_putchar_fd('e', 1);
		else if (nb == 15)
			ft_putchar_fd('f', 1);
	}
}

int	hex_analyzer(ssize_t route, t_flags *flags)
{
	int	index;
	int	len;

	len = set_route(route) + 2;
	index = len;
	if (route == 0)
	{
		index = flags->width;
		padding(flags->width - 3);
	}
	else if (flags->width - len > 0)
	{
		index = flags->width;
		padding(flags->width - len);
	}
	return (index);
}
