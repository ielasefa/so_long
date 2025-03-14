/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iel-asef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:18:19 by iel-asef          #+#    #+#             */
/*   Updated: 2025/02/13 19:18:21 by iel-asef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "so_long.h"

char	*add_line(char *all_lines, char *line)
{
	char	*temp;

	if (all_lines == NULL)
		return (ft_strdup(line));
	temp = ft_strjoin(all_lines, line);
	free(all_lines);
	return (temp);
}

char	**get_maps(int fd)
{
	char	*line;
	char	*all_lines;
	char	**map_array;

	all_lines = NULL;
	line = get_next_line(fd);
	while (line  != NULL)
	{
		if (line[0] == '\n')
		{
			free(line);
			free(all_lines);
			return (NULL);
		}
		all_lines = add_line(all_lines, line);
		free(line);
		line = get_next_line(fd);
	}
	if (!all_lines)
		return (NULL);
	map_array = ft_split(all_lines, '\n');
	free(all_lines);
	return (map_array);
}

int	open_map(char *filename)
{
	int	i;
	int	fd;

	i = ft_strlen(filename);
	if (i <= 4)
	{
		ft_printf("Error\nUsage: %s <*.ber>\n", filename);
		exit(1);
	}
	if (ft_strncmp(".ber", (filename + i) - 4, 4) != 0)
	{
		ft_printf("Error\nUsage: %s <*.ber>\n", filename);
		exit(1);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nl fichier ma kaynch ola ma kayt7lch\n");
		return (-1);
	}
	return (fd);
}
