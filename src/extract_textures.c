/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:35:20 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/11/18 22:17:31 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int		extract_textures(s_cube *file)
{
	int flag;
	
	flag = 0;
	file->pathtexturenorth = NULL;
	file->pathtexturesouth = NULL;
	file->pathtexturewest = NULL;
	file->pathtextureeast = NULL;
	
	if(!no_texture_path(file))
		flag = 1;
	if(!so_texture_path(file))
		flag = 1;
	if(!we_texture_path(file))
		flag = 1;
	if(!ea_texture_path(file))
		flag = 1;
	return flag;	
}
int no_texture_path(s_cube *file)
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
                while (str[i] && (str[i] == ' ' || str[i] == '\t'))
                    i++;
            	return file->pathtexturenorth = ft_substr(str, i, ft_strlen(str) - i), 1;		
            }
        }
    }
    return 0; 
}
int so_texture_path(s_cube *file)
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
                while (str[i] && (str[i] == ' ' || str[i] == '\t'))
                    i++;
            	return file->pathtexturesouth = ft_substr(str, i, ft_strlen(str) - i), 1;		
            }
        }
    }
    return 0; 
}
int we_texture_path(s_cube *file)
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
                while (str[i] && (str[i] == ' ' || str[i] == '\t'))
                    i++;
            	return file->pathtexturewest = ft_substr(str, i, ft_strlen(str) - i), 1;		
            }
        }
    }
    return 0; 
}
int ea_texture_path(s_cube *file)
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
                while (str[i] && (str[i] == ' ' || str[i] == '\t'))
                    i++;
            	return file->pathtextureeast = ft_substr(str, i, ft_strlen(str) - i), 1;		
            }
        }
    }
    return 0; 
}

