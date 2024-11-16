/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:45:09 by gacel             #+#    #+#             */
/*   Updated: 2024/11/16 22:25:17 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "../Lib/libft.h"

typedef struct cube
{
    char        *fdcontent;
    char        **dumpcontent;
}   s_cube;

//Utilidades--------------->utils.c
void    *ft_checkfinal (s_cube *file);

	

//Pruebas------------------>debug.c
void	print_infile(s_cube *file);
void	print_split(s_cube *file);




#endif