/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:32:03 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/11/19 22:36:54 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	init_params(s_cube *file)
{
	file->pathtexturenorth = NULL;
	file->pathtexturesouth = NULL;
	file->pathtexturewest = NULL;
	file->pathtextureeast = NULL;
	file->dumpcontent = ft_split(file->fdcontent, '\n');
	file->textfloorcolour = NULL;
	file->textceilingcolour = NULL;
	file->rgbceilingcolour = (int *)malloc(sizeof(int) * 3);
	file->rgbfloorcolour = (int *)malloc(sizeof(int) * 3);
	file->map = NULL; //Mandar a init
	file->dumpsize = dp_count(file->dumpcontent);
	file->rgb_flag = 0;
	file->texture_flag = 0;
	file->all_params_flag = 0;
}
