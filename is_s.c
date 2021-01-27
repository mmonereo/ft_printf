/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:04:23 by mmonereo          #+#    #+#             */
/*   Updated: 2021/01/27 10:43:34 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_width(t_flags *fstruct)
{
	int		i;
	char	c;

	if (fstruct->left == 0)
	{
		c = ' ';
		i = fstruct->width - (fstruct->len);
		while (i-- > 0)
		{
			write(1, &c, 1);
			fstruct->printed += 1;
		}
	}
}

void	print_left(t_flags *fstruct)
{
	int		i;
	char	c;

	if (fstruct->left == 1)
	{
		c = ' ';
		i = fstruct->width - (fstruct->len);
		while (i-- > 0)
		{
			write(1, &c, 1);
			fstruct->printed += 1;
		}
	}
}

int		get_len(t_flags *fstruct, char *to_print)
{
	int len;

	len = ft_strlen(to_print);
	fstruct->len = len;
	if (fstruct->is_precision != 0)
	{
		if (fstruct->precision < len)
			fstruct->len = fstruct->precision;
	}
	return (fstruct->len);
}

void	is_s(t_flags *f_struct, va_list ap)
{
	char	*to_print;
	int		i;
	int		len;

	i = 0;
	to_print = (char *)va_arg(ap, char *);
	if (to_print == NULL)
		to_print = "(null)";
	len = get_len(f_struct, to_print);
	print_width(f_struct);
	while (len--)
	{
		write(1, &to_print[i++], 1);
		f_struct->printed += 1;
	}
	print_left(f_struct);
}
