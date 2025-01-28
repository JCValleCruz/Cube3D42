/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_colours.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:40:10 by jvalle-d          #+#    #+#             */
/*   Updated: 2025/01/28 13:59:19 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cube3d.h"


int	extract_rgb(t_cube *file)
{
	int flag;
	
	flag = 0;
	if(!fextract_rgb(file))
		flag = 1;
	if(!cextract_rgb(file))
		flag = 1;
	if(flag == 0)
	{
		file->colourfloorsplit = ft_split(file->textfloorcolour, ' ');
		file->colourceilingsplit = ft_split(file->textceilingcolour, ' ');
		if(split_to_rgb(file))
			flag = 1;
	}
	if(file->rgbceilingcolour[0] == 0 && file->colourceilingsplit[1] == 0 
		&& file->rgbceilingcolour == 0 && file->rgbfloorcolour[0] == 0 
			&& file->rgbfloorcolour[1] == 0 && file->rgbfloorcolour == 0)
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
				exit_error("Error: Cannot load rgb values.\n", 1);
			count++;
		if(count > 2)
			exit_error("Error: Cannot load rgb values.\n", 1);
		}
		i++;		
	}
	return (str);
}

int cextract_rgb(t_cube *file)
{
	char	*str;
	int		line;
	int		i;
	
	line = -1;
	while(file->dumpcontent[++line])
	{
		str = iscleanrgbtxt(file->dumpcontent[line]);
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

int fextract_rgb(t_cube *file)
{
	char	*str;
	int		line;
	int		i;
	
	line = -1;
	while(file->dumpcontent[++line])
	{
		str = iscleanrgbtxt(file->dumpcontent[line]);
		if(!str)
			return 0;
		i = 0;
		if(str[0] == 'F')
		{
			i++;
			while(str[i++])
			{
				if(str[i] == ',')
					str[i] = ' ';
				if(str[i] == '\0')
					return file->textfloorcolour = str + 2, 1;	
			}
		}
	}
	return 0;
}

int	split_to_rgb(t_cube *file)
{
	int		c;
	char	**txt_rgb;
	
	c = 0;
	txt_rgb = file->colourfloorsplit;
	if (!txt_rgb || !txt_rgb[0] || !txt_rgb[1] || !txt_rgb[2])
    	return 1;
	while(c < 3)
	{
		file->rgbfloorcolour[c] = ft_rgb_atoi(txt_rgb[c]);
		if(file->rgbfloorcolour[c] > 255)
			return 1;
		c++;
	}
	c = 0;
	txt_rgb = file->colourceilingsplit;
	while(c < 3)
	{
		file->rgbceilingcolour[c] = ft_rgb_atoi(txt_rgb[c]);
		if(file->rgbceilingcolour[c] > 255)
			return 1;
		c++;
	}
	return 0;
}