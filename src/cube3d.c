/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalle-d <jvalle-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:15:59 by gacel             #+#    #+#             */
/*   Updated: 2024/11/16 22:33:10 by jvalle-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

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
    
    if(!check_extension(argv[1]))
        printf("\nError: Extensión no válida.\n\n");
    else    
        printf("\nOK: Extensión soportada.\n\n");
    dump_map(&file, argv);
	file.dumpcontent = ft_split(file.fdcontent, '\n');
	print_split(&file);
    return 0;
}