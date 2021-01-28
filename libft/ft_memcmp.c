/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:02:31 by mmonereo          #+#    #+#             */
/*   Updated: 2020/09/17 17:37:30 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*first;
	unsigned char	*sec;
	size_t			i;

	first = (unsigned char *)s1;
	sec = (unsigned char *)s2;
	i = 0;
	while (i++ < n)
	{
		if (first[i - 1] != sec[i - 1])
		{
			return (first[i - 1] - sec[i - 1]);
		}
	}
	return (0);
}
