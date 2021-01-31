/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_processor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemustaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 14:50:49 by aemustaf          #+#    #+#             */
/*   Updated: 2020/12/12 14:50:52 by aemustaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		hex_digit_len(unsigned int a)
{
	int i;

	i = 0;
	if (a == 0)
		return (1);
	while (a > 0)
	{
		a = a / 16;
		i++;
	}
	return (i);
}

void	ft_putnbr_x(t_flag *flags, unsigned int a)
{
	unsigned int		mod;
	unsigned int		div;
	char				r;

	if (flags->type == 'x')
		r = 'a';
	else
		r = 'A';
	mod = a % 16;
	div = a / 16;
	if (div != 0)
		ft_putnbr_x(flags, div);
	if (mod >= 10)
		ft_putchar_fd(mod - 10 + r, 1);
	else
		ft_putchar_fd(mod + '0', 1);
}

int		print_right_x(t_flag *flags, unsigned int a, char c)
{
	int len;
	int len_str;

	len = hex_digit_len(a);
	len_str = len;
	len_str += print_while((flags->width - MAX(flags->presicion, len)), c);
	len_str += print_while((flags->presicion - len), '0');
	if (!(flags->dot == 1 && flags->presicion == 0 && a == 0))
		ft_putnbr_x(flags, a);
	else
		len_str--;
	return (len_str);
}

int		print_left_x(t_flag *flags, unsigned int a)
{
	int len;
	int x_len;

	len = 0;
	x_len = hex_digit_len(a);
	len += x_len;
	len += print_while(flags->presicion - x_len, '0');
	if (!(flags->dot == 1 && flags->presicion == 0 && a == 0))
		ft_putnbr_x(flags, a);
	else
		len--;
	len += print_while(flags->width - MAX(flags->presicion, x_len), ' ');
	return (len);
}

int		hex_processor(unsigned int a, t_flag *flags)
{
	if (flags->dot == 1 && flags->presicion == 0 && a == 0)
		flags->width++;
	if (flags->minus == 1)
		return (print_left_x(flags, a));
	if (flags->zero == 0 && flags->minus == 0)
		return (print_right_x(flags, a, ' '));
	if (flags->zero == 1)
	{
		if (flags->dot == 0)
			return (print_right_x(flags, a, '0'));
		else
			return (print_right_x(flags, a, ' '));
	}
	return (0);
}
