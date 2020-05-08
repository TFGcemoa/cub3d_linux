/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 16:34:07 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/04 16:43:23 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/struct.h"

int		gotomap(int fd, t_map *map)
{
	char	*line;
	int		ijk[3];

	ijk[0] = 1;
	line = NULL;
	ijk[1] = 0;
	ijk[2] = 0;
	while (ijk[0] > 0)
	{
		ijk[0] = get_next_line(fd, &line);
		if (ijk[0] >= -1)
		{
			ijk[1] = getmapempty(line, map);
			if (ijk[1] == 1)
				ijk[2] = firstlinemap(line, map);
			free(line);
			line = NULL;
			map->lmap++;
			if (ijk[2] == 1)
				return (1);
		}
	}
	return (-1);
}

int		getlinemap(int fd, t_map *map)
{
	char	*line;
	int		verif;
	int		endl;
	int		numl;

	endl = 1;
	numl = 1;
	line = NULL;
	if (gotomap(fd, map) == -1)
		return (-1);
	while (endl > 0)
	{
		endl = get_next_line(fd, &line);
		if (endl >= -1)
		{
			if ((verif = verifmap(line, map, numl)) == 1)
				map->map[numl] = ft_strdup(line);
			numl = (map->map[numl]) ? numl + 1 : numl;
			free(line);
			line = NULL;
			if (verif == -1)
				return (-1);
		}
	}
	return (1);
}

int		opencubmap(t_map *map, int ok, int fd)
{
	ok = ok + getlinemap(fd, map);
	close(fd);
	return (1);
}
#include <stdio.h>
int		opencub(char *argv, t_map *map)
{
	int		fd;
	char	*line;
	int		endl;
	int		ok;

	line = NULL;
	map->nbrline = countline(argv);
	endl = 1;
	ok = 0;
	if ((fd = open(argv, O_RDONLY)) < 0)
		return (-2);
	while (endl > 0 && ok < 8)
	{
		endl = get_next_line(fd, &line);
		if (endl > -1)
		{
			ok = verifline(line, map, ok);
			free_null(&line);
			map->lmap++;
		}
	}
	opencubmap(map, ok, fd);
	return (0);
}

int		parsing2(char *argv, t_map *map)
{
	int	fd;

	fd = 0;
	if (!argv)
	{
		write(1, "Error\nPas d'arguments\n", 22);
		return (-1);
	}
	if (verif_ext((char *)argv) == -1)
		return (-1);
	if ((fd = open(argv, O_RDONLY)) < 0)
	{
		write(1, "Error\nFichier n'existe pas\n", 27);
		return (-1);
	}
	close(fd);
	if (init_s_map(&map) == -1)
		return (-1);
	if ((opencub((char *)argv, map)) == -1)
		return (free_opencub(map));
	if (writeerror(map) == 0)
		return (1);
	return (-1);
}
