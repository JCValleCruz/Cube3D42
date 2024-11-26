/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 02:09:50 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/11/26 12:00:44 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cube3d.h"

int	check_param_dup(s_cube *file)
{
	char	*str;
	int		line;
	int		count;
	
	line = -1;
	count = 0;
	while(file->dumpcontent[++line])
	{
		str = file->dumpcontent[line];
		if(!ft_strncmp(str, "NO", 2) || !ft_strncmp(str, "SO", 2) 
			|| !ft_strncmp(str, "WE", 2) || !ft_strncmp(str, "EA", 2) 
				|| !ft_strncmp(str, "F ", 2) || !ft_strncmp(str, "C ", 2))
			count++;			
	}
	if (count != 6)
		return 1;
	return 0;
}

int		all_params(s_cube *file)
{
	init_params(file);
	purge(file);
	if(check_param_dup(file))
		exit_error("Error: CUB file does not have the correct parameters.\n", 1);
	if(extract_textures(file))
		exit_error("Error: Cannot load path textures.\n", 1);
	else
		file->texture_flag = 1;		
	if(extract_rgb(file))
		exit_error("Error: Cannot load rgb values.\n", 1);
	else
		file->rgb_flag = 1;	
	if(file->texture_flag == 1 && file->rgb_flag == 1)
		file->all_params_flag = 1;
	extract_map(file);
	clone_map(file->map);
	return(file->all_params_flag);		
}

int	ft_rgb_atoi(const char *str)
{
	int	result;
	int	c;
	
	result = 0;
	c = 0;
 	if(!str)
		exit_error("Error: Cannot load rgb values.\n", 1);
	while(str[c])
	{
	 	if(str[c] < '0' || str[c] > '9')
			return 256;
		c++;	
	}
	c = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result);
}
