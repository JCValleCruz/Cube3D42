/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:19:20 by jvalle-d          #+#    #+#             */
/*   Updated: 2025/01/27 11:20:54 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	check_nullzero(t_cube *file)
{
	int	line;
	int	i;

	line = 1;
	while(line < dp_count(file->map + 1))
	{
		i = 1;
		while(file->map[line][i])
		{
			if((file->map[line][i] == '0') && ((file->map[line - 1][i] == '\0' 
				|| file->map[line + 1][i] == '\0' 
					|| file->map[line][i - 1] == '\0' 
						|| file->map[line][i + 1] == '\0'
							|| (size_t)i > ft_strlen(file->map[line - 1])
								|| (size_t)i >= ft_strlen(file->map[line + 1 ]))))
								{
									return (1);
								}
			i++;	
		}
		line++;
	}
	return(0);
}