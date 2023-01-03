/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_lowhex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 20:49:47 by fmota             #+#    #+#             */
/*   Updated: 2021/07/17 20:49:47 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cast_hex(unsigned int nb)
{
	int	index;

	index = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 16;
		++index;
	}
	return (index);
}

void	set_lowhex(unsigned int nb)
{
	if (nb > 15)
	{
		set_lowhex((nb / 16));
		set_lowhex((nb % 16));
	}
	else if (nb < 10)
	{
		ft_putchar_fd(nb + '0', 1);
	}
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

void	set_lowhex_precision(int nb, t_flags *flags, int len)
{
	if (flags->padding == 1)
	{
		if (flags->precision >= len)
			int_adjust(flags->precision - len);
		set_lowhex(nb);
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
		set_lowhex(nb);
}

int	low_x_definition(int nb, t_flags *flags, int len)
{
	if (flags->padding == 0)
	{
		if (flags->width > len)
		{
			if (flags->zero == 1)
				int_adjust(flags->width - len);
			else
				padding(flags->width - len);
			set_lowhex(nb);
			return (flags->width);
		}
		else
			set_lowhex(nb);
	}
	else if (flags->padding == 1)
	{
		set_lowhex(nb);
		if (flags->width > len)
		{
			padding(flags->width - len);
			return (flags->width);
		}
	}
	return (len);
}

int	handle_x(t_flags *flags, int len)
{
	int	index;

	if (flags->width == 0 && flags->precision == -1)
		index = len;
	else if (flags->width > flags->precision && flags->width > len)
		index = flags->width;
	else if (flags->precision >= flags->width && flags->precision > len)
		index = flags->precision;
	else
		index = len;
	return (index);
}
