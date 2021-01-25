/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:06:02 by mmonereo          #+#    #+#             */
/*   Updated: 2021/01/22 01:51:12 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_atoi(const char *str)
{
	int res;
	int neg;
	int i;

	res = 0;
	neg = 1;
	i = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		++i;
	if (str[i] == '-')
	{
		neg = -1;
		++i;
	}
	else if (str[i] == '+')
	{
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * neg);
}

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