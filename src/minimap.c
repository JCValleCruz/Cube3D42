/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:33:52 by jormoral          #+#    #+#             */
/*   Updated: 2024/12/13 13:10:27 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

/* int	get_rgba(int r, int g, int b, int a)
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
} */
mlx_texture_t	*load_wall_texture(void)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./resources/Wall0.png");
	return (texture);
}

/* void	paste_sticker(mlx_image_t *dst, mlx_image_t *src, int x, int y)
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
} */
mlx_texture_t	*load_ground(void)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./resources/background.png");
	return (texture);
}

mlx_texture_t	*load_player_texture(void)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./resources/player.png");
	return (texture);
}
mlx_texture_t	*load_clean(void)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./resources/trans.png");
	return (texture);
}

void	put_background(void *g, int x, int y)
{
	t_cube      *game; 

	game = (t_cube *)g;
	game->ground = mlx_texture_to_image(game->mlx, game->mmap_background);
	mlx_resize_image(game->ground, SCALE_M, SCALE_M);
	mlx_image_to_window(game->mlx, game->ground, x * SCALE_M, y * SCALE_M);
}
void	put_player(void *g, int x, int y)
{
	t_cube      *game; 

	game = (t_cube *)g;
	game->player = mlx_texture_to_image(game->mlx, game->mmap_player);
	mlx_resize_image(game->player, SCALE_M, SCALE_M);
	mlx_image_to_window(game->mlx, game->player, x * SCALE_M, y * SCALE_M);

}

void	put_wall(void *g, int x, int y)
{
	t_cube      *game; 

	game = (t_cube *)g;
	game->wall = mlx_texture_to_image(game->mlx, game->mmap_wall);
	mlx_resize_image(game->wall, SCALE_M, SCALE_M);
	mlx_image_to_window(game->mlx, game->wall, (x * SCALE_M), (y * SCALE_M));
}

void	put_cleaned(void *g, int x, int y)
{
	t_cube      *game; 

	game = (t_cube *)g;
	game->cleaned = mlx_texture_to_image(game->mlx, game->mmap_cleaned);
	mlx_resize_image(game->cleaned, SCALE_M, SCALE_M);
	mlx_image_to_window(game->mlx, game->cleaned, (x * SCALE_M), (y * SCALE_M));
}

void	ft_draw_minimap(void *g)
{
	t_cube	*file;
	int		x;
	int		y;
	
	file = (t_cube *)g;
	y = -1;
	if(file->minimap_visible == 1)
	{
		while (++y < 14) // 
		{
			x = -1;
			while ((size_t)++x < ft_strlen(file->map[y]))
			{
				if (file->map[y][x] == GROUND)
					put_background(file, x, y);
				else if (file->map[y][x] == WALL)
					put_wall(file, x, y);
				else if(file->map[y][x] == PLAYER)
					put_player(file, x, y);
			}
		}
	}
	else if(file->minimap_visible == 0)
		ft_clean_minimap(file);
}

void	ft_clean_minimap(void *g)
{
	t_cube	*file;
	int		x;
	int		y;
	file = (t_cube *)g;
	x = 0;
	y = 0;
	while (y < 14) // 
	{
		x = 0;
		while ((size_t)x < ft_strlen(file->map[y]))
		{
			if(file->map[y][x] == GROUND || file->map[y][x] == WALL || file->map[y][x] == PLAYER)
				put_cleaned(file, x, y);
			x++;
		}
		y++;
	}
	//file->player->enabled = false;
}

