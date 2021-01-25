/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_perc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 01:34:54 by mmonereo          #+#    #+#             */
/*   Updated: 2021/01/22 01:51:37 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percz(t_flags *fstruct)
{
	int		i;
	char	c;

	if (fstruct->left == 0)
	{
		c = '0';
		i = fstruct->width - (fstruct->len);
		while (i-- > 0)
		{
			write(1, &c, 1);
			fstruct->printed += 1;
		}
	}
}

void	is_perc(t_flags *f_struct)
{
	char c;
	int i;

	i = 0;
	c = '%';
	f_struct->len = 1;
	if (f_struct->is_zero == 1 && f_struct->left == 0)
		print_percz(f_struct);
	else
		print_width(f_struct);
	write(1, &c, 1);
	f_struct->printed += 1;
	printi_left(f_struct);
}