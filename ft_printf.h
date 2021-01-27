/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 17:15:09 by mmonereo          #+#    #+#             */
/*   Updated: 2021/01/27 10:30:24 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>

# define	SYMBOLS	"-.*0123456789siudxXpc%"
# define	CONVERSIONS	"siudxXpc%"
# define	MODIFIERS "-.*0123456789"

typedef struct	s_flags
{
	int		printed;
	int		pos;
	int		len;
	int		neg;
	int		zeroes;
	int		is_zero;
	int		left;
	int		width;
	int		precision;
	int		is_precision;
	int		upper;
	int		done;
}				t_flags;

int		ft_printf	(const char *format, ...);
void	struct_init	(t_flags *flags);
void	struct_reset(t_flags *flags);
int		mod_parse	(char *format, t_flags *fstruct, va_list ap);
int		parse		(char *format, t_flags *fstruct, va_list ap);
void	modifiers	(char *format, t_flags *fstruct, va_list ap);
void	flags		(char *format, t_flags *fstruct);
void	conversion	(char *format, t_flags *fstruct, va_list ap);
void	width		(char *format, t_flags *fstruct, va_list ap);
void	widthstar	(char *format, t_flags *fstruct, va_list ap);
void	precision	(char *format, t_flags *fstruct, va_list ap);
void	precstar	(char *format, t_flags *fstruct, va_list ap);
void	is_s		(t_flags *f_struct, va_list ap);
void	print_width	(t_flags *fstruct);
void	print_left	(t_flags *fstruct);
int		get_len		(t_flags *fstruct, char	*to_print);
void	is_c		(t_flags *f_struct, va_list ap);
void	is_i		(t_flags *f_struct, va_list ap);
void	signzero	(t_flags *fstruct, int arg);
void	printi_width(t_flags *fstruct);
void	printi_left	(t_flags *fstruct);
void	lenint		(t_flags *fstruct, char	*to_print);
void	valprec_z	(t_flags *f_struct);
void	lenint_z	(t_flags *fstruct);
void	is_u		(t_flags *f_struct, va_list ap);
void	is_p		(t_flags *f_struct, va_list ap);
void	print_0x	(t_flags *fstruct);
void	is_x		(t_flags *f_struct, va_list ap);
void	is_perc		(t_flags *f_struct);
void	print_percz	(t_flags *fstruct);

char	*ft_itoa_base(uintmax_t value, uintmax_t base);
char	*ft_itoa_base_upper(intmax_t value, intmax_t base);

#endif