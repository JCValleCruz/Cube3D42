/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:15:59 by gacel             #+#    #+#             */
/*   Updated: 2025/01/29 17:54:28 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	purge(t_cube *file)
{
	int		i;
	int		c;
	int		len;
	char	*aux;

	i = 0;
	while (file->dc[i])
	{
		c = 0;
		file->dc[1] = ft_cf_str(file->dc[1]);
		len = ft_strlen(file->dc[i]);
		while (file->dc[i][c] == ' '
			|| file->dc[i][c] == '\t')
			c++;
		if (!ft_check_map(file->dc[i]))
		{
			aux = ft_strdup(file->dc[i]);
			free(file->dc[i]);
			file->dc[i] = ft_substr(aux, c, len);
			free(aux);
		}
		i++;
	}
}

void	dump_map(t_cube *file, char **argv)
{
	int	fd;
	int	readed;

	if (!check_extension(argv[1]))
		exit_error("Error: cannot load file.", 1);
	file->fdcontent = calloc(10000, 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_error_game("Error: infile error.", 1, file);
	readed = read(fd, file->fdcontent, 9999);
	if (readed < 0)
		exit_error_game("Error: infile error.", 1, file);
	ft_checkfinal(file);
}

int	check_extension(char *str)
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
			if (str[i + 1] != 'c')
				return (0);
			if (str[i + 2] != 'u')
				return (0);
			if (str[i + 3] != 'b')
				return (0);
			if (str[i + 4] != '\0')
				return (0);
		}
		if (str[i + 1] == '\0' && str[i] != 'b')
			return (0);
		i++;
	}
	return (1);
}

void	check_cub_permission(char **argv)
{
	if (access(argv[1], R_OK) == -1)
	{
		printf("Error: Invalid .cub file permission.");
		exit (1);
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_cube	file;

	(void) argc;
	if (argc != 2)
		exit_error("Error: invalid number of arguments.\n", 1);
	check_cub_permission(argv);
	dump_map(&file, argv);
	ft_cf_str_n(file.fdcontent);
	all_params(&file);
	check_map(&file);
	check_permission(&file);
	init_raycasting(&file);
	init_mlx(argv[1], &file);
	mlx_image_to_window(file.mlx, file.img, 0, 0);
	mlx_loop_hook(file.mlx, &handle_move, &file);
	mlx_loop(file.mlx);
	exit_game(&file);
	return (0);
}
