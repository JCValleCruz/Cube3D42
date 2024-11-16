/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:52:02 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/04/19 13:45:56 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *string, const char *substring, size_t len)
{
	const char	*s;
	const char	*sub;
	size_t		sub_len;

	s = string;
	sub = substring;
	sub_len = ft_strlen(substring);
	if (*sub == '\0')
		return ((char *)s);
	while (*s != '\0' && len >= sub_len)
	{
		if (ft_strncmp(s, sub, sub_len) == 0)
			return ((char *)s);
		s++;
		len--;
	}
	return (NULL);
}
