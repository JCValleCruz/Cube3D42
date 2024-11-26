/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:51:09 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/11/26 12:01:04 by jormoral         ###   ########.fr       */
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

/* void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] != to_fill)
		return ;
	tab[cur.y][cur.x] = 'X';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
} */

char	**clone_map(char **map)
{
	int		line;
	int 	size;
	char	**result;

	size = dp_count(map);
	result = (char **)malloc(sizeof(char *) * size + 1);
	line = -1;
	while(map[++line])
		result[line] = ft_strdup(map[line]);
	return (result);
}

int	ft_strchrplayer(const char *s, int c, s_cube *file)
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


