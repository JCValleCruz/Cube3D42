/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:51:09 by jvalle-d          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/12/10 19:44:00 by jvalle-d         ###   ########.fr       */
=======
/*   Updated: 2024/12/05 18:28:27 by jormoral         ###   ########.fr       */
>>>>>>> main
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

<<<<<<< HEAD
void clone_map(s_cube *file)
=======
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

void clone_map(t_cube *file)
>>>>>>> main
{
	int		line;
	int 	size;
	int		i;
	
	size = dp_count(file->map);
	file->clone_map = (char **)malloc(sizeof(char *) * size + 1);
	line = -1;
	while(file->map[++line])
		file->clone_map[line] = ft_strdup(file->map[line]);
	line = 0;
	while(file->map[line])
	{
		i = 0;
		while(file->clone_map[line][i])
		{
			if(file->clone_map[line][i] == 'N' || file->clone_map[line][i] == 'S' 
				|| file->clone_map[line][i] == 'W' || file->clone_map[line][i] == 'E')
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

int	jclean(char *str, s_cube *file)
{
	int		i;
	
	i = 0;
	file->map_flag = 0;
	while(str[i])
	{
		if(str[i] == '1' && str[i + 1] == '1' && str[i + 2] == '1' 
			&& (str[i + 3] == '1' || str[i + 3] == '0'))
			file->map_flag = 1;
		if(str[i] == '\n' && str[i + 1] == '\n' && file->map_flag == 1)
			return 0;
		i++;	
	}
	return 1;
}



