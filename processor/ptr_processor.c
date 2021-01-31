/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_processor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemustaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 18:08:25 by aemustaf          #+#    #+#             */
/*   Updated: 2020/12/21 18:08:28 by aemustaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		p_digit_len(unsigned long long a, t_flag *flags)
{
	int i;

	i = 0;
	if (flags->dot == 1 && flags->presicion == 0 && a == 0)
		return (2);
	if (a == 0)
		return (3);
	while (a > 0)
	{
		a = a / 16;
		i++;
	}
	return (i + 2);
}

void	ft_putnbr_p(t_flag *flags, unsigned long long a)
{
	unsigned long long		mod;
	unsigned long long		div;
	char					r;

	r = 'a';
	mod = a % 16;
	div = a / 16;
	if (div != 0)
		ft_putnbr_p(flags, div);
	if (mod >= 10)
		ft_putchar_fd(mod - 10 + r, 1);
	else
		ft_putchar_fd(mod + '0', 1);
}

int		print_right_p(t_flag *flags, unsigned long long a, char c)
{
	int len;
	int len_str;

	len = p_digit_len(a, flags);
	len_str = len;
	if (c == '0')
	{
		ft_putstr_fd("0x", 1);
		len_str += print_while((flags->width - MAX(flags->presicion, len)), c);
	}
	if (c == ' ')
	{
		len_str += print_while((flags->width - MAX(flags->presicion, len)), c);
		ft_putstr_fd("0x", 1);
	}
	len_str += print_while((flags->presicion - (len - 2)), '0');
	if (!(flags->dot == 1 && flags->presicion == 0 && a == 0))
		ft_putnbr_p(flags, a);
	return (len_str);
}

int		print_left_p(t_flag *flags, unsigned long long a)
{
	int len;
	int x_len;

	len = 0;
	x_len = p_digit_len(a, flags);
	len += x_len;
	ft_putstr_fd("0x", 1);
	len += print_while(flags->presicion - x_len, '0');
	if (!(flags->dot == 1 && flags->presicion == 0 && a == 0))
		ft_putnbr_p(flags, a);
	else
		len--;
	len += print_while(flags->width - MAX(flags->presicion, x_len), ' ');
	return (len);
}

int		ptr_processor(unsigned long long a, t_flag *flags)
{
	if (flags->minus == 1)
		return (print_left_p(flags, a));
	if (flags->zero == 0 && flags->minus == 0)
		return (print_right_p(flags, a, ' '));
	if (flags->zero == 1)
	{
		if (flags->dot == 0)
			return (print_right_p(flags, a, '0'));
		else
			return (print_right_p(flags, a, ' '));
	}
	return (0);
}
