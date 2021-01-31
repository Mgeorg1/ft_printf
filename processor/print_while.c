/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_while.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemustaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:47:11 by aemustaf          #+#    #+#             */
/*   Updated: 2020/12/21 17:47:14 by aemustaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		print_while(int a, char c)
{
	int b;

	b = a;
	if (a <= 0)
		return (0);
	while (a--)
		ft_putchar_fd(c, 1);
	return (b);
}
