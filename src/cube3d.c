/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:15:59 by gacel             #+#    #+#             */
/*   Updated: 2024/11/18 23:53:15 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
void	purge(s_cube *file)
{
	int i;
	int c;
	int len;

	i = 0;
	while(file->dumpcontent[i])
	{
		c = 0;
		file->dumpcontent[1] = ft_checkfinal_str(file->dumpcontent[1]);
		len = ft_strlen(file->dumpcontent[i]);
		while(file->dumpcontent[i][c] == ' ' || file->dumpcontent[i][c] == '\t')
			c++;
		if(!ft_check_map(file->dumpcontent[i]))	
			file->dumpcontent[i] = ft_substr(file->dumpcontent[i], c, len);
		i++;	
	}
}

void    dump_map(s_cube *file, char **argv)
{
    int fd;
    int readed;

    file->fdcontent = calloc(10000, 1);
    fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return ;
    readed = read(fd, file->fdcontent, 9999);
	if (readed < 0)
		return ;
	ft_checkfinal(file);
}

int	check_extension(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if(str[0] == '.')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == '.' && str[i + 1] != '\0')
		{
			if (str[i + 1] != 'c')
				return (0);
			if (str[i + 2] != 'u')
				return (0);
			if (str[i + 3] != 'b')
				return (0);
		 	if (str[i + 4] != '\0')
				return (0);
		}
		i++;
	}
	return (1);
}

int main(int argc, char **argv)
{
    s_cube file;
	(void)argc;    
    if(!check_extension(argv[1]))
        printf("\nError: Extensión no válida.\n\n");
    else    
        printf("\nOK: Extensión soportada.\n\n");
    dump_map(&file, argv);
	file.dumpcontent = ft_split(file.fdcontent, '\n');
	all_params(&file);
	extract_map(&file);
	printf("%d\n", dp_count(file.dumpcontent));
	printf("%s\n", file.map[3]);

	//printf("RGB FLAG:%d TXT FLAG:%d ALL:%d\n", file.rgb_flag, file.texture_flag, file.all_params_flag);
	return 0;
}