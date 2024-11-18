/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:25:37 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/11/18 12:35:08 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	print_infile(s_cube *file)
{
	char *forprint = file->fdcontent;
	printf("Este es el contenido de CUBE:file.fdcontent:\n\n%s", forprint);
}

void	print_split(s_cube *file)
{
	int i;

	i = 0;
	while(file->dumpcontent[i])
	{
		printf("%s\n", file->dumpcontent[i]);
		i++;
	}	
}

void 	print_textures_path(s_cube *file)
{
	if(file->pathtexturenorth != NULL)
		printf("\n%s\n", file->pathtexturenorth);
	else
		printf("NULL");
	if(file->pathtexturesouth != NULL)	
		printf("%s\n", file->pathtexturesouth);
	else
		printf("NULL");
	if(file->pathtexturewest != NULL)
		printf("%s\n", file->pathtexturewest);
	else
		printf("NULL");
	if(file->pathtextureeast != NULL)
		printf("%s\n", file->pathtextureeast);
	else
		printf("NULL");	
}