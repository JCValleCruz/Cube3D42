/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:18:57 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/11/26 17:11:13 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cube3d.h"

void	extract_map(s_cube *file)
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
				file->map = (char **)ft_calloc((dp_count(file->dumpcontent) - 6), sizeof(char *));
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

