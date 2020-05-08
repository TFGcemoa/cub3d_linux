/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 14:27:15 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/08 14:28:09 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/struct.h"

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
