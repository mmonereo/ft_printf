/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:47:29 by mmonereo          #+#    #+#             */
/*   Updated: 2020/10/20 17:20:01 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*new;

	i = 0;
	new = (char *)malloc(len * sizeof(char) + 1);
	if (new == 0)
	{
		return (NULL);
	}
	while (i < start)
	{
		i++;
	}
	if (start > ft_strlen(s))
	{
		new[0] = '\0';
		return (new);
	}
	ft_memcpy(&new[0], &s[i], (len * sizeof(char)));
	new[len] = 0;
	return (new);
}
