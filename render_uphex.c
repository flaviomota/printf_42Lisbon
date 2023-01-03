/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_uphex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 13:59:49 by fmota             #+#    #+#             */
/*   Updated: 2021/07/19 13:59:49 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_uphex_precision(int nb, t_flags *flags, int len)
{
	if (flags->padding == 1)
	{
		if (flags->precision >= len)
			int_adjust(flags->precision - len);
		set_uphex(nb);
		if (flags->precision > len && flags->width > flags->precision)
			padding(flags->width - flags->precision);
		else if (flags->width - len > 0 && flags->width > flags->precision)
			padding(flags->width - len);
	}
	else if (flags->width <= flags->precision)
		int_adjust(flags->precision - len);
	else
	{
		if (flags->precision > len && flags->width > len)
		{
			padding(flags->width - flags->precision);
			int_adjust(flags->precision - len);
		}
		else if (flags->width > len)
			padding(flags->width - len);
	}
	if (flags->padding == 0)
		set_uphex(nb);
}

int	up_x_definition(int nb, t_flags *flags, int index)
{
	if (flags->padding == 0)
	{
		if (flags->width > index)
		{
			if (flags->zero == 1)
				int_adjust(flags->width - index);
			else
				padding(flags->width - index);
			set_uphex(nb);
			return (flags->width);
		}
		else
			set_uphex(nb);
	}
	else if (flags->padding == 1)
	{
		set_uphex(nb);
		if (flags->width > index)
		{
			padding(flags->width - index);
			return (flags->width);
		}
	}
	return (index);
}

void	set_uphex(unsigned int nb)
{
	cast_hex(nb);
	if (nb > 15)
	{
		set_uphex((nb / 16));
		set_uphex((nb % 16));
	}
	else if (nb < 10)
		ft_putchar_fd(nb + '0', 1);
	else
	{
		if (nb == 10)
			ft_putchar_fd('A', 1);
		else if (nb == 11)
			ft_putchar_fd('B', 1);
		else if (nb == 12)
			ft_putchar_fd('C', 1);
		else if (nb == 13)
			ft_putchar_fd('D', 1);
		else if (nb == 14)
			ft_putchar_fd('E', 1);
		else if (nb == 15)
			ft_putchar_fd('F', 1);
	}
}
