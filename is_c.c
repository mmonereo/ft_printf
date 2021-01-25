/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:31:26 by mmonereo          #+#    #+#             */
/*   Updated: 2021/01/21 16:47:11 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_len_c(t_flags *fstruct, unsigned char *to_print)
{
	int len;

	len = ft_strlen((char *)to_print);
	fstruct->len = 1;
	if (fstruct->is_precision != 0)
	{
		if (fstruct->precision < len)
			fstruct->len = fstruct->precision;
	}
	return (fstruct->len);
}

void	is_c(t_flags *f_struct, va_list ap)
{
	unsigned char to_print;
	int i;
	int len;
	
	i = 0;
	to_print = (unsigned char)va_arg(ap, int);
	len = get_len_c(f_struct, &to_print);
	print_width(f_struct);
	while (len--)
	{
		write(1, &to_print, 1);
		f_struct->printed += 1;
	}
	print_left(f_struct);
}