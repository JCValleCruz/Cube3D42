/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:15:59 by gacel             #+#    #+#             */
/*   Updated: 2025/01/28 13:59:00 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"


void	purge(t_cube *file)
{
	int i;
	int c;
	int len;

	i = 0;
	while(file->dumpcontent[i])
	{
		c = 0;
		file->dumpcontent[1] = ft_checkfinal_str(file->dumpcontent[1]);
		len = ft_strlen(file->dumpcontent[i]);
		while(file->dumpcontent[i][c] == ' ' || file->dumpcontent[i][c] == '\t')
			c++;
		if(!ft_check_map(file->dumpcontent[i]))	
			file->dumpcontent[i] = ft_substr(file->dumpcontent[i], c, len);
		i++;	
	}
}

void    dump_map(t_cube *file, char **argv)
{
    int fd;
    int readed;
	if(!check_extension(argv[1]))
        exit_error("Error: cannot load file.\n", 1);
    file->fdcontent = calloc(10000, 1);
    fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit_error_game("Error:try",1,file);
    readed = read(fd, file->fdcontent, 9999);
	if (readed < 0)
		exit_error_game("Error:try",1,file);
	ft_checkfinal(file);
}

int	check_extension(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if(str[0] == '.')
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
		if(str[i + 1] == '\0' && str[i] != 'b')
			return (0);
		i++;
	}
	return (1);
}


int main(int argc, char **argv)
{
    t_cube file;
	(void)argc;
    dump_map(&file, argv);
	all_params(&file);
	check_map(&file);
	init_raycasting(&file);
	init_mlx(argv[1], &file);
	mlx_image_to_window(file.mlx, file.img, 0, 0);
	mlx_loop_hook(file.mlx, &handle_move, &file);
	mlx_loop(file.mlx);
	//mlx_terminate(file.mlx);
	//free_all(&file);
	//free_game(&file);
	//free_split(file.clone_map);
	return 0;
}