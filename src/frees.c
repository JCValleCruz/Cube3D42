/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:12:33 by jvalle-d          #+#    #+#             */
/*   Updated: 2025/01/28 17:38:00 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cube3d.h"

void	free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}

void	free_game(t_cube *file)
{
	free(file->pathtextureeast);
	mlx_delete_texture(file->east);	
	free(file->pathtexturenorth);
	mlx_delete_texture(file->north);
	free(file->pathtexturesouth);
	mlx_delete_texture(file->south);	
	free(file->pathtexturewest);
	mlx_delete_texture(file->west);
	free(file->fdcontent);
	free_split(file->dumpcontent);
	free(file->rgbceilingcolour);
	free(file->rgbfloorcolour);
	free_split(file->map);
	free_split(file->colourceilingsplit);
	free_split(file->colourfloorsplit);
	
}
void	free_game_nt(t_cube *file)
{
	free(file->pathtextureeast);
	free(file->pathtexturenorth);
	free(file->pathtexturesouth);
	free(file->pathtexturewest);
	free(file->fdcontent);
	free_split(file->dumpcontent);
	if (file->rgbceilingcolour)
		free(file->rgbceilingcolour);
	if (file->rgbfloorcolour)
		free(file->rgbfloorcolour);
	if (file->map)
		free_split(file->map);
	if (file->colourceilingsplit)
		free_split(file->colourceilingsplit);
	if (file->colourfloorsplit)
		free_split(file->colourfloorsplit);		
	//free_split(file->colourceilingsplit);
	//free_split(file->colourfloorsplit);	
}
