/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:55:20 by jvalle-d          #+#    #+#             */
/*   Updated: 2025/01/29 13:46:10 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	check_characters(t_cube *file)
{
	int		line;
	int		i;
	char	*str;

	line = 0;
	while (file->map[line])
	{
		i = 0;
		str = file->map[line];
		while (str[i])
		{
			if (str[i] != '0' && str[i] != '1' && str[i] != 'N' && str[i] != 'S'
				&& str[i] != 'W' && str[i] != 'E' && str[i] != ' '
				&& str[i] != '\t')
				return (1);
			i++;
		}
		line++;
	}
	return (0);
}

int	check_x(t_cube *file)
{
	char	*str;
	int		i;

	str = file->map[0];
	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			return (1);
		i++;
	}
	str = file->map[dp_count(file->map) - 1];
	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			return (1);
		i++;
	}
	return (0);
}

int	check_y(t_cube *file)
{
	int		line;
	int		i;

	line = 0;
	while (file->map[line])
	{
		i = 0;
		while (file->map[line][i] == ' ')
			i++;
		if (file->map[line][i] == '0')
			return (1);
		line++;
	}
	line = 0;
	while (file->map[line])
	{
		if (file->map[line][ft_strlen(file->map[line]) - 1] == '0')
			return (1);
		line++;
	}
	return (0);
}

int	check_zero(t_cube *file)
{
	int	line;
	int	i;

	line = 1;
	while (line < dp_count(file->map))
	{
		i = 1;
		while (file->map[line][i++])
		{
			if ((file->map[line][i] == '0' && (size_t)i
				> ft_strlen(file->map[line + 1]))
				|| (file->map[line][i] == '0'
				&& (size_t)i > ft_strlen(file->map[line - 1])))
				return (1);
			if ((file->map[line][i] == '0') && ((file->map[line - 1][i] == ' '
				|| file->map[line + 1][i] == ' '
					|| file->map[line][i - 1] == ' '
					|| file->map[line][i + 1] == ' '
					|| (size_t)i > ft_strlen(file->map[line - 1])
					|| (size_t)i >= ft_strlen(file->map[line + 1]))))
				return (1);
		}
		line++;
	}
	return (0);
}

int	check_map(t_cube *file)
{
	if (check_x(file))
		exit_error_game("Error: Wrong .cub file.", 1, file);
	if (check_y(file))
		exit_error_game("Error: Wrong .cub file.", 1, file);
	if (check_characters(file))
		exit_error_game("Error: Wrong .cub file.", 1, file);
	if (check_invalid_line(file))
		exit_error_game("Error: Wrong .cub file.", 1, file);
	if (broken_map(file))
		exit_error_game("Error: Wrong .cub file.", 1, file);
	if (check_zero(file))
		exit_error_game("Error: Wrong .cub file.", 1, file);
	if (check_nullzero(file))
		exit_error_game("Error: Wrong .cub file.", 1, file);
	return (0);
}
