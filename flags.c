/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:06:02 by mmonereo          #+#    #+#             */
/*   Updated: 2021/01/29 09:49:31 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags(char *format, t_flags *fstruct)
{
	while (ft_strchr("-0", format[fstruct->pos]))
	{
		if (format[fstruct->pos] == '-')
			fstruct->left = 1;
		else if (format[fstruct->pos] == '0')
			fstruct->is_zero = 1;
		fstruct->pos += 1;
	}
}

void	widthstar(char *format, t_flags *fstruct, va_list ap)
{
	int wstar;

	if (format[fstruct->pos] == '*')
	{
		wstar = va_arg(ap, int);
		fstruct->width = wstar;
		if (wstar < 0)
		{
			fstruct->left = 1;
			fstruct->width = wstar * -1;
		}
		while (format[fstruct->pos] == '*')
			fstruct->pos++;
	}
}

void	width(char *format, t_flags *fstruct, va_list ap)
{
	widthstar(format, fstruct, ap);
	if (format[fstruct->pos] >= '0' && format[fstruct->pos] <= '9')
	{
		fstruct->width = ft_atoi(&format[fstruct->pos]);
	}
	while (format[fstruct->pos] >= '0' && format[fstruct->pos] <= '9')
	{
		fstruct->pos++;
	}
}

void	precstar(char *format, t_flags *fstruct, va_list ap)
{
	int pstar;

	pstar = va_arg(ap, int);
	if (pstar < 0)
		fstruct->is_precision = 0;
	else if (pstar >= 0)
		fstruct->precision = pstar;
	if (format[fstruct->pos] == '*')
		fstruct->pos++;
}

void	precision(char *format, t_flags *fstruct, va_list ap)
{
	if (format[fstruct->pos] == '.')
	{
		fstruct->is_precision = 1;
		fstruct->pos++;
		if (format[fstruct->pos] >= '0' && format[fstruct->pos] <= '9')
		{
			fstruct->precision = ft_atoi(&format[fstruct->pos]);
			while (format[fstruct->pos] >= '0' && format[fstruct->pos] <= '9')
				fstruct->pos++;
		}
		else if (format[fstruct->pos] == '*')
			precstar(format, fstruct, ap);
	}
}
