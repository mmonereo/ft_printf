/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:04:50 by mmonereo          #+#    #+#             */
/*   Updated: 2020/10/19 00:51:11 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t x;

	i = 0;
	x = 0;
	if (size == 0)
	{
		return (ft_strlen(src));
	}
	while (src[x] != '\0' && x < size - 1)
	{
		dst[i] = src[x];
		++i;
		++x;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
