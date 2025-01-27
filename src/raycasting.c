/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:24:34 by jormoral          #+#    #+#             */
/*   Updated: 2025/01/23 18:30:34 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int min_width(t_cube *file)
{
	int min = 0;
	int x = 0;
	int y = 0;
	while (file->clone_map[0][min])
		min++;
	while(y < file->map_height)
	{
		x = 0;
		while(file->clone_map[y][x])
			x++;
		if (min > x)
			min = x;
		y++;
	}
	return min;
}


int check_collision(t_cube *file)
{
	if(file->ph.x < 1.0 || file->ph.x > min_width(file) - 1
		|| file->ph.y < 1.0 || file->ph.y >  file->map_height - 1) // PH.X/Y no puede superar el tamaño del map
		return(1);
	if (file->ph.x == ceil(file->ph.x))
		return (file->map[(int)file->ph.y][(int)file->ph.x - (file->ray.x < 0)] == '1');
	else
		return (file->map[(int)file->ph.y - (file->ray.y < 0)][(int)file->ph.x] == '1');
}

int hacendado_point(t_cube *file)
{
	double	option_x[2];
	double	option_y[2];

	option_x[0] = floor(file->ph.x) + (file->ray.x > 0) - 
		(file->ray.x < 0 && ceil(file->ph.x) == file->ph.x);
	option_x[1] = file->ph.y + file->m.x * (option_x[0] - file->ph.x);
	option_y[1] = floor(file->ph.y) + (file->ray.y > 0) - 
		(file->ray.y < 0 && ceil(file->ph.y) == file->ph.y);
	option_y[0] =  file->ph.x + file->m.y * (option_y[1] - file->ph.y);
	if (fabs((option_x[0] - file->ph.x)) < (fabs(option_y[0] - file->ph.x)))
	{
		file->ph.x = option_x[0];
		file->ph.y = option_x[1];	
	}
	else
	{
		file->ph.x = option_y[0];
		file->ph.y = option_y[1];
	}
	return(check_collision(file));
}

double calculate_distance(t_cube *file)
{
	double distancex = file->ph.x - file->position_player.x; 
	double distancey = file->ph.y - file->position_player.y;
	//printf("sqrt %f\n", sqrt(distancex * distancex + distancey * distancey));
	return(sqrt(distancex * distancex + distancey * distancey));
	/*Hay que comprobar que este funcionando correctamente*/
}

void get_collision_orientation(t_cube *file)
{
    if (file->ray.x > 0.0 && file->ph.x == ceil(file->ph.x))
	{
		file->actual_t = file->west;
		file->x_img = file->ph.y - floor(file->ph.y); //WEST
	}
    else if (file->ray.x < 0.0 && file->ph.x == floor(file->ph.x))
	{
		file->actual_t = file->east;
		file->x_img = ceil(file->ph.y) - file->ph.y; //EAST
	}
    else if (file->ray.y > 0.0)
	{
		file->actual_t = file->south;
		file->x_img = ceil(file->ph.x) - file->ph.x; //SOUTH
	}   
    else if (file->ray.y < 0.0)
    {
		file->actual_t = file->north;
		file->x_img = file->ph.x - floor(file->ph.x); //NORTH
	}
	/*Hay que comprobar que este funcionando correctamente, y quiero
	cambiar la manera de identificar la textura que corresponde*/
}

void raycasting(t_cube *file)
{
	int i;
	
	i = 0;
	while(i < WIDTH)
	{
		file->ray.x = file->v_dir.x - file->v_dir.y * ((WIDTH / 2) - i) * FOV;
		file->ray.y = file->v_dir.y + file->v_dir.x * ((WIDTH / 2) - i) * FOV;
		file->ph.x = file->position_player.x;
		file->ph.y = file->position_player.y;
		file->m.x = file->ray.y / file->ray.x;
		file->m.y = file->ray.x / file->ray.y;
		while(!hacendado_point(file))
			continue ;
		file->scale =  1  / calculate_distance(file);
		get_collision_orientation(file);
		draw_texture(file, i);
		i++;
	}
}
