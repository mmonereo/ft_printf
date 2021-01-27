/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:26:12 by mmonereo          #+#    #+#             */
/*   Updated: 2021/01/27 10:39:40 by mmonereo         ###   ########.fr       */
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

void	lenint_z(t_flags *fstruct)
{
	int len;

	len = 0;
	fstruct->len = len;
	if (fstruct->is_precision != 0)
	{
		if (fstruct->precision > len)
			fstruct->zeroes = fstruct->precision - len;
	}
}

void	valprec_z(t_flags *f_struct)
{
	lenint_z(f_struct);
	printi_width(f_struct);
	printi_left(f_struct);
}
