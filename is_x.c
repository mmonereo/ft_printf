/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:17:14 by mmonereo          #+#    #+#             */
/*   Updated: 2021/01/27 11:12:33 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	is_x(t_flags *f_struct, va_list ap)
{
	uintmax_t	arg;
	char		*to_print;
	int			i;

	i = 0;
	arg = (unsigned int)va_arg(ap, unsigned int);
	if (arg == 0 && f_struct->is_precision == 1 && f_struct->precision == 0)
	{
		valprec_z(f_struct);
		return ;
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
