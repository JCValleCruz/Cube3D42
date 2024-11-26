/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:32:03 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/11/26 11:53:36 by jormoral         ###   ########.fr       */
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
	file->position_player.x = 0;
	file->position_player.y = 0;
	file->orientation = '\0';
	file->alpha = initial_orientation(file); // initial_orientation checkear funcion
	file->v_dir.x = cos(file->alpha);	// coseno alpha
	file->v_dir.y = sin(file->alpha);
	//printf("%f\n", file->v_dir.x);

	
}