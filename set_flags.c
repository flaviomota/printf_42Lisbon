/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 10:27:24 by fmota             #+#    #+#             */
/*   Updated: 2021/07/15 10:27:24 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	read_flags(const char *fmt)
{
	if (*fmt == '-' || *fmt == '*' || *fmt == '.')
		return (1);
	else if (ft_isdigit(*fmt))
		return (1);
	else
		return (0);
}

int	make_flags(const char *format, va_list args, t_flags *flags)
{
	if (*format == '-')
		flags->padding = 1;
	else if (*format == '*')
	{
		flags->star = 1;
		define_star(format, args, flags);
	}
	else if (*format == '.')
		flags->precision = 0;
	else if (*format == '0' && flags->precision == -1)
		flags->zero = 1;
	else
		return (0);
	return (1);
}

void	define_star(const char *format, va_list args, t_flags *flags)
{
	if (flags->precision >= 0)
		flags->precision = set_width(format, args, flags);
	else
	{
		flags->width = set_width(format, args, flags);
		flags->star = 0;
	}
	if (flags->width < 0)
	{
		flags->width = flags->width * -1;
		flags->padding = 1;
	}
}

int	set_width(const char *format, va_list args, t_flags *flags)
{
	int	index;

	index = 0;
	if (flags->star == 1)
	{
		flags->star = va_arg(args, int);
		return (flags->star);
	}
	if (ft_isdigit(*format))
	{
		while (ft_isdigit(*format))
		{
			index = index * 10 + (*format - '0');
			++format;
		}
	}
	return (index);
}
