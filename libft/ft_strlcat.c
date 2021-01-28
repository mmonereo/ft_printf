/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:04:32 by mmonereo          #+#    #+#             */
/*   Updated: 2020/09/21 17:14:18 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t srclen;
	size_t check;
	size_t s;

	i = 0;
	srclen = 0;
	check = 0;
	s = size;
	while (dst[i] != 0 && s--)
		i++;
	check = size - i;
	if (check == 0)
	{
		return (size + ft_strlen(src));
	}
	while (src[srclen] && size > i + 1)
	{
		dst[i + srclen] = src[srclen];
		srclen++;
		size--;
	}
	dst[i + srclen] = 0;
	return (i + ft_strlen(src));
}
