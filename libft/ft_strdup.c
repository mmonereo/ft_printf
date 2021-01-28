/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 17:04:15 by mmonereo          #+#    #+#             */
/*   Updated: 2020/10/20 17:24:11 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(const char *dest, const char *src)
{
	char	*dst;
	size_t	i;

	i = 0;
	dst = (char *)dest;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char	*ft_strnew(size_t size)
{
	char	*new;

	if (!(new = malloc(sizeof(char) * size)))
		return (NULL);
	ft_memset(new, '\0', size);
	return (new);
}

char		*ft_strdup(const char *s)
{
	char	*new;
	size_t	l;
	size_t	i;

	l = ft_strlen(s);
	i = 0;
	if (!(new = ft_strnew(l + 1)))
		return (NULL);
	new = ft_strcpy(new, s);
	return ((char *)new);
}
