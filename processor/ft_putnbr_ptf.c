/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemustaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 21:15:19 by aemustaf          #+#    #+#             */
/*   Updated: 2020/12/14 21:15:22 by aemustaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr_ptf(int n, int fd)
{
	int		mod;
	int		div;
	char	r;

	if (n == -2147483648)
	{
		write(fd, "2147483648", 10);
		return ;
	}
	if (n < 0)
		n = n * -1;
	mod = n % 10;
	div = n / 10;
	if (div != 0)
		ft_putnbr_ptf(div, fd);
	r = '0' + mod;
	write(fd, &r, 1);
}
