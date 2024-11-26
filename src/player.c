/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:48:16 by jormoral          #+#    #+#             */
/*   Updated: 2024/11/26 13:36:05 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	check_player(s_cube *file)
{
	double	x;
	double	y;
	int		count;

	x = -1;
	count = 0;
	while(file->map[(int)++x])
	{
		y = -1;
		while (file->map[(int)x][(int)++y])
		{
			if (ft_strchrplayer("NSWE", file->map[(int)x][(int)y], file))
				count++;
		}
	}
	if (count != 1)
		exit_error("Error: nº of players was incorrect", 1);
	return (0);
}

int	player_position(s_cube *file)
{
	double	x;
	double	y;

	x = -1;
	while(file->map[(int)++x])
	{
		y = -1;
		while (file->map[(int)x][(int)++y])
		{
			if (ft_strchrplayer("NSWE", file->map[(int)x][(int)y], file))
			{	
				file->position_player.x = x;
				file->position_player.y = y;
				return (0);
			}
		}
	
	}
	return(printf("Error: Player not found."), 1);
}

double	initial_orientation(s_cube *file)
{
	
	if (file->orientation == 'N')
		return (file->alpha = PI / 2);
	if (file->orientation == 'S')
		return (file->alpha = PI * 1.5);
	if (file->orientation == 'W')
		return (file->alpha = PI);
	if (file->orientation == 'E')
		return (file->alpha = PI * 2);
	return (0);
}

int	check_clonemap(s_cube *file)
{
	while()
}
