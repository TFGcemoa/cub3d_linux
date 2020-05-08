/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 16:34:07 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/08 16:33:24 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/struct.h"

int		parsing_keys2(char *line, int i, t_map *map)
{
	int	ok;

	ok = 0;
	if (line[i] == 'R' && map->parskey.r == 0)
		ok = line_r(line, i, map);
	else if (line[i] == 'N' && line[i + 1] == 'O' && map->parskey.no == 0)
		ok = line_no(line, i, map);
	else if (line[i] == 'S' && line[i + 1] == 'O' && map->parskey.so == 0)
		ok = line_so(line, i, map);
	else if (line[i] == 'W' && line[i + 1] == 'E' && map->parskey.we == 0)
		ok = line_we(line, i, map);
	else if (line[i] == 'E' && line[i + 1] == 'A' && map->parskey.ea == 0)
		ok = line_ea(line, i, map);
	else if (line[i] == 'F' && map->parskey.f == 0)
		ok = line_f(line, i, map);
	else if (line[i] == 'C' && map->parskey.c == 0)
		ok = line_c(line, i, map);
	else if (line[i] == 'S' && map->parskey.s == 0)
		ok = line_s(line, i, map);
	return (ok);
}

int		parsing_keys(char *line, t_map *map, int keys)
{
	int			ok;
	static int	error = 0;
	int			i;

	i = 0;
	ok = 0;
	map->lmap++;
	while (line[i] && (line[i] < '!' || line[i] > '~'))
		i++;
	if ((ft_strlen(line) - i) < 2)
	{
		if (error == 0 && line[i] >= '!' && line[i] <= '~')
			return (join_wrong(map, "Clé(s) inconnue(s)/double(s)\n", 1));
		return (keys);
	}
	ok = parsing_keys2(line, i, map);
	if (ok == 1)
		return (keys + 1);
	if (line[i] == '1')
		return (9);
	else if (error == 0 && ok == 0)
		return (join_wrong(map, "Clé(s) inconnue(s)/double(s)\n", 1));
	return (keys);
}

int		parsing_map(char *line, t_map *map)
{
	int			verif;
	static int	mal = 0;

	if (mal == 0)
	{
		map->lmap--;
		mal = map->nbrline - map->lmap + 1;
		if (mal <= 0)
		{
			mal = 1;
			return (10);
		}
		if (!(map->map = ft_calloc(sizeof(char*), mal)))
			return (10);
	}
	verif = 0;
	if ((verif = verifmap(line, map, map->numl)) == 1)
	{
		map->map[map->numl] = ft_strdup(line);
		map->numl = (map->map[map->numl]) ? map->numl + 1 : map->numl;
	}
	else
		return (10);
	return (9);
}

int		parsing_keys_map(char *argv, t_map *map)
{
	int		fd;
	int		endl;
	int		keys;
	char	*line;

	endl = 1;
	keys = 0;
	line = NULL;
	if ((fd = open(argv, O_RDONLY)) < 0)
		return (0);
	while ((endl = get_next_line(fd, &line)) > 0)
	{
		if (endl >= -1)
		{
			if (keys < 9)
				keys = parsing_keys(line, map, keys);
			if (keys == 9)
				keys = parsing_map(line, map);
			if (keys >= 10)
				verif_end_file(line, map);
			free_null(&line);
		}
	}
	return (0);
}

int		parsing(char *argv, t_map *map)
{
	if ((check_file(argv, map)) == -1)
		return (-1);
	if (init_s_map(&map) == -1)
		return (-1);
	parsing_keys_map(argv, map);
	ft_realloc(map);
	if (parsing_error(map) < 0)
		return (-1);
	return (0);
}
