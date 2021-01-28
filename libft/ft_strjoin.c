/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:44:31 by mmonereo          #+#    #+#             */
/*   Updated: 2020/09/21 17:46:30 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lenf;
	size_t	lens;
	char	*new;

	lenf = ft_strlen(s1);
	lens = ft_strlen(s2);
	new = (char *)malloc((lenf + lens + 1) * sizeof(char));
	if (new == 0)
	{
		return (NULL);
	}
	ft_memcpy(new, s1, lenf + 1 * sizeof(char));
	ft_strlcat(new, s2, lens + lenf + 1 * sizeof(char));
	return (&new[0]);
}
