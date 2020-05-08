/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 16:34:07 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/07 23:22:42 by nhochstr         ###   ########.fr       */
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
	while (line[i] && (line[i] < '!' || line[i] > '~'))
		i++;
	if ((ft_strlen(line) - i) < 2)
	{
		if (error == 0 && line[i] >= '!' && line[i] <= '~')
		{
			map->error = ft_strjoins1(map->error, "Clé(s) inconnue(s)/double(s)\n");
			error = 1;
		}
		return (keys);
	}
	ok = parsing_keys2(line, i, map);
	if (ok == 1)
		return (keys + 1);
	if (line[i] == '1')
		return (9);
	else if (error == 0 && ok == 0)
	{
		map->error = ft_strjoins1(map->error, "Clé(s) inconnue(s)/double(s)\n");
		error = 1;
	}
	return (keys);
}
#include <stdio.h>

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

int		verif_end_file(char *line, t_map *map)
{
	int			i;
	static int	error = 0;

	i = 0;
	while (line[i] != '\0' && (line[i] <= '!' || line[i] >= '~'))
		i++;
	if (line[i] != '\0')
	{
		if (error == 0)
		{
			error = 1;
			if (ft_strlen(map->error) <= 6)
				map->error = ft_strjoins1(map->error, "Mauvaise carte\n");
			return (0);
		}
	}
	return (0);
}

int		parsing_keys_map(char *argv, t_map *map)
{
	int		fd;
	int		endl;
	int 	keys;
	char	*line;

	endl = 1;
	keys = 0;
	line = NULL;
	if ((fd = open(argv, O_RDONLY)) < 0)
		return (0);
	while (endl > 0)
	{
		endl = get_next_line(fd, &line);
		if (endl >= -1)
		{
			if (keys < 9)
			{
				keys = parsing_keys(line, map, keys);
				map->lmap++;
			}
			if (keys == 9)
				keys = parsing_map(line, map);
			if (keys >= 10)
				verif_end_file(line, map);
			free(line);
			line = NULL;
		}
	}
	return (0);
}

int		check_file(char *argv, t_map *map)
{
	int	fd;
	int	i;

	fd = 0;
	i = ft_strlen(argv);
	if (!argv)
	{
		write(1, "Error\nPas d'arguments\n", 22);
		return (-1);
	}
	if (argv[i - 1] != 'b' && argv[i - 2] != 'u' && argv[i - 3] != 'c' &&
		argv[i - 4] != '.')
	{
		write(1, "Error\nMauvaise extension de fichier\n", 36);
		return (-1);
	}
	map->nbrline = 0;
	if ((map->nbrline = countline(argv)) == -1)
	{
		write(1, "Error\nFichier n'existe pas\n", 27);
		return (-1);
	}
	return (0);
}

int		verif_map_final(t_map *map)
{
	if (ft_strlen(map->error) > 6)
		return (-1);
	if (map->depx == -1 || map->depy == -1)
	{
		map->error = ft_strjoins1(map->error, "Mauvaise carte\n");
		return (0);
	}
	verifendmap(map);
	return (0);
}

int 	put_error_screen(t_map *map)
{
	int	leng;

	leng = 0;
	if (map->error == NULL)
	{
		write(1, "Error\nProblème de malloc\n", 25);
		return (free_opencub(map));
	}
	if ((leng = ft_strlen(map->error)) > 6)
		ft_putstr_fd(map->error, 1);
	if (leng > 6)
		return (free_opencub(map));
	return (0);
}

int		parsing_error(t_map *map)
{
	verifsizemap(map);
	verif_map_final(map);
	if ((map->rx <= 0 || map->ry <= 0))
		map->error = ft_strjoins1(map->error, "Mauvaise résolution\n");
	if (map->no == NULL)
		map->error = ft_strjoins1(map->error, "Mauvaise texture nord\n");
	if (map->so == NULL)
		map->error = ft_strjoins1(map->error, "Mauvaise texture sud\n");
	if (map->ea == NULL)
		map->error = ft_strjoins1(map->error, "Mauvaise texture est\n");
	if (map->we == NULL)
		map->error = ft_strjoins1(map->error, "Mauvaise texture ouest\n");
	if (map->s == NULL)
		map->error = ft_strjoins1(map->error, "Mauvaise texture sprite\n");
	if (map->c < 0)
		map->error = ft_strjoins1(map->error, "Mauvaise couleur plafond\n");
	if (map->f < 0)
		map->error = ft_strjoins1(map->error, "Mauvaise couleur sol\n");
	return (put_error_screen(map));
}
#include <stdio.h>
int		ft_realoc(t_map *map)
{
	char	**buff;
	int		i;
	int		size;

	i = 0;
	buff = NULL;
	size = map->nbrline - map->lmap + 1;
	if (!map->map)
		return (0);
	if (!(buff = ft_calloc(sizeof(char*), map->numl + 1)))
		return (0);
	while (i < map->numl && map->map[i])
	{
		buff[i] = ft_strdup(map->map[i]);
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (map->map[i])
			free(map->map[i]);
		map->map[i] = NULL;
		i++;
	}
	if (map->map)
		free(map->map);
	map->map = NULL;
	if (!(map->map = ft_calloc(sizeof(char*), map->numl + 1)))
		return (0);
	i = 0;
	while (i < map->numl && buff[i])
	{
		map->map[i] = ft_strdup(buff[i]);
		i++;
	}
	if (!buff)
		return (0);
	i = 0;
	while (i < map->numl)
	{
		if (buff[i])
			free(buff[i]);
		buff[i] = NULL;
		i++;
	}
	if (buff)
		free(buff);
	buff = NULL;
	return (0);
}

int		parsing(char *argv, t_map *map)
{
	if ((check_file(argv, map)) == -1)
		return (-1);
	if (init_s_map(&map) == -1)
		return (-1);
	parsing_keys_map(argv, map);
	ft_realoc(map);
	if (parsing_error(map) < 0)
		return (-1);
	return (0);
}