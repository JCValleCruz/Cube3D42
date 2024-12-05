/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:32:03 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/12/05 13:31:42 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	init_params(s_cube *file)
{
	file->pathtexturenorth = NULL;
	file->pathtexturesouth = NULL;
	file->pathtexturewest = NULL;
	file->pathtextureeast = NULL;
	file->dumpcontent = ft_split(file->fdcontent, '\n');
	file->textfloorcolour = NULL;
	file->textceilingcolour = NULL;
	file->rgbceilingcolour = (int *)malloc(sizeof(int) * 3);
	file->rgbfloorcolour = (int *)malloc(sizeof(int) * 3);
	file->map = NULL; //Mandar a init
	file->dumpsize = dp_count(file->dumpcontent);
	file->rgb_flag = 0;
	file->texture_flag = 0;
	file->all_params_flag = 0;
}

void	init_raycasting(s_cube *file)
{
	player_position(file);
	initial_orientation(file);
	file->alpha = initial_orientation(file); // initial_orientation checkear funcion
	file->v_dir.x = cos(file->alpha);
	file->v_dir.y = sin(file->alpha);
	if (file->v_dir.x < 0.0 && file->orientation != 'W')
    	file->v_dir.x = -file->v_dir.x;	 
	if (file->v_dir.y < 0.0 && file->orientation != 'S')
		file->v_dir.y = -file->v_dir.y; 

}
void	init_texture(s_cube	*file)
{
	file->north = mlx_load_png(file->pathtexturenorth);
	file->south = mlx_load_png(file->pathtexturesouth);
	file->east = mlx_load_png(file->pathtextureeast);
	file->west = mlx_load_png(file->pathtexturewest);
}