/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:04:23 by mmonereo          #+#    #+#             */
/*   Updated: 2021/01/13 20:43:39 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void print_width(t_flags *fstruct)
{
	int i;
	char c;

	c = ' ';
	i = fstruct->width - (fstruct->len);
	if (fstruct->left == 0)
	{
		while (i-- > 0)
		{
			write(1, &c, 1);
			fstruct->printed += 1;
		}
		
	}
}

void	is_s(t_flags *f_struct, va_list ap)
{
	char *to_print;
	int len;
	int i;
	
	i = 0;
	to_print = (char *)va_arg(ap, char *);
	if (to_print == NULL)
		to_print = "(null)";
	len = ft_strlen(to_print);
	f_struct->len = len;
	print_width(f_struct);
	while (len--)
	{
		write(1, &to_print[i++], 1);
		f_struct->printed += 1;
	}
	
}