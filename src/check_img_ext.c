/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_img_ext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:50:21 by jormoral          #+#    #+#             */
/*   Updated: 2025/01/29 13:44:28 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	check_permission(t_cube *file)
{
	if (access(file->pathtexturesouth, R_OK) == -1
		|| access(file->pathtexturenorth, R_OK) == -1
		|| access(file->pathtexturewest, R_OK) == -1
		|| access(file->pathtextureeast, R_OK) == -1)
		exit_error_game("Error: Invalid texture permission.", 1, file);
	return (0);
}

int	check_order(t_cube *file)
{
	char	**data;
	char	*str;
	int		line;
	int		i;

	line = 0;
	i = 6;
	data = file->dumpcontent;
	while (data[line] && i--)
	{
		str = ft_check_spaces(data[line]);
		if (str[0] == '1')
			exit_error_game("Error: Wrong .cub file.", 1, file);
		line++;
	}
	return (0);
}

int	check_extension_png(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[0] == '.')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == '.' && str[i + 1] != '\0')
		{
			if (str[i + 1] != 'p')
				return (0);
			if (str[i + 2] != 'n')
				return (0);
			if (str[i + 3] != 'g')
				return (0);
			if (str[i + 4] != '\0')
				return (0);
		}
		if (str[i + 1] == '\0' && str[i] != 'g')
			return (0);
		i++;
	}
	return (1);
}
