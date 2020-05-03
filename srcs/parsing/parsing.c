/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 16:34:07 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/03 17:42:20 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/struct.h"

int		gotomap(int fd, t_map *map)
{
	char	*line;
	int		endl;
	int		startmap;
	int		ok;

	endl = 1;
	line = NULL;
	startmap = 0;
	ok = 0;
	while (endl > 0)
	{
		endl = get_next_line(fd, &line);
		if (endl >= -1)
		{
			startmap = getmapempty(line);
			if (startmap == 1)
				ok = firstlinemap(line, map);
			free(line);
			line = NULL;
			map->lmap++;
			if (ok == 1)
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
			verif = verifmap(line, map, numl);
			if (verif == 1)
				map->map[numl++] = ft_strdup(line);
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
	if (ok == 8)
		ok = ok + getlinemap(fd, map);
	else
	{
		close(fd);
		return (-1);
	}
	close(fd);
	if (ok != 9)
		return (free_map(map));
	return (1);
}

int		opencub(char *argv, t_map *map)
{
	int		fd;
	char	*line;
	int		endl;
	int		ok;

	line = NULL;
	ok = 0;
	map->nbrline = countline(argv);
	if ((fd = open(argv, O_RDONLY)) < 0)
	{
		write(1, "Error\nFichier n'existe pas\n", 27);
		return (free_opencub(map));
	}
	endl = 1;
	while (endl > 0 && ok < 8)
	{
		endl = get_next_line(fd, &line);
		if (endl > -1)
		{
			ok = ok + verifline(line, map);
			free_null(&line);
			map->lmap++;
		}
	}
	return (opencubmap(map, ok, fd));
}

int		parsing(char *argv, t_map *map)
{
	if (!argv)
	{
		write(1, "Error\nPas d'arguments\n", 22);
		return (-1);
	}
	if (verif_ext((char *)argv) == -1)
		return (-1);
	init_s_map(&map);
	if (opencub((char *)argv, map) == (-2))
		return (-1);
	if (writeerror(map) == 0)
		return (1);
	return (-1);
}
