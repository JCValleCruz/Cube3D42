/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:18:57 by jvalle-d          #+#    #+#             */
/*   Updated: 2025/01/27 13:59:23 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cube3d.h"

void	extract_map(t_cube *file)
{
	int		i;
	int		line;
	int		n;

	i = -1;
	line = -1;
	n = 0;
	while(file->dumpcontent[++line])
	{
		i = -1;
		while(file->dumpcontent[line][++i])
		{
			if(file->dumpcontent[line][i] == '1' && file->dumpcontent[line][i + 1] == '1' 
				&& file->all_params_flag == 1)
			{	
				while(file->dumpcontent[line][0] == ' ')
					i++;		
				file->map = (char **)ft_calloc((dp_count(file->dumpcontent) - 5), sizeof(char *));
				while(file->dumpcontent[line])
				{
					file->map[n++] = ft_strdup(file->dumpcontent[line++]);
					if(file->dumpcontent[line] == NULL)
						return;		
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
	while(file->dumpcontent[line])
	{
		str = file->dumpcontent[line];
		if(!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "SO ", 3) 
			|| !ft_strncmp(str, "WE ", 3) || !ft_strncmp(str, "EA ", 3) 
				|| !ft_strncmp(str, "F ", 2) || !ft_strncmp(str, "C ", 2)
					 || !ft_strncmp(str, " ", 1) || !ft_strncmp(str, "1", 1))
				
				line++;		
		else
			return 1;				
	}
	return 0;
}
