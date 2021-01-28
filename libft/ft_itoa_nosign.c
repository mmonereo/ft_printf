/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_nosign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:45:01 by mmonereo          #+#    #+#             */
/*   Updated: 2021/01/28 13:49:57 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(unsigned int n)
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

char		*ft_itoa_nosign(int n)
{
	unsigned int	len;
	unsigned int	i;
	char			*res;
	unsigned int	num;

	num = n;
	if (n < 0)
		num = n * -1;
	len = ft_numlen(num);
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
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
