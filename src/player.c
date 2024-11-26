/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:48:16 by jormoral          #+#    #+#             */
/*   Updated: 2024/11/26 11:58:47 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	player_position(s_cube *file)
{
	double	x;
	double	y;

	x = 0;
	while (file->map[(int)x])
	{
		y = 0;
		while (file->map[(int)x][(int)y])
		{
			if (ft_strchrplayer("NSWE", file->map[(int)x][(int)y], file))
			{
				printf("%c\n", file->orientation);
				file->position_player.x = x;
				file->position_player.y = y;
				printf("%f\n", file->position_player.x);
				printf("%f\n", file->position_player.y);
				return (0);
			}
			y++;
		}
		x++;
	}
	return(printf("Not found player\n"),1);
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
