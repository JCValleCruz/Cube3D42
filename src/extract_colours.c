/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_colours.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:40:10 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/11/18 13:45:03 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cube3d.h"

int	colourtotext(s_cube *file)
{
	int flag;
	
	flag = 0;
	file->textfloorcolour = NULL;
	file->textceilingcolour = NULL;
	
	if(!fextract_rgb(file))
		flag = 1;
	if(!cextract_rgb(file))
		flag = 1;
	return flag;	
}

int cextract_rgb(s_cube *file)
{
	char	*str;
	int		line;
	
	line = -1;
	while(file->dumpcontent[++line])
	{
		str = file->dumpcontent[line];
		int i = 0;
		if(str[0] == 'C')
		{
			i++;
			while(str[i++])
			{
				if(str[i] == ',')
					str[i] = ' ';
				if(str[i] == '\0')
				{
					file->textceilingcolour = str + 2;
					return 1;	
				}
			}
		}
	}
	return 0;
}

int fextract_rgb(s_cube *file)
{
	char	*str;
	int		line;
	
	line = -1;
	while(file->dumpcontent[++line])
	{
		str = file->dumpcontent[line];
		int i = 0;
		if(str[0] == 'F')
		{
			i++;
			while(str[i++])
			{
				if(str[i] == ',')
					str[i] = ' ';
				if(str[i] == '\0')
				{
					file->textfloorcolour = str + 2;
					return 1;	
				}
			}
		}
	}
	free(str);
	return 0;
}


