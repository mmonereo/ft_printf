/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:07:45 by mmonereo          #+#    #+#             */
/*   Updated: 2020/10/20 16:41:14 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;
	int		check;

	a = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[a] != '\0')
	{
		b = -1;
		check = 1;
		while (++b < ft_strlen(needle))
			if (needle[b] != haystack[a + b])
				check = 0;
		if (check && a + b <= len)
			return ((char *)haystack + a);
		a++;
	}
	return (0);
}
