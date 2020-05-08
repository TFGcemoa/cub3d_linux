/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 16:40:54 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/07 22:48:38 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/struct.h"

int		ismap(char c, t_map *map, int i, int numl)
{
	static int ori = 0;

	if (c == ' ' || c == '1' || c == '0' || c == '2')
	{
		if (c == '2')
			map->numsprite++;
		return (0);
	}
	if ((c == 'N' || c == 'E' || c == 'S' || c == 'W') && ori == 0)
	{
		map->depx = numl + 0.5;
		map->depy = i + 0.5;
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			init_ori(map, c);
		ori = 1;
		return (0);
	}
	return (-1);
}

int		verifspacemap(char *line, int i, t_map *map, int numl)
{
	int top;
	int left;

	top = 0;
	left = 0;
	if (numl == 0 || !(map->map[numl - 1][i]))
		top = 1;
	else if (map->map[numl - 1][i] == ' ' || map->map[numl - 1][i] == '1')
		top = 1;
	if (i == 0 || !line[i - 1])
		left = 1;
	else if (line[i - 1] == ' ' || line[i - 1] == '1')
		left = 1;
	if (top == 1 && left == 1)
		return (1);
	return (-1);
}

int		verifothermap(char *line, int i, t_map *map, int numl)
{
	if (numl == 0 || !(map->map[numl - 1][i]) || map->map[numl - 1][i] == ' ')
		return (-1);
	if (i == 0 || !line[i - 1] || line[i - 1] == ' ')
		return (-1);
	if (i == (int)ft_strlen(line) - 1)
		return (-1);
	if (!line[i + 1] || line[i + 1] == ' ')
		return (-1);
	if (numl == (map->nbrline - map->lmap - 1))
		return (-1);
	return (1);
}

int		verifcharmap(char *line, int i, t_map *map, int numl)
{
	int ok;

	ok = -1;
	if (line[i] == ' ')
		ok = verifspacemap(line, i, map, numl);
	else if (line[i] == '1')
		ok = 1;
	else
		ok = verifothermap(line, i, map, numl);
	return (ok);
}

int		verifmap(char *line, t_map *map, int numl)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (ismap(line[i], map, i, numl) == -1)
		{
			if (ft_strlen(map->error) <= 6)
				map->error = ft_strjoins1(map->error, "Mauvaise carte\n");
			return (-1);
		}
		if (verifcharmap(line, i, map, numl) == -1)
		{
			if (ft_strlen(map->error) <= 6)
				map->error = ft_strjoins1(map->error, "Mauvaise carte\n");
			return (-1);
		}
		i++;
	}
	if (line[0] == '\0')
		return (-1);
	return (1);
}
