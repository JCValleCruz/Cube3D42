/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:20:05 by jormoral          #+#    #+#             */
/*   Updated: 2025/01/28 14:05:51 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void rotate_move(t_cube *file, double newmove)
{
	file->alpha += newmove;
	if (file->alpha < 0.0)
		file->alpha += 2 * PI;
	if (file->alpha > 2 * PI)
		file->alpha -= 2 * PI;
	file->v_dir.x = cos(file->alpha);
	file->v_dir.y = sin(file->alpha);
	/* sumamos el nuevo movimiento a nuestro alpha
	nunca puede estar alpha fuera de el rango de 360\
	y actualizamos el vector de direcion nuevo;*/
}

void	frontal_move(t_cube *file, double n)
{
	double	new_pos_x;
	double	new_pos_y;
	//printf("Pos player x: [%f] y: [%f] Pos in map: [%c] \n", file->position_player.x, file->position_player.y, file->map[(int)file->position_player.y][(int)file->position_player.x]);
	new_pos_x = file->position_player.x + n * file->v_dir.x;
	new_pos_y = file->position_player.y + n * file->v_dir.y;
	if(new_pos_x > 0.0 && new_pos_y > 0.0 && file->map[(int)new_pos_y][(int)new_pos_x] != '1')
	{
		file->position_player.x = new_pos_x;
		file->position_player.y = new_pos_y;
	} 
	return ; 
}


void handle_move(void *param)
{
	t_cube *file;
	
	file = (t_cube *)param;
	if (mlx_is_key_down(file->mlx, MLX_KEY_ESCAPE))
	{
		free_game(file);
		mlx_close_window(file->mlx);
		mlx_terminate(file->mlx);
		file = NULL;
		exit(1);
	}
	else if (mlx_is_key_down(file->mlx, MLX_KEY_A))
		rotate_move(file, 0.1745);
	else if (mlx_is_key_down(file->mlx, MLX_KEY_D))
		rotate_move(file, -1 * 0.1745);
	else if (mlx_is_key_down(file->mlx, MLX_KEY_W))
		frontal_move(file, 0.1);
	else if (mlx_is_key_down(file->mlx, MLX_KEY_S))
		frontal_move(file, -0.1);
	raycasting(file);
}