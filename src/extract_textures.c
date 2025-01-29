/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:35:20 by jvalle-d          #+#    #+#             */
/*   Updated: 2025/01/29 13:39:40 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		extract_textures(t_cube *file)
{
	int flag;
	
	flag = 0;
	if(!no_texture_path(file))
		flag = 1;
	if(!so_texture_path(file))
		flag = 1;
	if(!we_texture_path(file))
		flag = 1;
	if(!ea_texture_path(file))
		flag = 1;
	if  (!check_extension_png(file->pathtexturenorth) || !check_extension_png(file->pathtexturesouth) || !check_extension_png(file->pathtexturewest) || !check_extension_png(file->pathtextureeast))
		exit_error_game("Error: Invalid texture extension.", 1, file);
	if (access(file->pathtexturesouth, F_OK) == -1 || access(file->pathtexturenorth, F_OK) == -1 || access(file->pathtexturewest, F_OK) == -1 || access(file->pathtextureeast, F_OK) == -1)
		exit_error_game("Error: Invalid texture permission.", 1, file);
	return flag;	
}
int no_texture_path(t_cube *file)
{
    char    *str;
    int     line;

    line = -1;
    while (file->dumpcontent[++line])
    {
        str = file->dumpcontent[line];
        int i = -1;
        while (str[++i])
        {
            if (str[0] == 'N' && str[1] == 'O')
            {
                i += 2;
                while (str[i] && (str[i] == ' '))
				{
                    i++;
					if(str[i] == '\0')
						return 0;
				}
            	return file->pathtexturenorth = ft_checkfinal_str
					(ft_substr(str, i, ft_strlen(str) - i)), 1;	
            }
        }
	}
    return 0; 
}
int so_texture_path(t_cube *file)
{
    char    *str;
    int     line;

    line = -1;
    while (file->dumpcontent[++line])
    {
        str = file->dumpcontent[line];
        int i = -1;
        while (str[++i])
        {
            if (str[0] == 'S' && str[1] == 'O')
            {
                i += 2;
                while (str[i] && (str[i] == ' '))
				{
                    i++;
					if(str[i] == '\0')
						return 0;
				}
            	return file->pathtexturesouth = ft_checkfinal_str(ft_substr(str, i, ft_strlen(str) - i)), 1;
            }
        }
    }
    return 0; 
}
int we_texture_path(t_cube *file)
{
    char    *str;
    int     line;

    line = -1;
    while (file->dumpcontent[++line])
    {
        str = file->dumpcontent[line];
        int i = -1;
        while (str[++i])
        {
            if (str[0] == 'W' && str[1] == 'E')
            {
                i += 2;
                while (str[i] && (str[i] == ' '))
				{
                    i++;
					if(str[i] == '\0')
						return 0;
				}
            	return file->pathtexturewest = ft_checkfinal_str(ft_substr(str, i, ft_strlen(str) - i)), 1;		
            }
        }
    }
    return 0; 
}
int ea_texture_path(t_cube *file)
{
    char    *str;
    int     line;

    line = -1;
    while (file->dumpcontent[++line])
    {
        str = file->dumpcontent[line];
        int i = -1;
        while (str[++i])
        {
            if (str[0] == 'E' && str[1] == 'A')
            {
                i += 2;
                while (str[i] && (str[i] == ' '))
				{
                    i++;
					if(str[i] == '\0')
						return 0;
				}
            	return file->pathtextureeast = ft_checkfinal_str(ft_substr(str, i, ft_strlen(str) - i)), 1;		
            }
        }
    }
    return 0; 
}

