/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:18:57 by jvalle-d          #+#    #+#             */
/*   Updated: 2024/12/10 13:43:19 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/cube3d.h"

void	extract_map(s_cube *file)
{
	int		i;
	int		line;
	int		n;

	i = -1;
	line = -1;
	n = 0;
	while(file->dumpcontent[++line])
	{
		i = -1;
		while(file->dumpcontent[line][++i])
		{
			if(file->dumpcontent[line][i] == '1' && file->dumpcontent[line][i + 1] == '1' 
				&& file->all_params_flag == 1)
			{			
				file->map = (char **)ft_calloc((dp_count(file->dumpcontent) - 6), sizeof(char *));
				while(file->dumpcontent[line])
				{
					file->map[n++] = ft_strdup(file->dumpcontent[line++]);
					if(file->dumpcontent[line] == NULL)
						return;		
				}	
			}
		}
	}
}

void	no_tabs(s_cube *file)
{
	int		line;
	int		i;
	char	*str;

	line = 0;
	while(file->dumpcontent[line])
	{
		i = 0;
		str = file->dumpcontent[line];
		while(str[i])
		{
			if(str[i] == '\t')
				exit_error("Error: infile contains tab characters.", 1);
			i++;				
		}
		line++;
	}
	
}

void pmap(s_cube	*file)
{
	int 	i;
	char	*str;

	i = 0;
	str = file->fdcontent;
	while(str[i])
		i++;
	i--;	
	while(i > 0)
	{	
		while(str[i] == ' ' || str[i] == '\n' || (str[i] >= 9 && str[i] <= 13))
			i--;
		if(str[i - 1] != '1')
			exit_error("Error: infile incorrect.", 1);
		printf("%s\n",file->fdcontent);
		if(str[i - 1] == '1' && str[i - 2] == '1' && str[i - 3] == '1')
			return ;
		i--;		
	}
}
