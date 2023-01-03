/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 13:40:49 by fmota             #+#    #+#             */
/*   Updated: 2021/07/19 13:40:49 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_unsigned_precision(int nb, t_flags *flags, int len)
{
	if (flags->precision > len || flags->width > len)
	{
		if (flags->padding == 0)
			padding(flags->width - len);
		else if (flags->padding == 1)
			int_adjust(flags->precision - len);
	}
	ft_putunbr(nb);
	if (flags->padding == 1)
	{
		if (flags->precision > len)
			padding(flags->width - flags->precision);
		else if (flags->width > len)
			padding(flags->width - len);
	}
}

void	unsigned_measure(int nb, t_flags *flags, int len)
{
	if (flags->precision == -1 && flags->padding == 0)
	{
		if (flags->zero == 1)
			int_adjust(flags->width - len);
		else if (flags->width > len)
			padding(flags->width - len);
		if ((flags->zero == 1) || (flags->width > len))
			ft_putunbr(nb);
	}
	else if (flags->precision >= len && flags->padding == 0)
	{
		padding(flags->width - flags->precision);
		int_adjust(flags->precision - len);
		ft_putunbr(nb);
	}
}

int	manage_unsigned(ssize_t nb, t_flags *flags, int len)
{
	if (flags->width < len && flags->precision == -1)
	{
		ft_putunbr(nb);
		return (len);
	}
	if (flags->width > flags->precision)
	{
		unsigned_measure(nb, flags, len);
		if (flags->padding == 0)
			if (flags->precision == -1 || flags->precision >= len)
				if (flags->zero == 1 || flags->width > len)
					return (flags->width);
	}
	else if (flags->precision > len)
	{
		int_adjust(flags->precision - len);
		ft_putunbr(nb);
		return (flags->precision);
	}
	set_unsigned_precision(nb, flags, len);
	if (flags->width >= flags->precision && flags->width > len)
		return (flags->width);
	else if (flags->precision > len)
		return (flags->precision);
	return (len);
}
