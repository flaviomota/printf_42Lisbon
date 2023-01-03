/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyzers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:53:07 by fmota             #+#    #+#             */
/*   Updated: 2021/07/06 20:53:07 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	padding(int len)
{
	while (len--)
		ft_putchar_fd(' ', 1);
}

void	int_adjust(int width)
{
	if (width > 0)
		while (width--)
			ft_putchar_fd('0', 1);
}
