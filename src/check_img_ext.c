/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_img_ext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jormoral <jormoral@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:50:21 by jormoral          #+#    #+#             */
/*   Updated: 2025/01/28 17:56:08 by jormoral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_extension_png(char *str)
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
			if (str[i + 1] != 'p')
				return (0);
			if (str[i + 2] != 'n')
				return (0);
			if (str[i + 3] != 'g')
				return (0);
		 	if (str[i + 4] != '\0')
				return (0);
		}
		if(str[i + 1] == '\0' && str[i] != 'g')
			return (0);
		i++;
	}
	return (1);
}
