/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 11:19:20 by jvalle-d          #+#    #+#             */
/*   Updated: 2025/01/29 16:30:49 by jormoral         ###   ########.fr       */
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
				|| (size_t)i >= ft_strlen(file->map[line + 1]))))
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
	char	*temp;
	int		c;
	int		i;

	c = dp_count(file->map);
	i = ft_strlen(file->fdcontent) - 1;
	while (file->fdcontent[i] == '\n')
		i--;
	while (c > 0)
	{
		if (file->fdcontent[i] == '\n')
			c--;
		i--;
	}
	while (file->fdcontent[i] == '\n')
		i--;
	while (file->fdcontent[i] != '\n')
		i--;
	i++;
	while (file->fdcontent[i] == ' ')
		i++;
	temp = ft_substr(file->fdcontent, i, 3);
	if (!search_header(temp))
		return (free(temp), 0);
	return (free(temp), 1);
}
