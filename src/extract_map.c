/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:18:57 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/11/18 23:57:25 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cube3d.h"

void	extract_map(s_cube	*file)
{
	int		line;
	int		mapsize;
	char	*str;
	int		i;
	int		n;

	line = 0;
	i = 0;
	n = 0;
	file->map = NULL;
	while(file->dumpcontent[line])
	{
		str = file->dumpcontent[line];
		while(str[i])
		{
			if (str[i] && str[i] == '1' && str[i + 1] == '1' && str[i + 2] == '1' 
				&& file->all_params_flag == 1)
			{
				mapsize =  dp_count(file->dumpcontent + 1) - line;
				file->map = (char **)malloc(sizeof(char *) * mapsize);
				while(n < (dp_count(file->dumpcontent) - line))
				{
					str = ft_strdup(file->dumpcontent[line]);
					file->map[n] = str;
					n++;
					line++;
					free(str);
				}
			}	
			i++;
		}
		line++;
	}
	file->map[n] = NULL;
}
