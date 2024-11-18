/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_colours.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:40:10 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/11/18 16:46:21 by jvalle-d         ###   ########.fr       */
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

char	*iscleanrgbtxt(char *str)
{
	int i;
	int count;
	
	i = 0;
	count = 0;
	while(str[i])
	{
		if(str[i] == ',')
		{
			if(str[i + 1] == ',')
			{
				return NULL;
			}
			count++;
		}
		i++;		
	}
	return (str);
}

int cextract_rgb(s_cube *file)
{
	char	*str;
	int		line;
	int		i;
	
	line = -1;
	while(file->dumpcontent[++line])
	{
		printf("1AQUISTR:%s\n\n", str);
		str = iscleanrgbtxt(file->dumpcontent[line]);
		printf("2AQUISTR:%s\n\n", str);
		if(!str)
			return 0;
		i = 0;
		if(str[0] == 'C')
		{
			i++;
			while(str[i++])
			{
				if(str[i] == ',')
					str[i] = ' ';
				if(str[i] == '\0')
					return file->textceilingcolour = str + 2, 1;	
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


