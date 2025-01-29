/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:20:05 by jormoral          #+#    #+#             */
/*   Updated: 2025/01/29 17:53:58 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	rotate_move(t_cube *file, double newmove)
{
	file->alpha += newmove;
	if (file->alpha < 0.0)
		file->alpha += 2 * PI;
	if (file->alpha > 2 * PI)
		file->alpha -= 2 * PI;
	file->v_dir.x = cos(file->alpha);
	file->v_dir.y = sin(file->alpha);
}

void	frontal_move(t_cube *file, double n)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = file->position_player.x + n * file->v_dir.x;
	new_pos_y = file->position_player.y + n * file->v_dir.y;
	if (new_pos_x > 0.0 && new_pos_y > 0.0
		&& (file->map[(int)new_pos_y][(int)new_pos_x] == '0'
		|| file->map[(int)new_pos_y][(int)new_pos_x] == file->orientation))
	{
		file->position_player.x = new_pos_x;
		file->position_player.y = new_pos_y;
	}
	return ;
}

void	lateral_move(t_cube *file, double n)
{
	double	new_pos_x;
	double	new_pos_y;
	double	lateral_dir_x;
	double	lateral_dir_y;

	lateral_dir_x = file->v_dir.y;
	lateral_dir_y = -file->v_dir.x;
	new_pos_x = file->position_player.x + n * lateral_dir_x;
	new_pos_y = file->position_player.y + n * lateral_dir_y;
	if (new_pos_x > 0.0 && new_pos_y > 0.0
		&& file->map[(int)new_pos_y][(int)new_pos_x] != '1')
	{
		file->position_player.x = new_pos_x;
		file->position_player.y = new_pos_y;
	}
	return ;
}

void	handle_move(void *param)
{
	t_cube	*file;

	file = (t_cube *)param;
	if (mlx_is_key_down(file->mlx, MLX_KEY_ESCAPE))
		exit_game(file);
	else if (mlx_is_key_down(file->mlx, MLX_KEY_LEFT))
		rotate_move(file, -1 * 0.10);
	else if (mlx_is_key_down(file->mlx, MLX_KEY_RIGHT))
		rotate_move(file, 0.10);
	else if (mlx_is_key_down(file->mlx, MLX_KEY_A))
		lateral_move(file, 0.08);
	else if (mlx_is_key_down(file->mlx, MLX_KEY_D))
		lateral_move(file, -0.08);
	else if (mlx_is_key_down(file->mlx, MLX_KEY_W))
		frontal_move(file, 0.08);
	else if (mlx_is_key_down(file->mlx, MLX_KEY_S))
		frontal_move(file, -0.08);
	raycasting(file);
}
