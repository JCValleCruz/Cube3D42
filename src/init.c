/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:32:03 by jvalle-d          #+#    #+#             */
/*   Updated: 2025/01/29 16:44:28 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	init_params(t_cube *file)
{
	file->pathtexturenorth = NULL;
	file->pathtexturesouth = NULL;
	file->pathtexturewest = NULL;
	file->pathtextureeast = NULL;
	file->dc = ft_split(file->fdcontent, '\n');
	file->textfloorcolour = NULL;
	file->textceilingcolour = NULL;
	file->rgbceilingcolour = (int *)malloc(sizeof(int) * 3);
	if (!file->rgbceilingcolour)
		exit_error_game("Error: Failed Ceiling Color.", 1, file);
	file->rgbfloorcolour = (int *)malloc(sizeof(int) * 3);
	if (!file->rgbfloorcolour)
		exit_error_game("Error: Failed Floor Color.", 1, file);
	file->map = NULL;
	file->dumpsize = dp_count(file->dc);
	file->rgb_flag = 0;
	file->texture_flag = 0;
	file->apflag = 0;
	file->textfloorcolour = NULL;
	file->textceilingcolour = NULL;
	file->colourceilingsplit = NULL;
	file->colourfloorsplit = NULL;
}

void	init_raycasting(t_cube *file)
{
	player_position(file);
	initial_orientation(file);
	file->v_dir.x = cos(file->alpha);
	file->v_dir.y = sin(file->alpha);
	if (file->v_dir.x < 0.0 && file->orientation != 'W')
		file->v_dir.x = -file->v_dir.x;
}

void	init_texture(t_cube	*file)
{
	(void)file;
	file->north = mlx_load_png(file->pathtexturenorth);
	file->east = mlx_load_png(file->pathtextureeast);
	file->south = mlx_load_png(file->pathtexturesouth);
	file->west = mlx_load_png(file->pathtexturewest);
}
