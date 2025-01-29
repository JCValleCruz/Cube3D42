/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:53:56 by jormoral          #+#    #+#             */
/*   Updated: 2025/01/29 13:06:41 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	init_mlx(char *str1, t_cube *file)
{
	(void) str1;
	file->mlx = mlx_init(WIDTH, HEIGHT, "Studio", 1);
	if (!file->mlx)
		return ;
	file->img = mlx_new_image(file->mlx, WIDTH, HEIGHT);
	init_texture(file);
}
