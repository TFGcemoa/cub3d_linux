/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 16:38:10 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/08 16:35:31 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/struct.h"

int		countline(char *argv)
{
	int		i;
	int		fd;
	char	*line;
	int		endl;

	i = 0;
	line = NULL;
	endl = 1;
	if ((fd = open(argv, O_RDONLY)) < 0)
		return (-1);
	while (endl > 0)
	{
		endl = get_next_line(fd, &line);
		if (endl >= 0)
		{
			free(line);
			line = NULL;
			i++;
		}
	}
	close(fd);
	return (i);
}

int		getmapempty(char *line, t_map *map)
{
	static int	buff = 0;
	int			i;

	i = 0;
	while (line[i] != '1' && line[i] != '\0')
	{
		if (line[i] >= '!' && line[i] <= '~' && buff == 0)
		{
			map->error = ft_strjoins1(map->error, "Clé inconnue ou double\n");
			buff = 1;
			return (0);
		}
		i++;
	}
	if (line[i] == '1')
		return (1);
	return (0);
}

int		tryopentext(char *str)
{
	int		fd;
	int		leng;
	char	*path;

	if ((path = ft_worddup(str)) == NULL)
		return (-1);
	leng = ft_strlen(path) - 1;
	while (ft_isspace(path[leng]) == 1 && path[leng] != 0)
		leng--;
	if (path[leng] == 0)
		return (free_null(&path));
	if (path[leng] != 'm' && path[leng - 1] != 'p' && path[leng - 2] != 'x' &&
		path[leng - 3] != '.')
		return (free_null(&path));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (free_null(&path));
	close(fd);
	free_null(&path);
	return (0);
}

int		ft_verif_rgb(int r, int g, int b)
{
	if (r < 0 || r > 255)
		return (-1);
	if (g < 0 || g > 255)
		return (-1);
	if (b < 0 || b > 255)
		return (-1);
	return (0);
}

void	freergb(char **r, char **g, char **b)
{
	if (*r)
		free(*r);
	if (*g)
		free(*g);
	if (*b)
		free(*b);
}
