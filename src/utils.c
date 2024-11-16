/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:35:10 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/11/16 21:39:55 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void    *ft_checkfinal (s_cube *file)
{
	char *str;

	str = file->fdcontent;
    int i = 0;
    int n = 1;

    while (str[i] != '\0')
        i++;

    while (str[i - n] != '1')
    {
        str[i - n] = str[i];
        n++;
    }
    file->fdcontent = str;
}