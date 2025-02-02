/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 02:09:50 by jvalle-d          #+#    #+#             */
/*   Updated: 2025/01/30 10:23:55 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	exit_error(char *str, int i)
{
	printf("%s", str);
	exit(i);
}

int	check_param_dup(t_cube *file)
{
	char	*str;
	int		line;
	int		count;

	line = -1;
	count = 0;
	while (file->dc[++line])
	{
		str = file->dc[line];
		if (!ft_strncmp(str, "NO ", 3) || !ft_strncmp(str, "SO ", 3)
			|| !ft_strncmp(str, "WE ", 3) || !ft_strncmp(str, "EA ", 3)
			|| !ft_strncmp(str, "F ", 2) || !ft_strncmp(str, "C ", 2))
			count++;
	}
	if (count != 6)
		return (1);
	return (0);
}

int	all_params(t_cube *file)
{
	init_params(file);
	purge(file);
	if (check_param_dup(file))
		exit_error_game("Error: Wrong .cub file.", 1, file);
	if (extract_textures(file))
		exit_error_game("Error: Wrong .cub file.", 1, file);
	else
		file->texture_flag = 1;
	if (extract_rgb(file))
		exit_error_game("Error: Wrong .cub file.", 1, file);
	else
		file->rgb_flag = 1;
	if (file->texture_flag == 1 && file->rgb_flag == 1)
		file->apflag = 1;
	check_order(file);
	extract_map(file);
	clone_map(file);
	check_player(file);
	if (!check_player_location(file))
		exit_error_game("Error: Wrong .cub file.", 1, file);
	return (file->apflag);
}

int	ft_rgb_atoi(const char *str)
{
	int	result;
	int	c;

	result = 0;
	c = 0;
	if (!str)
		exit_error("Error: Wrong .cub file.", 1);
	while (str[c])
	{
		if (str[c] < '0' || str[c] > '9')
			return (256);
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
