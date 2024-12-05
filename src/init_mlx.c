/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:53:56 by jormoral          #+#    #+#             */
/*   Updated: 2024/12/05 12:19:36 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void init_mlx(char *str1, s_cube *file)
{
	(void)str1;
	// tengo que hacerle malloc a file??
	// preguntar a JC en el de meckjose esta hecho asi
	file->mlx = mlx_init(WIDTH, HEIGHT, "Studio", 0);
	if (!file->mlx)
		return ;
	file->img = mlx_new_image(file->mlx, WIDTH, HEIGHT);
	init_texture(file);
}