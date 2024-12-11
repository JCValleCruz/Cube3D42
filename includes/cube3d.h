/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:45:09 by gacel             #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/12/10 18:58:06 by jvalle-d         ###   ########.fr       */
=======
/*   Updated: 2024/12/11 13:10:49 by jormoral         ###   ########.fr       */
>>>>>>> main
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

# define PI 3.14159265
# define WIDTH 1024
# define HEIGHT 768
# define WHITE 0x66ffffff

# define WALL '1'
# define PLAYER 'P'
# define GROUND '0'


typedef struct	s_point
{
	double	x;
	double	y;
}	t_point;


typedef struct s_cube
{
    char        *fdcontent;
    char        **dumpcontent;
	int			dumpsize;
	char		**map;
	char		**clone_map;
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
	//int			fclean_flag;
	int			*rgbceilingcolour;
	int			rgb_flag;
	int			all_params_flag;
	int			map_flag;
	/// añadido para Ray casting
	char		orientation;
	t_point 	position_player;
	double		alpha;		
	t_point		v_dir; // inizializar , hablas con jc si es mejor hacer un array
	mlx_t			*mlx;
	mlx_image_t		*img;
	mlx_texture_t	*east;
	mlx_texture_t 	*north;
	mlx_texture_t	*south;
	mlx_texture_t	*west;
	mlx_texture_t	*mmap_player;
	mlx_texture_t	*mmap_wall;
	mlx_texture_t 	*mmap_background;
}   t_cube;

//Utilidades-------------------->utils.c
void    ft_checkfinal (t_cube *file);
int		check_extension(char *str);
char    *ft_checkfinal_str(char *str);
char	*ft_check_spaces(char *str);
int		ft_check_map(char *str);
int		ft_rgb_atoi(const char *str);
void	purge(t_cube *file);
int		check_param_dup(t_cube *file);
int		dp_count(char **content);
void	clone_map(t_cube *file);
int		check_player(t_cube *file);
//Pruebas----------------------->debug.c
void	print_infile(t_cube *file);
void	print_split(t_cube *file);
void	print_split2(char **str);
void 	print_textures_path(t_cube *file);
//Extract Texturs Path---------->extract_textures.c
int		extract_textures(t_cube *file);
int		no_texture_path(t_cube *file);
int		so_texture_path(t_cube *file);
int		we_texture_path(t_cube *file);
int		ea_texture_path(t_cube *file);
//Extract Colours				extract_colours.c
char	*iscleanrgbtxt(char *str);
int		extract_rgb(t_cube *file);
int		fextract_rgb(t_cube *file);
int		cextract_rgb(t_cube *file);
int		split_to_rgb(t_cube *file);
//Check_map

<<<<<<< HEAD
void	no_tabs(s_cube *file);
int		check_x(s_cube *file);
int		check_y(s_cube *file);
int		check_map(s_cube *file);
int		check_zero(s_cube *file);
//Extract Map
int		all_params(s_cube *file);
void	extract_map(s_cube	*file);
int		jclean(char *str, s_cube *file);
=======
int		check_x(t_cube *file);
int		check_y(t_cube *file);
int		check_map(t_cube *file);
int		check_zero(t_cube *file);
//Extract Map
int		all_params(t_cube *file);
void	extract_map(t_cube	*file);
>>>>>>> main
//Errors
int     exit_error(char *str, int i);

//Frees-------------------------->frees.c
void	free_split(char **split);
void	free_path(t_cube *file);


void	init_params(t_cube *file);
// Ray Casting
<<<<<<< HEAD
int		player_position(s_cube *file);
double	initial_orientation(s_cube *file);
void	init_raycasting(s_cube *file);
int		ft_strchrplayer(const char *s, int c, s_cube *file);
void	init_mlx(char *str1, s_cube *file);
void	init_texture(s_cube	*file);



char	**ft_split_2(const char *s, char c);
=======
int		player_position(t_cube *file);
double	initial_orientation(t_cube *file);
void	init_raycasting(t_cube *file);
int		ft_strchrplayer(const char *s, int c, t_cube *file);
void	init_mlx(char *str1, t_cube *file);
void	init_texture(t_cube	*file);


//Experimento Minimapa
void	ft_draw_minimap(void *g);
mlx_texture_t	*load_ground(void);
mlx_texture_t	*load_wall_texture(void);


>>>>>>> main
#endif