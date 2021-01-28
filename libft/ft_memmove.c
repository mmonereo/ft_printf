/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:03:19 by mmonereo          #+#    #+#             */
/*   Updated: 2020/09/17 17:34:44 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;
	size_t s;

	i = 0;
	s = n;
	if (dest > src)
	{
		while (s > 0)
		{
			((char *)dest)[s - 1] = ((char *)src)[s - 1];
			s--;
		}
		return (dest);
	}
	else
	{
		while (i < s)
		{
			((char *)dest)[i] = ((char *)src)[i];
			++i;
		}
		return (dest);
	}
	return (dest);
}
