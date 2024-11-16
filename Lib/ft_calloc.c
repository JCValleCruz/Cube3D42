/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:30:05 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/05/08 12:28:05 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*p;
	char	*ptr;
	size_t	i;

	p = malloc(num * size);
	if (!p)
	{
		return (NULL);
	}
	ptr = (char *)p;
	i = 0;
	while (i < num * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (p);
}
