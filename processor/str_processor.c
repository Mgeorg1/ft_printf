/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_processor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemustaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 14:50:31 by aemustaf          #+#    #+#             */
/*   Updated: 2020/12/12 14:50:34 by aemustaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		printf_str(char *str, t_flag *flags)
{
	int len;

	len = 0;
	if (flags->dot == 1)
	{
		while (*str && flags->presicion--)
		{
			ft_putchar_fd(*str, 1);
			str++;
			len++;
		}
	}
	else
	{
		ft_putstr_fd(str, 1);
		len = ft_strlen(str);
	}
	return (len);
}

int		sp_if_dot(t_flag *flags, char *s)
{
	if (flags->dot)
		return (flags->width - MIN(flags->presicion, ft_strlen(s)));
	else
		return (flags->width - ft_strlen(s));
}

int		flag_minus(t_flag *flags, char *str, int sp_len)
{
	int len;

	len = 0;
	if (flags->minus)
	{
		len += printf_str(str, flags);
		len += print_while(sp_len, ' ');
	}
	else
	{
		len += print_while(sp_len, ' ');
		len += printf_str(str, flags);
	}
	return (len);
}

int		str_processor(char *str, t_flag *flags)
{
	int		sp_len;
	int		len;
	char	*s;

	len = 0;
	s = NULL;
	if (str == NULL)
	{
		if (!(s = ft_strdup("(null)")))
			return (0);
		else
			str = s;
	}
	if ((flags->width < 0) || (flags->width < ft_strlen(str) && flags->dot == 0)
	|| ((flags->width < flags->presicion)
	&& (ft_strlen(str) >= flags->presicion)))
		sp_len = 0;
	else
		sp_len = sp_if_dot(flags, str);
	len += flag_minus(flags, str, sp_len);
	if (s != NULL)
		free(s);
	return (len);
}
