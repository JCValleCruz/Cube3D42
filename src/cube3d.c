/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:15:59 by gacel             #+#    #+#             */
/*   Updated: 2024/12/11 12:53:07 by jormoral         ###   ########.fr       */
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

void raycasting(t_cube *file)
{
	(void)file;
	
}
void rotate_move(t_cube *file, double newmove)
{
	file->alpha += newmove;
	if (file->alpha < 0.0)
		file->alpha += 2 * PI;
	if (file->alpha > 2 * PI)
		file->alpha -= 2 * PI;
	file->v_dir.x = cos(file->alpha);
	file->v_dir.y = sin(file->alpha);
	/* sumamos el nuevo movimiento a nuestro alpha
	nunca puede estar alpha fuera de el rango de 360\
	y actualizamos el vector de direcion nuevo;*/
		
}

void	frontal_move(t_cube *file, double n)
{
	double	new_pos_x;
	double	new_pos_y;
	printf("posicion x: %f\n", file->position_player.x);
	printf("posicion y: %f\n", file->position_player.y);
	
	new_pos_x = file->position_player.x + n * file->v_dir.x;
	new_pos_y = file->position_player.y + n * file->v_dir.y;
	if(file->map[(int)new_pos_x][(int)new_pos_y] == '0')
	{
		file->position_player.x = new_pos_x;
		file->position_player.y = new_pos_y;
		printf("nueva posicion x: %f\n", file->position_player.x);
		printf("nueva posicion y: %f\n", file->position_player.y);
	}
	/* cuando tengamos el mapa activo comprobar como se
	comporta cerca de algo que no sea un '0'*/
	/* sumamos el movimiento(n), * la direccion en la que
	estabamos orientados, y antes de actualizar la posicion
	comprobamos si estariamos dentro del mapa*/
}


void handle_move(void *param)
{
	t_cube *file;
	file = (t_cube *)param;
	ft_draw_minimap(file);
	if(mlx_is_key_down(file->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(file->mlx);
	else if (mlx_is_key_down(file->mlx, MLX_KEY_A))
		rotate_move(file, -1 * 0.1745);
	else if (mlx_is_key_down(file->mlx, MLX_KEY_D))
		rotate_move(file, 0.1745);
	else if (mlx_is_key_down(file->mlx, MLX_KEY_W))
		frontal_move(file, 0.1);
	else if (mlx_is_key_down(file->mlx, MLX_KEY_S))
		frontal_move(file, -0.1);
	//mlx_put_pixel(file->img, file->position_player.x, file->position_player.y);
	
	/*nuestro giros van a ser de 10 grados, lo que es igual 
	a PI / 18 = 0.1745, si giramos hacia la izquierda es -1
	porque estamos girando sobre el eje x */
	raycasting(file);
	/* en base al movimiento que realicemos, tenemos que calcula la direccion
	si nos movemos hacias los lados, y si nos movemos hacia delante o atras 
	realizamos el movimiento, esto tiene que estar activo durante
	todo el programa*/
	
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
	mlx_image_to_window(file.mlx, file.img, 100, 0);
	mlx_loop_hook(file.mlx, handle_move, &file);
	mlx_loop(file.mlx);
	// funcion que libere aqui!!
	//print_split2(file.map);
	//printf("\n\n\n\n\n");
	//print_split2(file.clone_map); 
	//mlx_put_pixel()
	printf("%c\n", file.orientation);
	printf("%f\n", file.position_player.x);
	printf("%f\n", file.position_player.y);
	printf("%f\n", file.alpha);
	printf("%f\n", file.v_dir.x);
	printf("%f\n", file.v_dir.y);

	return 0;
}