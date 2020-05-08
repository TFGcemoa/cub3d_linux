/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 15:35:27 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/08 17:05:56 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/struct.h"

int	verif_end_file(char *line, t_map *map)
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

int	check_file(char *argv, t_map *map)
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

int	map_realloc(t_map *map, char **buff)
{
	int	i;

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
		buff[i++] = NULL;
	}
	if (buff)
		free(buff);
	buff = NULL;
	return (0);
}

int	ft_realloc(t_map *map)
{
	char	**buff;
	int		i;

	i = 0;
	buff = NULL;
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
	while (i < (map->nbrline - map->lmap + 1))
	{
		if (map->map[i])
			free(map->map[i]);
		map->map[i++] = NULL;
	}
	if (map->map)
		free(map->map);
	map_realloc(map, buff);
	return (0);
}

int	join_wrong(t_map *map, char *str, int r)
{
	map->error = ft_strjoins1(map->error, str);
	return (r);
}
