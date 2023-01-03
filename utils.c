/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 16:31:01 by fmota             #+#    #+#             */
/*   Updated: 2021/06/28 16:31:01 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unsigned_length(unsigned int nb)
{
	int	index;

	index = 0;
	if (nb < 10)
		return (1);
	while (nb > 9)
	{
		nb /= 10;
		++index;
	}
	if (nb)
		++index;
	return (index);
}

int	int_length(int nb)
{
	int	index;

	index = 0;
	if (nb == -2147483648)
		return (10);
	if (nb < 10)
		return (1);
	while (nb > 9)
	{
		nb /= 10;
		++index;
	}
	if (nb >= 0)
		++index;
	return (index);
}

int	counter(const char *format, va_list args, t_flags *flags)
{
	int	index;

	index = 0;
	if (flags->precision >= 0)
	{
		flags->precision = set_width(format, args, flags);
		index = int_length(flags->width);
	}
	return (index);
}

int	deficient(int nb)
{
	int	diff;

	diff = 0;
	if (nb < 0)
		diff = 1;
	return (diff);
}

size_t	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0')
		index++;
	return (index);
}
