/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_processor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemustaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 14:50:19 by aemustaf          #+#    #+#             */
/*   Updated: 2020/12/12 14:50:22 by aemustaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		printf_char(int c, t_flag *flags)
{
	int len;
	int i;

	len = 1;
	i = flags->width - 1;
	if (flags->minus)
	{
		ft_putchar_fd(c, 1);
		while (i-- > 0)
		{
			ft_putchar_fd(' ', 1);
			len++;
		}
	}
	else
	{
		while (i-- > 0)
		{
			ft_putchar_fd(' ', 1);
			len++;
		}
		ft_putchar_fd(c, 1);
	}
	return (len);
}
