/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemustaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:50:49 by aemustaf          #+#    #+#             */
/*   Updated: 2020/12/03 11:50:52 by aemustaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <unistd.h>

void	init_flags(t_flag *flags)
{
	flags->dot = 0;
	flags->minus = 0;
	flags->presicion = 0;
	flags->width = 0;
	flags->zero = 0;
	flags->type = 0;
}

int		printf_s(char format)
{
	int len;

	len = 0;
	ft_putchar_fd(format, 1);
	len++;
	return (len);
}

int		ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	ap;
	t_flag	flags;

	va_start(ap, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%' && !(format[i + 1] == '\0'))
		{
			i++;
			init_flags(&flags);
			i += ft_parser(&format[i], &ap, &flags);
			len += processor(&ap, &flags);
		}
		else
		{
			len += printf_s(format[i]);
			i++;
		}
	}
	va_end(ap);
	return (len);
}
