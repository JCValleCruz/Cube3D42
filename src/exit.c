/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:39:34 by jormoral          #+#    #+#             */
/*   Updated: 2025/01/29 13:43:00 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	exit_game(t_cube *file)
{
	free_game(file);
	mlx_close_window(file->mlx);
	mlx_terminate(file->mlx);
	file = NULL;
	exit (0);
}

void	exit_error_game(char*str, int i, t_cube *file)
{
	printf("%s", str);
	free_game_nt(file);
	file = NULL;
	exit (i);
}
