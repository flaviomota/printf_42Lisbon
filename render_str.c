/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 22:08:27 by fmota             #+#    #+#             */
/*   Updated: 2021/05/18 22:08:27 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	set_str_precision(char *str, t_flags *flags)
{
	int	index;
	int	len;

	index = 0;
	len = ft_strlen(str);
	if (flags->precision < len)
		index = set_crop(str, flags);
	else if (flags->precision >= len)
	{
		if (flags->precision == 0)
			padding(flags->width);
		else
			index = flags->width - len;
		if (flags->padding == 0)
			if (index > 0)
				padding(index);
	}
	return (index);
}

int	str_measure(char *str, t_flags *flags)
{
	int	index;
	int	len;
	int	range;

	index = 0;
	len = ft_strlen(str);
	range = flags->width - len;
	if (range > 0)
	{
		index = range;
		padding(range);
	}
	return (index);
}

int	set_crop(char *str, t_flags *flags)
{
	int	index;
	int	rigor;

	index = 0;
	rigor = flags->precision;
	if (flags->padding == 0)
	{
		if (flags->width - flags->precision > 0)
			padding(flags->width - flags->precision);
	}
	while (rigor--)
	{
		ft_putchar_fd(*str++, 1);
		++index;
	}
	if (flags->padding == 1)
	{
		if (flags->width - flags->precision > 0)
			padding(flags->width - flags->precision);
	}
	return (index);
}

int	manage_str(t_flags *flags, int index, int len)
{
	index = len;
	if (flags->width <= flags->precision)
	{
		if (flags->precision >= 0 && flags->precision <= len)
			index = flags->precision;
		else if (flags->precision > len && flags->width > len)
			index = flags->width;
		else if (flags->width < len)
			index = len;
	}
	else if (flags->width == 0)
	{
		if (flags->precision == -1)
			if (len == -1)
				index = 0;
	}
	else if (flags->width >= 0)
		if (flags->precision >= 0 || flags->width >= len)
			index = flags->width;
	return (index);
}

int	manage_null(t_flags *flags)
{
	if (flags->width == 0)
		return (0);
	if (flags->precision <= 0)
	{
		if (flags->width == 0 && flags->precision == 0)
			return (0);
		else if (flags->width > 0)
			padding(flags->width);
		return (flags->width);
	}
	else if (flags->width < flags->precision && flags->precision < 6)
	{
		padding(flags->width);
		return (flags->width);
	}
	if (flags->padding == 1 && flags->precision > 0)
	{
		printf("(");
		padding(flags->width - 1);
		return (flags->width);
	}
	return (1);
}
