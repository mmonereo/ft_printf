/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:38:27 by mmonereo          #+#    #+#             */
/*   Updated: 2021/01/27 10:38:34 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	struct_init(t_flags *flags)
{
	flags->printed = 0;
	flags->left = 0;
	flags->width = 0;
	flags->neg = 0;
	flags->zeroes = 0;
	flags->is_zero = 0;
	flags->len = 0;
	flags->pos = 0;
	flags->precision = 0;
	flags->is_precision = 0;
	flags->upper = 0;
	flags->done = 0;
}

void	struct_reset(t_flags *flags)
{
	flags->left = 0;
	flags->width = 0;
	flags->neg = 0;
	flags->zeroes = 0;
	flags->is_zero = 0;
	flags->len = 0;
	flags->precision = 0;
	flags->is_precision = 0;
	flags->upper = 0;
}

int		mod_parse(char *format, t_flags *fstruct, va_list ap)
{
	if (ft_strchr(CONVERSIONS, format[fstruct->pos]))
	{
		conversion(format, fstruct, ap);
		fstruct->done = 1;
		struct_reset(fstruct);
	}
	else if (ft_strchr(MODIFIERS, format[fstruct->pos]))
	{
		modifiers(format, fstruct, ap);
	}
	return (fstruct->pos);
}

int		parse(char *format, t_flags *fstruct, va_list ap)
{
	while (format[fstruct->pos] != '\0')
	{
		if (format[fstruct->pos] && format[fstruct->pos] != '%')
			fstruct->printed += write(1, &format[fstruct->pos], 1);
		if (format[fstruct->pos] == '%')
		{
			if (ft_strchr(SYMBOLS, format[fstruct->pos + 1]))
			{
				fstruct->pos = fstruct->pos + 1;
				while (ft_strchr(SYMBOLS, format[fstruct->pos])
				&& (fstruct->done == 0))
					fstruct->pos = mod_parse(format, fstruct, ap);
			}
		}
		fstruct->done = 0;
		fstruct->pos++;
	}
	return (fstruct->printed);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		final_count;
	char	*save;
	t_flags	*fl_struct;

	final_count = 0;
	save = ft_strdup(format);
	if (!(fl_struct = malloc(sizeof(t_flags))))
		return (0);
	struct_init(fl_struct);
	va_start(ap, format);
	final_count = parse(save, fl_struct, ap);
	va_end(ap);
	free(fl_struct);
	free(save);
	return (final_count);
}
