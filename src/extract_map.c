/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:18:57 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/11/18 22:43:25 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cube3d.h"

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
