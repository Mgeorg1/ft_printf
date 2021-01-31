/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemustaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:28:18 by aemustaf          #+#    #+#             */
/*   Updated: 2020/12/05 18:28:22 by aemustaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		processor(va_list *ap, t_flag *flags)
{
	int len;

	len = 0;
	if_neg_w(flags);
	if (flags->type == 'i' || flags->type == 'd')
		len = printf_decimal_int(va_arg(*ap, int), flags);
	else if (flags->type == 'u')
		len = printf_decimal_int(va_arg(*ap, unsigned int), flags);
	else if (flags->type == 'c')
		len = printf_char(va_arg(*ap, int), flags);
	else if (flags->type == 's')
		len = str_processor(va_arg(*ap, char*), flags);
	else if (flags->type == 'x' || flags->type == 'X')
		len = hex_processor(va_arg(*ap, unsigned int), flags);
	else if (flags->type == 'p')
		len = ptr_processor(va_arg(*ap, unsigned long long), flags);
	else if (flags->type == '%')
		len = prc_processor(flags);
	return (len);
}
