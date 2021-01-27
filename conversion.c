/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:57:18 by mmonereo          #+#    #+#             */
/*   Updated: 2021/01/27 10:33:16 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion(char *format, t_flags *fstruct, va_list ap)
{
	if (format[fstruct->pos] == 's')
		is_s(fstruct, ap);
	else if (format[fstruct->pos] == 'c')
		is_c(fstruct, ap);
	else if (format[fstruct->pos] == ('i') || format[fstruct->pos] == ('d'))
		is_i(fstruct, ap);
	else if (format[fstruct->pos] == 'u')
		is_u(fstruct, ap);
	else if (format[fstruct->pos] == 'p')
		is_p(fstruct, ap);
	else if (format[fstruct->pos] == 'x')
		is_x(fstruct, ap);
	else if (format[fstruct->pos] == 'X')
	{
		fstruct->upper = 1;
		is_x(fstruct, ap);
	}
	else if (format[fstruct->pos] == '%')
		is_perc(fstruct);
}

void	modifiers(char *format, t_flags *fstruct, va_list ap)
{
	flags(format, fstruct);
	width(format, fstruct, ap);
	precision(format, fstruct, ap);
}
