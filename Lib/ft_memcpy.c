/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 11:08:04 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/04/19 14:27:14 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char				*d;
	const unsigned char			*o;
	size_t						i;

	d = dest;
	o = src;
	i = 0;
	if (src == NULL && dest == NULL)
	{
		return (NULL);
	}
	while (i < n)
	{
		d[i] = o[i];
		i++;
	}
	if (n < i)
	{
		d[i] = '\0';
	}
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>



int main() {
    char buffer[] = "Hello, world!";
    ft_memcpy(buffer + 5, buffer, 7);
    printf("%s\n", buffer);
    return 0;
}
*/
