/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 02:09:50 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/11/18 23:29:38 by jvalle-d         ###   ########.fr       */
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
	{
		printf("Error: CUB file does not have the correct parameters.\n");
		exit(1);
	}
	if(extract_textures(file))
		printf("Error: Cannot load path textures.\n");
	else
		file->texture_flag = 1;		
	if(extract_rgb(file))
		printf("Error Cannot load rgb values.\n");
	else
		file->rgb_flag = 1;	
	if(file->texture_flag == 1 && file->rgb_flag == 1)
		file->all_params_flag = 1;
	return(file->all_params_flag);		
}