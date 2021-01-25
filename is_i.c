/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_i.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 15:27:13 by mmonereo          #+#    #+#             */
/*   Updated: 2021/01/22 02:23:42 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_numlen(unsigned int n)
{
	unsigned int len;

	len = 0;
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len + 1);
}

static unsigned int	ft_numselect(int n, unsigned int *num)
{
	unsigned int len;

	if (n < 0)
	{
		*num = (unsigned int)(n * -1);
		len = ft_numlen(*(num));
		len = len + 1;
	}
	else
	{
		len = ft_numlen(*(num));
	}
	return (len);
}

char				*ft_itoa(int n)
{
	unsigned int	num;
	unsigned int	len;
	unsigned int	i;
	char			*res;

	num = n;
	len = ft_numselect(n, &num);
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
	{
		return (NULL);
	}
	if (n < 0)
	{
		res[0] = '-';
	}
	i = len - 1;
	while (num >= 10)
	{
		res[i] = (char)(num % 10 + 48);
		num = num / 10;
		i--;
	}
	res[i] = (char)(num + 48);
	res[len] = '\0';
	return (res);
}

void signzero(t_flags *fstruct, int arg)
{
	char c;
	int i;

	i = 0;
	c = '-';
	if (fstruct->neg == 1 && arg)
	{
		write(1, &c, 1);
		fstruct->printed += 1;
	}
	if (fstruct->zeroes)
	{
		i = fstruct->zeroes;
		c = '0';
		while (i-- > 0)
		{
			write(1, &c, 1);
			fstruct->printed += 1;
		}
	}	
}

void	printi_width(t_flags *fstruct)
{
	int		i;
	char	c;
 
	if (fstruct->left == 0 && fstruct->width)
	{
		c = ' ';
		if (fstruct->zeroes)
			i = fstruct->width - (fstruct->precision);
		else
			i = fstruct->width - (fstruct->len);
		if (fstruct->is_zero == 1 && fstruct->is_precision == 0)
		{	
			fstruct->zeroes = fstruct->width - (fstruct->len);
			if (fstruct->neg == 1)
				fstruct->zeroes -= 1;
			i = 0;
		}
		if (fstruct->neg == 1)
			i -= 1;
		while (i-- > 0)
		{
			write(1, &c, 1);
			fstruct->printed += 1;
		}
	}
}

void	printi_left(t_flags *fstruct)
{
	int		i;
	char	c;

	if (fstruct->left == 1)
	{
		c = ' ';
		if (fstruct->zeroes)
			i = fstruct->width - (fstruct->precision);
		else
			i = fstruct->width - (fstruct->len);
		if (fstruct->neg == 1)
			i -= 1;
		while (i-- > 0)
		{
			write(1, &c, 1);
			fstruct->printed += 1;
		}
	}
}

void	lenint(t_flags *fstruct, char *to_print)
{
	int len;

	len = ft_strlen(to_print);
	fstruct->len = len;
	if (fstruct->is_precision != 0)
	{
		if (fstruct->precision > len)
			fstruct->zeroes = fstruct->precision - len;
	}	
}

void	lenint_z(t_flags *fstruct)
{
	int len;

	len = 0;
	fstruct->len = len;
	if (fstruct->is_precision != 0)
	{
		if (fstruct->precision > len)
			fstruct->zeroes = fstruct->precision - len;
	}	
}


void	valprec_z(t_flags *f_struct)
{
	lenint_z(f_struct);
	printi_width(f_struct);
	printi_left(f_struct);
} 

void	is_i(t_flags *f_struct, va_list ap)
{
	intmax_t arg;
	char *to_print;
	int i;
	
	arg = 0;
	i = 0;
	arg = (int)va_arg(ap, int);
	if (arg < 0 || arg == -2147483648)
	{
		f_struct->neg = 1;
			arg = arg * -1;
	}
	if (arg == 0 && f_struct->is_precision == 1 && f_struct->precision == 0)
	{
		valprec_z(f_struct);
		return;
	}
	to_print = ft_itoa(arg);
	lenint(f_struct, to_print);
	printi_width(f_struct);
	signzero(f_struct, arg);
	while (to_print[i] != '\0')
	{
		write(1, &to_print[i++], 1);
		f_struct->printed += 1;
	}
	printi_left(f_struct);
	free(to_print);
}

