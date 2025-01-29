/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 09:26:42 by jormoral          #+#    #+#             */
/*   Updated: 2025/01/29 14:42:15 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

uint32_t color_switch(uint32_t color)
{
	return ((color & 0x000000ff) << 24 | (color & 0x0000ff00) << 8 
	| (color & 0x00ff0000) >> 8 | (color & 0xff000000) >> 24);
}
uint32_t rgb_to_rgba(int *rgb)
{
    return ((uint32_t)rgb[0] << 24) | ((uint32_t)rgb[1] << 16) | ((uint32_t)rgb[2] << 8) | 0xFF;
}

void draw_texture(t_cube *file, int i)
{
	int			c;
	int			start;
	uint32_t    color;
	int			end;
	int			pixel;
    uint32_t ceiling_color = rgb_to_rgba(file->rgbceilingcolour);
    uint32_t floor_color = rgb_to_rgba(file->rgbfloorcolour);

	(void)color;
	c = 0;
	start = (HEIGHT - file->scale * 2 * 212) / 2;
	end = (HEIGHT + file->scale * 2 * 212) / 2;
	while (c < start)
		mlx_put_pixel(file->img, i, c++, ceiling_color);
	while (c < end && c < HEIGHT)
	{
		pixel = 4 * ((int)(212.0 * file->x_img)
				+ (212 * (int)((c - start) / (2 * file->scale))));
		ft_memcpy(&color, &file->actual_t->pixels[pixel], 4);
		mlx_put_pixel(file->img, i, c, color_switch(color));
		c++;
	}
	while (c < HEIGHT)
		mlx_put_pixel(file->img, i, c++, floor_color);
}
