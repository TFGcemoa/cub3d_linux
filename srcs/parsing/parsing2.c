/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 16:39:59 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/04 17:35:43 by nhochstr         ###   ########.fr       */
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
		return (-1);
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
	return (ok);
}

int		ft_isprintnodigit(char c)
{
	if (c >= '!' && c <= '/')
		return (1);
	if (c >= ':' && c <= '~')
		return (1);
	return (0);
}
#include <stdio.h>
int		verifline(char *line, t_map *map, int oldok)
{
	int			i;
	int 		ok;
	static int	buff = 0;

	i = 0;
	while (line[i] <= '!' && line[i] >= '~' && line[i] != '\0')
		i++;
	ok = verif_id_line(line, i, map);
	if (ok == 0)
	{
		if (line[i] == '1')
			return (8);
		if (buff == 0)
		{
			map->error = ft_strjoins1(map->error, "Clé inconnue ou double\n");
			printf("%s - %i\n", line, map->lmap);
		}
		buff = 1;
		return (oldok);
	}
	if (ok == 1)
		return (oldok + 1);
	return (oldok);
}

int		firstlinemap(char *line, t_map *m)
{
	int	i;
	int	j;

	i = m->nbrline - m->lmap + 1;
	j = verifmap(line, m, 0);
	if (j == 1)
	{
		if (!(m->map = ft_calloc(sizeof(char*), i)))
			return (-1);
		if (!(m->map[0] = ft_strdup(line)))
			return (-1);
	}
	else if (j == -1)
		return (-1);
	return (1);
}
