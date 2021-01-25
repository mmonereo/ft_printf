/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:17:14 by mmonereo          #+#    #+#             */
/*   Updated: 2021/01/22 02:12:29 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(uintmax_t value, uintmax_t base)
{
	char				*s;
	unsigned long long	n;
	int					i;

	i = 1;
	n = value;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = value;
	while (i-- > 0)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
		n /= base;
	}
	return (s);
}

char	*ft_itoa_base_upper(intmax_t value, intmax_t base)
{
	char				*s;
	long long			n;
	int					sign;
	int					i;

	n = (value < 0) ? -value : value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = (value < 0) ? -value : value;
	while (i-- + sign)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		n /= base;
	}
	(i == 0) ? s[i] = '-' : 0;
	return (s);
}

void	is_x(t_flags *f_struct, va_list ap)
{
	uintmax_t arg;
	char *to_print;
	int i;
	
	arg = 0;
	i = 0;
	arg = (unsigned int)va_arg(ap, unsigned int);
	if (arg == 0 && f_struct->is_precision == 1 && f_struct->precision == 0)
	{
		valprec_z(f_struct);
		return;
	}
	if (f_struct->upper == 1)
		to_print = ft_itoa_base_upper(arg, 16);
	else
		to_print = ft_itoa_base(arg, 16);
	lenint(f_struct, to_print);
	printi_width(f_struct);
	signzero(f_struct, 0);
	while (to_print[i] != '\0')
	{
		write(1, &to_print[i++], 1);
		f_struct->printed += 1;
	}
	printi_left(f_struct);
	free(to_print);
}