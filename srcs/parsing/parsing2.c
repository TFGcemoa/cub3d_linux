/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 16:39:59 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/03 21:40:20 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/struct.h"

int		verif_id_line(char *line, int i, t_map *map)
{
	int leng;
	int ok;

	leng = ft_strlen(line);
	ok = 0;
	if (i > leng - 2)
		return (0);
	if (line[i] == 'R' && map->rx == 0 && map->ry == 0)
		ok = line_r(line, i, map);
	else if (line[i] == 'N' && line[i + 1] == 'O' && map->no == NULL)
		ok = line_no(line, i, map);
	else if (line[i] == 'S' && line[i + 1] == 'O' && map->so == NULL)
		ok = line_so(line, i, map);
	else if (line[i] == 'W' && line[i + 1] == 'E' && map->we == NULL)
		ok = line_we(line, i, map);
	else if (line[i] == 'E' && line[i + 1] == 'A' && map->ea == NULL)
		ok = line_ea(line, i, map);
	else if (line[i] == 'F' && map->f == -1)
		ok = line_f(line, i, map);
	else if (line[i] == 'C' && map->c == -1)
		ok = line_c(line, i, map);
	else if (line[i] == 'S' && map->s == NULL)
		ok = line_s(line, i, map);
	ok = (ok < 0) ? 0 : ok;
	return (ok);
}

int		verifline(char *line, t_map *map)
{
	int leng;
	int	i;
	int ok;

	ok = 0;
	i = 0;
	leng = ft_strlen(line);
	while (i < leng && ok == 0)
	{
		ok = verif_id_line(line, i, map);
		i++;
	}
	return (ok);
}

int		firstlinemap(char *line, t_map *map)
{
	int	i;

	i = map->nbrline - map->lmap + 1;
	if (verifmap(line, map, 0) == 1)
	{
		if (!(map->map = ft_calloc(sizeof(char*), i)))
			return (-1);
		if (!(map->map[0] = ft_strdup(line)))
			return (-1);
		return (1);
	}
	return (-1);
}
