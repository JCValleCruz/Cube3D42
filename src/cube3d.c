/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:15:59 by gacel             #+#    #+#             */
/*   Updated: 2024/12/05 13:31:06 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
void	purge(s_cube *file)
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

void    dump_map(s_cube *file, char **argv)
{
    int fd;
    int readed;
	
	if(!check_extension(argv[1]))
        exit_error("Error: cannot load file.\n", 1);
    file->fdcontent = calloc(10000, 1);
    fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return ;
    readed = read(fd, file->fdcontent, 9999);
	if (readed < 0)
		return ;
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
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
    s_cube file;
	(void)argc;    
    dump_map(&file, argv);	
	all_params(&file);
	check_map(&file);
	init_raycasting(&file);
	init_mlx(argv[1], &file);
	mlx_image_to_window(file.mlx, file.img, 0, 0);
	//print_split2(file.map);
	//printf("\n\n\n\n\n");
	//print_split2(file.clone_map); 
/* 	printf("%c\n", file.orientation);
	printf("%f\n", file.position_player.x);
	printf("%f\n", file.position_player.y);
	printf("%f\n", file.alpha);
	printf("%f\n", file.v_dir.x);
	printf("%f\n", file.v_dir.y); */

	return 0;
}