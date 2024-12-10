/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:51:09 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/12/10 12:32:30 by jvalle-d         ###   ########.fr       */
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

void clone_map(s_cube *file)
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


