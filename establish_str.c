/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   establish_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 16:07:45 by fmota             #+#    #+#             */
/*   Updated: 2021/07/19 16:07:45 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	manage_c(va_list args, t_flags *flags, int index)
{
	int	str;

	str = va_arg(args, int);
	if (flags->width > 1 && flags->padding == 0)
		padding(flags->width - 1);
	ft_putchar_fd(str, 1);
	if (flags->width > 1 && flags->padding == 1)
		padding(flags->width - 1);
	if (flags->width)
		index = flags->width;
	else
		index = 1;
	return (index);
}

int	manage_s(va_list args, t_flags *flags, int index)
{
	char	*str;
	int		len;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (flags->precision >= 0)
		set_str_precision(str, flags);
	else
	{
		if (flags->width > 0 && flags->padding == 0)
			str_measure(str, flags);
		ft_putstr_fd(str, 1);
		if (flags->width > 0 && flags->padding == 1)
			str_measure(str, flags);
	}
	index = manage_str(flags, index, len);
	return (index);
}
