/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:49:40 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/11/18 02:02:25 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *str;
    size_t s_len;
    size_t i;

    if (!s) // Verifica si la cadena es NULL
        return NULL;

    s_len = strlen(s);
    
    // Si 'start' es mayor que la longitud de 's', retorna una cadena vacía
    if (start >= s_len)
        return strdup(""); // strdup crea una copia de la cadena vacía

    // Ajusta 'len' si es necesario
    if (len > s_len - start)
        len = s_len - start;

    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str) // Verifica si la asignación fue exitosa
        return NULL;

    for (i = 0; i < len; i++)
        str[i] = s[start + i];

    str[len] = '\0'; // Asegúrate de terminar la cadena con un null

    return str;
}
