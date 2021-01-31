/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aemustaf <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:50:13 by aemustaf          #+#    #+#             */
/*   Updated: 2020/12/03 11:50:15 by aemustaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "../includes/libft.h"
# define MAX(a, b) (((a) > (b)) ? (a) : (b))
# define MIN(a, b) (((a) < (b)) ? (a) : (b))

int				ft_printf(const char *format, ...);

typedef	struct	s_flag
{
	int width;
	int type;
	int minus;
	int zero;
	int presicion;
	int dot;
}				t_flag;

void			if_neg_w(t_flag *flags);
int				ptr_processor(unsigned long long a, t_flag *flags);
int				prc_processor(t_flag *flags);
void			ft_putnbr_fd_p(int n, int fd);
int				str_processor(char *str, t_flag *flags);
int				hex_processor(unsigned int a, t_flag *flags);
int				ft_parser(const char *format, va_list *ap, t_flag *flags);
int				processor(va_list *ap, t_flag *flags);
int				printf_decimal_int(int a, t_flag *flags);
int				printf_char(int c, t_flag *flags);
int				print_while(int a, char b);
void			ft_putnbr_ptf(int n, int fd);
void			ft_putnbr_u_fd(unsigned int n, int fd);
int				u_int_len(unsigned int a);
int				int_len(int a);
void			if_neg_w(t_flag *flags);
int				if_negative(int a);

#endif
