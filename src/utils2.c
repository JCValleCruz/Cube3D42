/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 02:09:50 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/11/18 22:35:01 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cube3d.h"

int	check_param_dup(s_cube *file)
{
	char	*str;
	int		line;
	int		count;
	
	line = -1;
	count = 0;
	while(file->dumpcontent[++line])
	{
		str = file->dumpcontent[line];
		if(!ft_strncmp(str, "NO", 2) || !ft_strncmp(str, "SO", 2) 
			|| !ft_strncmp(str, "WE", 2) || !ft_strncmp(str, "EA", 2) 
				|| !ft_strncmp(str, "F ", 2) || !ft_strncmp(str, "C ", 2))
			count++;			
	}
	if (count != 6)
		return 1;
	return 0;
}
