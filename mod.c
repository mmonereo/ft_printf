/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:06:02 by mmonereo          #+#    #+#             */
/*   Updated: 2021/01/13 20:13:31 by mmonereo         ###   ########.fr       */
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
}

void	modifiers(char *format, t_flags *fstruct)
{
		flags(format, fstruct);
		width(format, fstruct);
}

void	flags(char *format, t_flags *fstruct)
{
	while (format[fstruct->pos] == '-')
	{
		if (format[fstruct->pos] == '-')
			fstruct->left = 1;
		fstruct->pos += 1;
	}
	
}

void	width(char *format, t_flags *fstruct)
{
	if (format[fstruct->pos] >= '0' && format[fstruct->pos] <= '9')
	{
		fstruct->width = ft_atoi(&format[fstruct->pos]);
	}
	while (format[fstruct->pos] >= '0' && format[fstruct->pos] <= '9')
	{
		fstruct->pos++;
	}
}