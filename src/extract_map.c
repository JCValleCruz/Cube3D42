/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:18:57 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/11/18 20:11:24 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cube3d.h"

int		all_params(s_cube *file)
{
	purge(file);
	//init_textures_flag(file);
	if(extract_textures(file))
		printf("Error: Cannot load path textures.\n");
	else
		file->texture_flag = 1;		
	if(extract_rgb(file))
		printf("Error Cannot load rgb values.\n");
	else
		file->rgb_flag = 1;	
	//print_textures_path(&file);    //debug
	if(file->texture_flag == 1 && file->rgb_flag == 1)
		file->all_params_flag = 1;
	return(file->all_params_flag);		
}
