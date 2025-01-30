/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:51:09 by jvalle-d          #+#    #+#             */
/*   Updated: 2025/01/30 10:24:42 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	dp_count_space(char **dp)
{
	int		line;
	int		i;
	int		spaces;
	char	*str;

	line = 0;
	i = 0;
	spaces = 0;
	while (dp[line])
	{
		i = 0;
		str = dp[line];
		while (str[i])
		{
			if (str[i] == ' ')
				spaces++;
			i++;
		}
		line++;
	}
	return (spaces);
}

void	clone_map(t_cube *file)
{
	int		line;
	int		size;
	int		i;

	size = dp_count(file->map);
	file->map_height = size;
	file->clone_map = (char **)malloc(sizeof(char *) * size + 1);
	line = -1;
	while (file->map[++line])
		file->clone_map[line] = ft_strdup(file->map[line]);
	line = 0;
	while (file->map[line])
	{
		i = 0;
		while (file->clone_map[line][i])
		{
			if (file->clone_map[line][i] == 'N'
				|| file->clone_map[line][i] == 'S'
				|| file->clone_map[line][i] == 'W' ||
					file->clone_map[line][i] == 'E')
				file->clone_map[line][i] = '0';
			i++;
		}
		line++;
	}
}

int	ft_strchrplayer(const char *s, int c, t_cube *file)
{
	const char	*str;
	int			i;

	str = s;
	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
		{
			file->orientation = (char)c;
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_cf_str_n(char *str)
{
	int	i;
	int	n;

	n = 1;
	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i - n] == ' ' || str[i - n] == '\t')
	{
		str[i - n] = str[i];
		n++;
	}
	return (str);
}

int	check_player_location(t_cube *file)
{
	int	line;
	int	i;

	line = 1;
	while (line < dp_count(file->map + 1))
	{
		i = 1;
		while (file->map[line][i])
		{
			if ((file->map[line][i] == file->orientation)
			&& ((file->map[line - 1][i] != '0')
			|| (file->map[line - 1][i] != '1')
			|| file->map[line + 1][i] != '0' || file->map[line + 1][i] != '1'
			|| file->map[line][i - 1] != '0' || file->map[line][i - 1] != '1'
			|| file->map[line][i + 1] != '0' || file->map[line][i + 1] != '1'))
			{
				return (1);
			}
			i++;
		}
		line++;
	}
	return (0);
}
