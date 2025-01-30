/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:49:40 by jvalle-d          #+#    #+#             */
/*   Updated: 2025/01/28 14:45:46 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (start > ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s) - start)
		len = (ft_strlen(s) - start);
	sub = malloc(len + 1);
	if (!s || !sub)
	{
		return (NULL);
	}
	while (s[i] != '\0' && i < len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}
