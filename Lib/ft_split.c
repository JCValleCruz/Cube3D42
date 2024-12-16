/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:36:42 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/05/08 12:26:54 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_numwords(const char *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		if (*s != c)
		{
			words++;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (words);
}

static void	free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	size_t	i;
	size_t	len;

	ret = malloc(sizeof(char *) * (ft_numwords(s, c) + 1));
	if (!s || !ret)
		return (0);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			ret[i++] = ft_substr(s - len, 0, len);
			if (!ret[i - 1])
				return (free_split(ret), NULL);
		}
		else
			++s;
	}
	ret[i] = 0;
	return (ret);
}
