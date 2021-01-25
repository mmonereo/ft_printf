/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 12:45:42 by mmonereo          #+#    #+#             */
/*   Updated: 2021/01/21 15:45:00 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_0x(t_flags *fstruct)
{
	char *c;
	int i;
	
	i = 0;
	c = "0x";
	while (c[i] != '\0')
	{
		write(1, &c[i++], 1);
		fstruct->printed += 1;
	}
	
}
void	is_p(t_flags *f_struct, va_list ap)
{
	int					i;
	char				*to_print;
	unsigned long long	p;

	i = 0;
	p = 0;
	p = (unsigned long long) va_arg(ap, void *);
	to_print = ft_itoa_base(p, 16);
	f_struct->is_precision = 0;
	get_len(f_struct, to_print);
	f_struct->len +=2;
	print_width(f_struct);
	print_0x(f_struct);
	while (to_print[i] != '\0')
	{
		write(1, &to_print[i++], 1);
		f_struct->printed += 1;
	}
	print_left(f_struct);
	free(to_print);
}