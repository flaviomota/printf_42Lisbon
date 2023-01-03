/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 10:54:08 by fmota             #+#    #+#             */
/*   Updated: 2021/03/05 10:54:08 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_flags
{
	int	padding;
	int	star;
	int	width;
	int	precision;
	int	zero;
}	t_flags;

void	padding(int len);
void	int_adjust(int width);
int		manage_p(va_list args, t_flags *flags, int index);
int		manage_d(va_list args, t_flags *flags, int index);
int		manage_u(va_list args, t_flags *flags, int index);
int		manage_x(va_list args, t_flags *flags, int index);
int		manage_X(va_list args, t_flags *flags, int index);
int		manage_c(va_list args, t_flags *flags, int index);
int		manage_s(va_list args, t_flags *flags, int index);
void	flags_def(t_flags *flags);
int		establisher(const char *format, va_list args, t_flags *flags);
int		format_analyzer(const char *fmt, va_list args,
			t_flags *flags, int index);
int		ft_printf(const char *format, ...);
int		int_accuracy(int nb, t_flags *flags);
void	int_measure(int nb, t_flags *flags, int diff, int len);
void	set_int_precision(int nb, t_flags *flags, int diff, int len);
void	int_padding(int nb, t_flags *flags, int len, int diff);
int		manage_int(t_flags *flags, int nb, int len, int diff);
int		cast_hex(unsigned int nb);
void	set_lowhex(unsigned int nb);
int		low_x_definition(int nb, t_flags *flags, int len);
void	set_lowhex_precision(int nb, t_flags *flags, int len);
int		handle_x(t_flags *flags, int len);
int		set_str_precision(char *str, t_flags *flags);
int		str_measure(char *str, t_flags *flags);
int		set_crop(char *str, t_flags *flags);
int		manage_str(t_flags *flags, int index, int len);
int		manage_null(t_flags *flags);
void	set_unsigned_precision(int nb, t_flags *flags, int len);
void	unsigned_measure(int nb, t_flags *flags, int len);
int		manage_unsigned(ssize_t nb, t_flags *flags, int len);
void	set_uphex_precision(int nb, t_flags *flags, int len);
int		up_x_definition(int nb, t_flags *flags, int index);
void	set_uphex(unsigned int nb);
int		set_route(unsigned long nb);
void	establish_route(unsigned long nb);
int		hex_analyzer(ssize_t route, t_flags *flags);
int		read_flags(const char *fmt);
int		make_flags(const char *format, va_list args, t_flags *flags);
void	define_star(const char *format, va_list args, t_flags *flags);
int		set_width(const char *format, va_list args, t_flags *flags);
int		unsigned_length(unsigned int nb);
int		int_length(int nb);
int		counter(const char *format, va_list args, t_flags *flags);
int		deficient(int nb);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putunbr(ssize_t n);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);

#endif