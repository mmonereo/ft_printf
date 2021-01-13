/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:15:09 by mmonereo          #+#    #+#             */
/*   Updated: 2021/01/13 20:36:46 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

# define	SYMBOLS	"-0123456789s"
# define	CONVERSIONS	"s"
# define	MODIFIERS "-.0123456789"

typedef struct	s_flags
{
	int		printed;
	int		pos;
	int		len;
	int		left;
	int		width;
	int		precision;
	int		done;
}	t_flags;

int		ft_printf	(const char *format, ...);
void	struct_init	(t_flags *flags);
void	struct_reset(t_flags *flags);
int		mod_parse	(char *format, t_flags *fstruct, va_list ap);
int		parse		(char *format, t_flags *fstruct, va_list ap);
void	modifiers	(char *format, t_flags *fstruct);
void	flags		(char *format, t_flags *fstruct);
void	conversion	(char *format, t_flags *fstruct, va_list ap);
void	width		(char *format, t_flags *fstruct);
void	is_s		(t_flags *f_struct, va_list ap);

size_t	ft_strlen	(char* str);
int		ft_atoi		(const char *str);

#endif