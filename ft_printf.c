/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 11:38:27 by mmonereo          #+#    #+#             */
/*   Updated: 2021/01/13 20:45:09 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

size_t ft_strlen(char* str)
{
	size_t i; 
	
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return(i);
}

void	*ft_memcpy(void *dst, const void *src, size_t size)
{
	unsigned char		*dest;
	const unsigned char	*source;

	dest = (unsigned char *)dst;
	source = (const unsigned char *)src;
	while (size--)
	{
		*dest++ = *source++;
	}
	return ((unsigned char *)dst);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != c)
	{
		s++;
	}
	if (*s == (char)c)
	{
		return ((char *)s);
	}
	return (NULL);
}


void	struct_init(t_flags *flags)
{
	flags->printed = 0;
	flags->left = 0;
	flags->width = 0;
	flags->len = 0;
	flags->pos = 0;
	flags->done = 0;
}

void	struct_reset(t_flags *flags)
{
	flags->left = 0;
	flags->width = 0;
	flags->len = 0;
}

int	mod_parse (char *format, t_flags *fstruct, va_list ap)
{
	if (ft_strchr(CONVERSIONS, format[fstruct->pos]))
	{
		conversion(format, fstruct, ap);
		fstruct->done = 1;
		struct_reset(fstruct);
	}
	else if (ft_strchr(MODIFIERS, format[fstruct->pos]))
	{
		modifiers(format, fstruct);
	}
	return (fstruct->pos);
}

int	parse(char *format, t_flags *fstruct, va_list ap)
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
				while (ft_strchr(SYMBOLS, format[fstruct->pos]) && (fstruct->done == 0))
				{
					// printf("in the lop\n");
					// printf("pos lop: %i\n", fstruct->pos);
					fstruct->pos = mod_parse(format, fstruct, ap);
				}	
			}
		}
		fstruct->done = 0;
		fstruct->pos++;
	}
	return(fstruct->printed);
}

int	ft_printf(const char *format, ...)
{
	va_list ap;
	int final_count;
	char *save;
	t_flags *fl_struct;
	
	final_count = 0;
	save = strdup(format);
	if (!(fl_struct = malloc(sizeof(t_flags))))
		return(0);
	struct_init(fl_struct);
	va_start(ap, format);
	final_count = parse(save, fl_struct, ap);
	va_end(ap);
	free(fl_struct);
	return(final_count);
}





