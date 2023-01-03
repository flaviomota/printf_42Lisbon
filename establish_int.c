/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   establish_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:39:18 by fmota             #+#    #+#             */
/*   Updated: 2021/07/19 14:39:18 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	manage_p(va_list args, t_flags *flags, int index)
{
	void	*str;
	ssize_t	route;

	str = va_arg(args, void *);
	route = (ssize_t)(str);
	if (route == 0)
	{
		if (flags->width <= 0)
			return (write(1, "0x0", 3));
		else if (flags->padding == 0)
			index = hex_analyzer(route, flags);
		write(1, "0x0", 3);
	}
	else if (route != 0)
	{
		if (flags->width == 0 && flags->precision == -1)
			index = hex_analyzer(route, flags);
		else if (flags->width > 0 && flags->padding == 0)
			index = hex_analyzer(route, flags);
		write(1, "0x", 2);
		establish_route(route);
	}
	if (flags->width > 0 && flags->padding == 1)
		index = hex_analyzer(route, flags);
	return (index);
}

int	manage_d(va_list args, t_flags *flags, int index)
{
	int	str;
	int	len;
	int	diff;

	str = va_arg(args, int);
	diff = deficient(str);
	if (diff)
		str = -str;
	len = int_length(str);
	if (str == 0 && (flags->precision == 0 && flags->width == 0))
		return (0);
	if (flags->padding == 0 && flags->width > flags->precision)
		int_measure(str, flags, diff, len);
	if (int_accuracy(str, flags))
		if (flags->width >= len)
			return (flags->width + diff);
	if (flags->precision == flags->width)
		int_measure(str, flags, diff, len);
	if (len >= flags->width && flags->precision == flags->width)
		return (len + diff);
	else if (len < flags->width && flags->precision == flags->width)
		return (flags->width + diff);
	set_int_precision(str, flags, diff, len);
	return (manage_int(flags, index, len, diff));
}

int	manage_u(va_list args, t_flags *flags, int index)
{
	size_t	str;
	int		len;

	str = va_arg(args, int);
	len = unsigned_length(str);
	if (str == 0 && flags->precision == 0)
	{
		if (flags->width > 0)
		{
			padding(flags->width);
			return (flags->width);
		}
		if (len == 1)
			return (flags->width);
		else
			return (flags->width);
	}
	if (index > 50)
		return (index);
	return (manage_unsigned(str, flags, len));
}

int	manage_x(va_list args, t_flags *flags, int index)
{
	int		str;
	size_t	hex;
	int		tmp;

	tmp = -1;
	str = va_arg(args, int);
	hex = (size_t)str;
	index = cast_hex(hex);
	if (hex == 0 && flags->precision == 0)
	{
		if (flags->width)
			padding(flags->width);
		return (flags->width);
	}
	if (flags->precision == -1)
	{
		tmp = low_x_definition(hex, flags, index);
		if (tmp > -1)
			return (tmp);
	}
	set_lowhex_precision(str, flags, index);
	return (handle_x(flags, index));
}

int	manage_X(va_list args, t_flags *flags, int index)
{
	int		str;
	size_t	hex;
	int		tmp;

	tmp = -1;
	str = va_arg(args, int);
	hex = (size_t)str;
	index = cast_hex(hex);
	if (hex == 0 && flags->precision == 0)
	{
		if (flags->width)
			padding(flags->width);
		return (flags->width);
	}
	if (flags->precision == -1)
	{
		tmp = up_x_definition(hex, flags, index);
		if (tmp > -1)
			return (tmp);
	}
	set_uphex_precision(str, flags, index);
	return (handle_x(flags, index));
}
