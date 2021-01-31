/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemustaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 14:48:34 by aemustaf          #+#    #+#             */
/*   Updated: 2020/12/03 14:48:36 by aemustaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <unistd.h>
#include "../includes/libft.h"

int		dot(t_flag *flags, const char *format, va_list *ap)
{
	int i;

	i = 1;
	flags->dot = 1;
	while (format[i] == '-')
		i++;
	if (ft_isdigit(format[i]))
	{
		flags->presicion = ft_atoi(&format[i]);
		while (ft_isdigit(format[i]))
			i++;
	}
	else if (format[i] == '*')
	{
		flags->presicion = va_arg(*ap, int);
		i++;
	}
	if (flags->presicion < 0)
		flags->dot = 0;
	return (i);
}

void	minus_a_zero(const char *a, t_flag *flags)
{
	if (*a == '-')
	{
		flags->zero = 0;
		flags->minus = 1;
	}
}

int		flags_parse(t_flag *flags, const char *format)
{
	int i;

	i = 0;
	if (format[i] == '0')
	{
		flags->zero = 1;
		while (format[i] == '0' || format[i] == '-')
		{
			minus_a_zero(&format[i], flags);
			i++;
		}
	}
	else if (format[i] == '-')
	{
		flags->minus = 1;
		while (format[i] == '-' || format[i] == '0')
		{
			minus_a_zero(&format[i], flags);
			i++;
		}
	}
	return (i);
}

int		type_parse(const char *format, t_flag *flags)
{
	int i;

	i = 0;
	if (*format == 'c' || *format == 's'
	|| *format == 'p' || *format == 'd' || *format == 'i'
	|| *format == 'u' || *format == 'x' || *format == 'X' || *format == '%')
	{
		flags->type = *format;
		i++;
	}
	return (i);
}

int		ft_parser(const char *format, va_list *ap, t_flag *flags)
{
	int i;

	i = 0;
	i += flags_parse(flags, &format[i]);
	if (ft_isdigit(format[i]))
	{
		flags->width = ft_atoi(&format[i]);
		while (ft_isdigit(format[i]) && format[i])
			i++;
	}
	else if (format[i] == '*')
	{
		flags->width = va_arg(*ap, int);
		i++;
	}
	if (format[i] == '.')
		i += dot(flags, &format[i], ap);
	i += type_parse(&format[i], flags);
	return (i);
}
