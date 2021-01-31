/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemustaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 17:49:59 by aemustaf          #+#    #+#             */
/*   Updated: 2020/12/21 17:50:00 by aemustaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_u_fd(unsigned int n, int fd)
{
	int		mod;
	int		div;
	char	r;

	mod = n % 10;
	div = n / 10;
	if (div != 0)
		ft_putnbr_u_fd(div, fd);
	r = '0' + mod;
	write(fd, &r, 1);
}
