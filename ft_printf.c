/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:54:23 by fmota             #+#    #+#             */
/*   Updated: 2021/03/05 10:54:23 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_def(t_flags *flags)
{
	flags->padding = 0;
	flags->precision = -1;
	flags->star = 0;
	flags->zero = 0;
	flags->width = 0;
}

int	establisher(const char *format, va_list args, t_flags *flags)
{
	int	index;

	index = 0;
	if (*format == 'c')
		index = manage_c(args, flags, index);
	else if (*format == 's')
		index = manage_s(args, flags, index);
	else if (*format == 'p')
		index = manage_p(args, flags, index);
	else if (*format == 'd' || *format == 'i')
		index = manage_d(args, flags, index);
	else if (*format == 'u')
		index = manage_u(args, flags, index);
	else if (*format == 'x')
		index = manage_x(args, flags, index);
	else if (*format == 'X')
		index = manage_X(args, flags, index);
	else if (*format == '%')
	{
		ft_putchar_fd('%', 1);
		++index;
	}
	return (index);
}

int	format_analyzer(const char *fmt, va_list args, t_flags *flags, int index)
{
	flags_def(flags);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			++fmt;
			while (read_flags(fmt))
			{
				if (make_flags(fmt, args, flags))
					++fmt;
				else if (ft_isdigit(*fmt))
					fmt += counter(fmt, args, flags);
			}
			index += establisher(fmt, args, flags);
			flags_def(flags);
		}
		else
		{
			ft_putchar_fd(*fmt, 1);
			++index;
		}
		++fmt;
	}
	return (index);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_flags	flags;
	int		set;
	int		index;

	index = 0;
	va_start(args, format);
	set = format_analyzer(format, args, &flags, index);
	va_end(args);
	return (set);
}
