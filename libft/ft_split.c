/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonereo <mmonereo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:32:49 by mmonereo          #+#    #+#             */
/*   Updated: 2020/10/30 15:57:07 by mmonereo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int		i;
	int		count;
	int		stop;

	i = 0;
	count = 0;
	stop = 0;
	while (s[i] != '\0')
	{
		if ((s[i] == c) && (stop == 1))
			stop = 0;
		if ((stop == 0) && (s[i] != c))
		{
			stop = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static int	ft_wordlen(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while ((s[i] != c) && (s[i] != '\0'))
	{
		i++;
		len++;
	}
	return (len);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		wordc;
	char	**new;

	i = 0;
	if (s && *s)
		wordc = ft_wordcount(s, c);
	else
		wordc = 0;
	new = (char **)malloc((wordc + 1) * sizeof(char *));
	if (new == NULL)
		return (NULL);
	while (wordc--)
	{
		while ((*s == c) && (*s != '\0'))
			s++;
		new[i] = ft_substr(s, 0, ft_wordlen(s, c));
		if (new[i] == NULL)
			return (NULL);
		s = s + ft_wordlen(s, c);
		i++;
	}
	new[i] = NULL;
	return (new);
}
