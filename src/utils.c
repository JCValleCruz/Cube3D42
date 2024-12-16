/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:35:10 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/12/05 18:28:27 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void    ft_checkfinal(t_cube *file)
{
	char *str;

    int i = 0;
    int n = 1;
	str = file->fdcontent;
	while (str[i] != '\0')
        i++;
    while (str[i - n] != '1')
    {
        str[i - n] = str[i];
        n++;
    }
    file->fdcontent = str;
}

char    *ft_checkfinal_str(char *str)
{
    int i = 0;
    int n = 1;
	while (str[i] != '\0')
	    i++;
	while (str[i - n] == ' ')
    {
        str[i - n] = str[i];
        n++;
    }
    return(str);
}

char	*ft_check_spaces(char *str)
{
	int 	c;
	
	c = 0;
	while(str[c] == ' ')
		c++;
	return (str + c);
}

int	ft_check_map(char *str)
{
	int c;

	c = 0;
	while(str[c])
	{
		if(str[c] == '1')
			return 1;
		c++;
	}
	return 0;
}

int	dp_count(char **str)
{
	int line;

	line = 0;
	while(str[line])
		line++;
	return (line);	
}