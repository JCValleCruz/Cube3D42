/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 02:09:50 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/11/19 17:48:24 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cube3d.h"

int	check_param_dup(s_cube *file)
{
	char	*str;
	int		line;
	int		count;
	
	line = -1;
	count = 0;
	while(file->dumpcontent[++line])
	{
		str = file->dumpcontent[line];
		if(!ft_strncmp(str, "NO", 2) || !ft_strncmp(str, "SO", 2) 
			|| !ft_strncmp(str, "WE", 2) || !ft_strncmp(str, "EA", 2) 
				|| !ft_strncmp(str, "F ", 2) || !ft_strncmp(str, "C ", 2))
			count++;			
	}
	if (count != 6)
		return 1;
	return 0;
}

int		all_params(s_cube *file)
{
	file->rgb_flag = 0;
	file->texture_flag = 0;
	file->all_params_flag = 0;
	purge(file);
	if(check_param_dup(file))
		exit_error("Error: CUB file does not have the correct parameters.\n", 1);
	if(extract_textures(file))
		exit_error("Error: Cannot load path textures.\n", 1);
	else
		file->texture_flag = 1;		
	if(extract_rgb(file))
		exit_error("Error Cannot load rgb values.\n", 1);
	else
		file->rgb_flag = 1;	
	if(file->texture_flag == 1 && file->rgb_flag == 1)
		file->all_params_flag = 1;
	return(file->all_params_flag);		
}

void	purge_lines(s_cube *file)
{
	int		i;
	int		line;
	char	*str;
	int		n;

	
	i = -1;
	line = -1;
	n = 0;
	file->dumpsize = dp_count(file->dumpcontent);
	while(file->dumpcontent[line])
	{
		str = ft_strdup(file->dumpcontent[line]);
		i = -1;
		while(str[i])
		{
			if(str[i] == '1' && str[i + 1] == '1' && file->all_params_flag == 0)
			{			
				file->map = (char **)malloc(dp_count(file->dumpcontent) - 7);
				while(n < file->dumpsize - 7)
				{
					file->map[n] = file->dumpcontent[line];
					n++;
					line++;					
				}	
			}
			else
				i++;
		}
		line++;
	}
	print_split2(file->map);
	file->map[n] = NULL;
}
