/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:30:13 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/04/22 11:55:06 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*str;

	str = s;
	while (*str != '\0')
	{
		str++;
	}
	while (str >= s)
	{
		if (*str == (unsigned char)c)
		{
			return ((char *)str);
		}
		str--;
	}
	if (c == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}

/*

int main(void)
{
    char *datos = ft_strrchr("JuJan", 'J');    
    printf("%s\n", datos);
    return 0;
}
*/
