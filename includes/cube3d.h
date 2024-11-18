/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:45:09 by gacel             #+#    #+#             */
/*   Updated: 2024/11/18 22:23:38 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include "../Lib/libft.h"

typedef struct cube
{
	
    char        *fdcontent;
    char        **dumpcontent;
	char		**map;
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
	int			all_params_flag;
}   s_cube;

//Utilidades-------------------->utils.c
void    ft_checkfinal (s_cube *file);
char    *ft_checkfinal_str(char *str);
char	*ft_check_spaces(char *str);
int		ft_check_map(char *str);
int		ft_rgb_atoi(const char *str);
void	purge(s_cube *file);
void	init_textures_flag(s_cube *file);
int		check_param_dup(s_cube *file);
//int		dp_count(char **content);
//Pruebas----------------------->debug.c
void	print_infile(s_cube *file);
void	print_split(s_cube *file);
void	print_split2(char **str);
void 	print_textures_path(s_cube *file);
//Extract Texturs Path---------->extract_textures.c
int		extract_textures(s_cube *file);
int		no_texture_path(s_cube *file);
int		so_texture_path(s_cube *file);
int		we_texture_path(s_cube *file);
int		ea_texture_path(s_cube *file);
//Extract Colours				extract_colours.c
char	*iscleanrgbtxt(char *str);
int		extract_rgb(s_cube *file);
int		fextract_rgb(s_cube *file);
int		cextract_rgb(s_cube *file);
int		split_to_rgb(s_cube *file);
//Extract Map
int		all_params(s_cube *file);

//Frees-------------------------->frees.c
void	free_split(char **split);
void	free_path(s_cube *file);



#endif