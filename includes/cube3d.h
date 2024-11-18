/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:45:09 by gacel             #+#    #+#             */
/*   Updated: 2024/11/18 02:13:28 by jvalle-d         ###   ########.fr       */
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
}   s_cube;

//Utilidades--------------->utils.c
void    *ft_checkfinal (s_cube *file);
char    *ft_checkfinal_str(char *str);
char	*ft_check_spaces(char *str);
int		ft_check_map(char *str);
int		dp_count(char **content);

	

//Pruebas------------------>debug.c
void	print_infile(s_cube *file);
void	print_split(s_cube *file);

int		extract_textures(s_cube *file);
int		no_texture_path(s_cube *file);
int		so_texture_path(s_cube *file);
int		we_texture_path(s_cube *file);
int		ea_texture_path(s_cube *file);





#endif