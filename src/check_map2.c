/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:19:20 by jvalle-d          #+#    #+#             */
/*   Updated: 2025/01/29 14:40:33 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	check_nullzero(t_cube *file)
{
	int	line;
	int	i;

	line = 1;
	while (line < dp_count(file->map + 1))
	{
		i = 1;
		while (file->map[line][i])
		{
			if ((file->map[line][i] == '0') && ((file->map[line - 1][i] == '\0' 
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
	return (0);
}

int	broken_map(t_cube *file)
{
	char *str = file->fdcontent;
	int c = dp_count(file->map);
	int i = ft_strlen(str) - 1;
	while (str[i] == '\n')
		i--;
	while (c > 0)
	{
		if (str[i] == '\n')
			c--;
		i--;	
	}
	while (str[i] == '\n')
		i--;
	while (str[i] != '\n')
		i--;
	i++;
	while (str[i] == ' ')
		i++;
	char *temp;

	temp = ft_substr(str, i, 3);
	if (!ft_strncmp(temp, "NO ", 3) || !ft_strncmp(temp, "SO ", 3)
		|| !ft_strncmp(temp, "WE ", 3) || !ft_strncmp(temp, "EA ", 3)
		|| !ft_strncmp(temp, "F ", 2) || !ft_strncmp(temp, "C ", 2))
		return (free(temp), 0);
	return (free(temp), 1);
}
