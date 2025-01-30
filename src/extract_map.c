/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:18:57 by jvalle-d          #+#    #+#             */
/*   Updated: 2025/01/29 16:46:06 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	extract_map(t_cube *file)
{
	int		i;
	int		line;
	int		n;

	line = -1;
	n = 0;
	while (file->dc[++line])
	{
		i = -1;
		while (file->dc[line][++i])
		{
			if (file->dc[line][i] == '1' && file->dc[line][i + 1] == '1'
			&& file->apflag == 1 && file->dc[line][0] != 'F'
			&& file->dc[line][0] != 'C')
			{
				file->map = ft_calloc((dp_count(file->dc) - 5), sizeof(char *));
				while (file->dc[line])
				{
					file->map[n++] = ft_strdup(file->dc[line++]);
					if (file->dc[line] == NULL)
						return ;
				}
			}
		}
	}
}

int	check_invalid_line(t_cube *file)
{
	char	*str;
	int		line;

	line = 0;
	while (file->dc[line])
	{
		str = file->dc[line];
		if (!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "SO ", 3)
			|| !ft_strncmp(str, "WE ", 3) || !ft_strncmp(str, "EA ", 3)
			|| !ft_strncmp(str, "F ", 2) || !ft_strncmp(str, "C ", 2)
			|| !ft_strncmp(str, " ", 1) || !ft_strncmp(str, "1", 1))
			line++;
		else
			return (1);
	}
	return (0);
}
