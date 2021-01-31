/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prc_processor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemustaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 17:30:10 by aemustaf          #+#    #+#             */
/*   Updated: 2020/12/14 17:30:13 by aemustaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		prc_processor(t_flag *flags)
{
	int len;

	len = 1;
	if (flags->zero == 1)
	{
		len += print_while(flags->width - 1, '0');
		ft_putchar_fd('%', 1);
	}
	else if (flags->minus == 1)
	{
		ft_putchar_fd('%', 1);
		len += print_while(flags->width - 1, ' ');
	}
	else
	{
		len += print_while(flags->width - 1, ' ');
		ft_putchar_fd('%', 1);
	}
	return (len);
}
