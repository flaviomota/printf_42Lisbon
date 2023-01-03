/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 14:49:04 by fmota             #+#    #+#             */
/*   Updated: 2021/05/18 14:49:04 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_accuracy(int nb, t_flags *flags)
{
	if (flags->precision <= 0 && nb == 0)
	{
		if (flags->precision == 0)
			padding(flags->width);
		if (flags->precision == 0 || (flags->padding == 1 && flags->width == 0))
			return (1);
	}
	return (0);
}

void	int_measure(int nb, t_flags *flags, int diff, int len)
{
	if ((flags->width > len + diff && flags->width > flags->precision))
	{
		if (nb != 0 && flags->precision == 0)
			padding(flags->width - len - diff);
		else if (flags->precision >= len + diff)
			padding(flags->width - flags->precision - diff);
		else if (flags->width >= len && flags->precision > 0)
			if (flags->zero == 1 || (flags->precision < len + diff && nb != 0))
				padding(flags->width - len - diff);
	}
	if (flags->precision == flags->width)
	{
		if (diff == 1)
			ft_putchar_fd('-', 1);
		int_adjust(flags->width - len);
		ft_putnbr_fd(nb, 1);
	}
}

void	set_int_precision(int nb, t_flags *flags, int diff, int len)
{
	if (flags->zero == 0 && flags->precision <= 0)
	{
		if (flags->width > (len + diff) && flags->precision < 0)
			if (!flags->padding)
				padding(flags->width - (len + diff));
		if (flags->precision <= 0)
			if (diff == 1)
				ft_putchar_fd('-', 1);
	}
	else if (flags->precision > 0 || flags->zero == 1)
	{
		if (diff == 1)
			ft_putchar_fd('-', 1);
		if (flags->padding == 0 && flags->width >= flags->precision)
		{
			if (flags->width > (len + diff) && flags->precision < 0)
				int_adjust(flags->width - (len + diff));
			else if (flags->precision != -1)
				int_adjust(flags->precision - len);
		}
		else if (flags->padding == 1 || flags->width < flags->precision)
			int_adjust(flags->precision - len);
	}
	int_padding(nb, flags, len, diff);
}

void	int_padding(int nb, t_flags *flags, int len, int diff)
{
	int	range;

	if (nb == -2147483648)
	{
		ft_putnbr_fd(214748364, 1);
		ft_putnbr_fd(8, 1);
	}
	else
		ft_putnbr_fd(nb, 1);
	if (flags->precision > len)
		range = flags->width - flags->precision - diff;
	else
		range = flags->width - (len + diff);
	if (flags->padding == 1 && range > 0)
		padding(range);
}

int	manage_int(t_flags *flags, int nb, int len, int diff)
{
	nb = len + diff;
	if (flags->width < flags->precision)
	{
		if (flags->precision >= len)
			nb = flags->precision + diff;
		else if (flags->precision < len && flags->padding == 1)
			nb = len + diff;
		else if (flags->width == 0 && flags->precision < (len + diff))
			nb = flags->width + len + diff;
	}
	else if (flags->width > 0 && flags->width > flags->precision)
	{
		if (flags->width > len)
			nb = flags->width;
		else if (flags->precision > len)
			nb = flags->precision + diff;
		else if (flags->precision < len)
			nb = len + diff;
		else if (flags->width != 0)
			nb = flags->width;
	}
	return (nb);
}
