/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:16:42 by mmonereo          #+#    #+#             */
/*   Updated: 2021/01/26 17:10:12 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	is_u(t_flags *f_struct, va_list ap)
{
	intmax_t	arg;
	char		*to_print;
	int			i;

	i = 0;
	arg = (unsigned int)va_arg(ap, unsigned int);
	if (arg == 0 && f_struct->is_precision == 1 && f_struct->precision == 0)
	{
		valprec_z(f_struct);
		return ;
	}
	to_print = ft_itoa_base(arg, 10);
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
