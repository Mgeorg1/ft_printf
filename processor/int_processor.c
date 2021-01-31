/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_processor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemustaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:46:41 by aemustaf          #+#    #+#             */
/*   Updated: 2020/12/09 14:46:44 by aemustaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

int		print_left_d(t_flag *flags, int len, int a)
{
	int len_str;

	len_str = len;
	if (a < 0 && flags->type != 'u')
	{
		a = if_negative(a);
		ft_putchar_fd('-', 1);
		flags->presicion++;
	}
	len_str += print_while((flags->presicion - len), '0');
	if (flags->type == 'u'
	&& !(flags->dot == 1 && flags->presicion == 0 && a == 0))
		ft_putnbr_u_fd(a, 1);
	else if (flags->dot == 1 && flags->presicion == 0 && a == 0)
		len_str--;
	else
		ft_putnbr_ptf(a, 1);
	len_str += print_while((flags->width - MAX(flags->presicion, len)), ' ');
	return (len_str);
}

int		print_neg_zero(int a, t_flag *flags, int len, char w_c)
{
	a = if_negative(a);
	ft_putchar_fd('-', 1);
	return (print_while((flags->width - MAX(flags->presicion, len)), w_c));
}

int		print_neg_sp(int a, t_flag *flags, int len, char w_c)
{
	int len_s;

	flags->presicion++;
	a = if_negative(a);
	len_s = print_while((flags->width - MAX(flags->presicion, len)), w_c);
	ft_putchar_fd('-', 1);
	return (len_s);
}

int		print_right_d(t_flag *flags, int len, int a, char w_c)
{
	int len_s;

	len_s = len;
	if (a < 0 && w_c == '0' && !(flags->type == 'u'))
		len_s += print_neg_zero(a, flags, len, w_c);
	else if (a < 0 && w_c == ' ' && !(flags->type == 'u'))
		len_s += print_neg_sp(a, flags, len, w_c);
	else
		len_s += print_while((flags->width - MAX(flags->presicion, len)), w_c);
	len_s += print_while((flags->presicion - len), '0');
	if (flags->type == 'u'
	&& !(flags->dot == 1 && flags->presicion == 0 && a == 0))
		ft_putnbr_u_fd(a, 1);
	else if (flags->dot == 1 && flags->presicion == 0 && a == 0)
		len_s--;
	else
		ft_putnbr_ptf(a, 1);
	return (len_s);
}

int		printf_decimal_int(int a, t_flag *flags)
{
	int	len_i;

	if (flags->type == 'u')
		len_i = u_int_len(a);
	else
		len_i = int_len(a);
	if (flags->presicion == 0 && flags->dot == 1 && a == 0)
		flags->width++;
	if (flags->minus == 1)
		return (print_left_d(flags, len_i, a));
	if (flags->zero == 0 && flags->minus == 0)
		return (print_right_d(flags, len_i, a, ' '));
	if (flags->zero == 1)
	{
		if (flags->dot == 0)
			return (print_right_d(flags, len_i, a, '0'));
		else
			return (print_right_d(flags, len_i, a, ' '));
	}
	return (0);
}
