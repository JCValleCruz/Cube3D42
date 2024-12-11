/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temporal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:33:52 by jormoral          #+#    #+#             */
/*   Updated: 2024/12/11 13:02:03 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

int32_t	mlx_get_pixel(mlx_image_t *image, uint32_t x, uint32_t y)
{
	uint8_t	*ps;

	if (x > image->width || y > image->height)
		return (0xFF000000);
	ps = image->pixels + (y * image->width + x) * sizeof(int32_t);
	return (get_rgba(*(ps), *(ps + 1), *(ps + 2), *(ps + 3)));
}

int	put_pixel_valid(mlx_image_t *img, uint32_t x, uint32_t y)
{
	return (x < img->width && y < img->height && mlx_get_pixel(img, x, y) != 0);
}
mlx_texture_t	*load_wall_texture(void)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./resources/Wall0.png");
	return (texture);
}

void	paste_sticker(mlx_image_t *dst, mlx_image_t *src, int x, int y)
{
	uint32_t	i;
	uint32_t	j;

	i = 0;
	while (i < src->width)
	{
		j = 0;
		while (j < src->height)
		{
			if (put_pixel_valid(src, i, j))
				mlx_put_pixel(dst, x + i, y + j, mlx_get_pixel(src, i, j));
			j++;
		}
		i++;
	}
}
mlx_texture_t	*load_ground(void)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./resources/background.png");
	return (texture);
}

mlx_texture_t	*load_player_texture(void)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./textures/player.png");
	return (texture);
}

void	put_background(void *g, int x, int y)
{
	mlx_image_t	*sticker;
	t_cube      *game; 

	game = (t_cube *)g;
	sticker = mlx_texture_to_image(game->mlx, game->mmap_background);
	//if (!sticker)
		//error(game);
	paste_sticker(game->img, sticker, x * 160, y * 160);
	mlx_delete_image(game->mlx, sticker);
}
void	put_wall(void *g, int x, int y)
{
	mlx_image_t	*sticker;
	t_cube      *game; 

	game = (t_cube *)g;
	sticker = mlx_texture_to_image(game->mlx, game->mmap_wall);
/* 	if (!sticker)
		error(game); */
	paste_sticker(game->img, sticker, x * 160, y * 160);
	mlx_delete_image(game->mlx, sticker);
}

void	ft_draw_minimap(void *g)
{
	t_cube	*gm;
	int		x;
	int		y;

	gm = (t_cube *)g;
	x = 0;
	y = 0;
	while ((size_t)y < ft_strlen(gm->map[y]))
	{
		x = 0;
		while (x < gm->map[y][x])
		{
			if (gm->map[y][x] == GROUND)
				put_background(gm, x, y);
			else if (gm->map[y][x] == WALL)
				put_wall(gm, x, y);
			x++;
		}
		y++;
	}
}
