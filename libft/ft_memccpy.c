/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:01:50 by mmonereo          #+#    #+#             */
/*   Updated: 2020/09/17 17:35:15 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*x;
	unsigned char	*y;
	size_t			i;

	x = (unsigned char *)dest;
	y = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		x[i] = y[i];
		if (y[i++] == (unsigned char)c)
		{
			return (&x[i]);
		}
	}
	return (NULL);
}
