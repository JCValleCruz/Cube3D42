/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:25:37 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/11/19 22:36:02 by jvalle-d         ###   ########.fr       */
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
void	print_split2(char	**str)
{
	int i;

	i = 0;
	while(str[i])
		printf("%s\n", str[i++]);
	
}
void 	print_textures_path(s_cube *file)
{
	if (extract_rgb(file))
		printf("\nError al cargar RGB.\n");
	else
	{
		printf("\nRGB FLOOR: R:%d G:%d B:%d\n",file->rgbfloorcolour[0], file->rgbfloorcolour[1], file->rgbfloorcolour[2]);
		printf("RGB CEILING: R:%d G:%d B:%d\n",file->rgbceilingcolour[0], file->rgbceilingcolour[1], file->rgbceilingcolour[2]);
	}		
	if(file->pathtexturenorth != NULL)
		printf("\n%p\n", file->pathtexturenorth);
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
		printf("%s\n\n", file->pathtextureeast);
	else
		printf("NULL");	
}
