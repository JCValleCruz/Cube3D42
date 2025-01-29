/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:45:09 by gacel             #+#    #+#             */
/*   Updated: 2025/01/29 18:46:02 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H


# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "../Lib/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

/* # ifndef MALLOC_TEST
# define malloc(size) 0
# endif */

# define PI 3.14159265
# define WIDTH 1024
# define HEIGHT 768
# define FOV 0.000976562 
# define WHITE 0x66ffffff

# define WALL '1'
# define PLAYER 'S'
# define GROUND '0'
# define SCALE_M 32


typedef struct	s_point
{
	double	x;
	double	y;
}	t_point;


typedef struct s_cube
{
    char        *fdcontent;
    char        **dc;
	int			dumpsize;
	int			mapsize;
	char		**map;
	char		**clone_map;
	int			map_height;
	char		*pathtexturenorth;
	char		*pathtexturesouth;
	char		*pathtexturewest;
	char		*pathtextureeast;
	int			texture_flag;
	char		*textfloorcolour;
	char		**colourfloorsplit;
	char		*textceilingcolour;
	char		**colourceilingsplit;
	int			*rgbfloorcolour;
	int			*rgbceilingcolour;
	int			rgb_flag;
	int			apflag;
	char		orientation;
	t_point 	position_player;
	double		alpha;
	t_point		ray;		
	t_point		v_dir;
	t_point		ph;
	t_point 	m;
	double		difx;
	double		dify;
	double		scale;
	double 		x_img;
	uint32_t	ceiling_color;
	uint32_t	floor_color;
	mlx_t			*mlx;
	mlx_texture_t	*actual_t;
	mlx_image_t		*img;
	mlx_texture_t	*east;
	mlx_texture_t 	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_image_t     *player;
	mlx_image_t		*wall;
	mlx_image_t		*ground;
	mlx_image_t		*cleaned;
	int				i;
	int				j;
	int				n;
}   t_cube;

void    ft_checkfinal (t_cube *file);
int		check_extension(char *str);
char    *ft_cf_str(char *str);
char	*ft_check_spaces(char *str);
int		ft_check_map(char *str);
int		ft_rgb_atoi(const char *str);
void	purge(t_cube *file);
int		check_param_dup(t_cube *file);
int		dp_count(char **content);
void	clone_map(t_cube *file);
int		check_player(t_cube *file);
int		extract_textures(t_cube *file);
int		no_texture_path(t_cube *file);
int		so_texture_path(t_cube *file);
int		we_texture_path(t_cube *file);
int		ea_texture_path(t_cube *file);
char	*iscleanrgbtxt(char *str);
int		extract_rgb(t_cube *file);
int		fextract_rgb(t_cube *file);
int		cextract_rgb(t_cube *file);
int		split_to_rgb(t_cube *file);
int		check_extension_png(char *str);	
int		check_x(t_cube *file);
int		check_y(t_cube *file);
int		check_map(t_cube *file);
int		check_zero(t_cube *file);
int		check_nullzero(t_cube *file);
int		all_params(t_cube *file);
void	extract_map(t_cube	*file);
int     exit_error(char *str, int i);
void	free_split(char **split);
void	free_game(t_cube *file);
void	free_game_nt(t_cube *file);
void	init_params(t_cube *file);
void	raycasting(t_cube *file);
int		player_position(t_cube *file);
double	initial_orientation(t_cube *file);
void	init_raycasting(t_cube *file);
int		ft_strchrplayer(const char *s, int c, t_cube *file);
void	init_mlx(char *str1, t_cube *file);
void	init_texture(t_cube	*file);
void	draw_texture(t_cube *file, int i);
void	handle_move(void *param);
int		check_invalid_line(t_cube *file);
int		broken_map(t_cube *file);
void	exit_error_game(char *str, int i, t_cube *file);
void	exit_game(t_cube *file);
int		check_order(t_cube *file);
int		check_permission(t_cube *file);
int		search_header(char *temp);
#endif