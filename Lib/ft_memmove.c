/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:19:06 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/05/08 12:28:16 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dest;
	s = src;
	if (dest == src || n == 0)
		return (dest);
	if (d < s && d + n > s)
	{
		while (n--)
			*d++ = *s++;
	}
	else if (s < d && s + n > d)
	{
		d += n;
		s += n;
		while (n--)
			*--d = *--s;
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>



int main() {
    char buffer[] = "Hello, world!";
    ft_memmove(buffer + 5, buffer, 7);
    printf("%s\n", buffer);
    return 0;
}*/
