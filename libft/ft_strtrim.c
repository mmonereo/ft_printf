/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:46:03 by mmonereo          #+#    #+#             */
/*   Updated: 2020/10/19 16:52:18 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_sub_u(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*new;

	i = 0;
	new = (char *)malloc(len * sizeof(char));
	if (new == 0)
	{
		return (NULL);
	}
	while (i < start)
	{
		i++;
	}
	ft_memcpy(&new[0], &s[i], (len * sizeof(char)));
	new[len] = '\0';
	return (new);
}

static int		ft_inset(char c, char const *set)
{
	if (ft_strchr(set, c) == 0)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*new;

	len = ft_strlen(s1);
	i = 0;
	while (ft_inset(s1[len - 1], set) == 1)
	{
		len--;
	}
	while (ft_inset(s1[i], set) == 1)
	{
		i++;
		len--;
	}
	if (len < 0)
	{
		len = 0;
	}
	if (!(new = ft_sub_u(s1, i, len)))
		return (NULL);
	new[len] = 0;
	return (new);
}
