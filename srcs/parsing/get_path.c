/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 16:45:28 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/07 18:04:06 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/struct.h"

int		line_no(char *line, int i, t_map *map)
{
	map->parskey.no = 1;
	while (ft_isspace(line[i]) == 1)
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O')
		i = i + 2;
	while (ft_isspace(line[i]) == 1)
		i++;
	if (line[i] == 0)
		return (-1);
	if (tryopentext(line + i) == -1)
		return (-1);
	map->no = ft_worddup(line + i);
	if (map->no == NULL)
		return (-1);
	return (1);
}

int		line_so(char *line, int i, t_map *map)
{
	map->parskey.so = 1;
	while (ft_isspace(line[i]) == 1)
		i++;
	if (line[i] == 'S' && line[i + 1] == 'O')
		i = i + 2;
	while (ft_isspace(line[i]) == 1)
		i++;
	if (line[i] == 0)
		return (-1);
	if (tryopentext(line + i) == -1)
		return (-1);
	map->so = ft_worddup(line + i);
	if (map->so == NULL)
		return (-1);
	return (1);
}

int		line_we(char *line, int i, t_map *map)
{
	map->parskey.we = 1;
	while (ft_isspace(line[i]) == 1)
		i++;
	if (line[i] == 'W' && line[i + 1] == 'E')
		i = i + 2;
	while (ft_isspace(line[i]) == 1)
		i++;
	if (line[i] == 0)
		return (-1);
	if (tryopentext(line + i) == -1)
		return (-1);
	map->we = ft_worddup(line + i);
	if (map->we == NULL)
		return (-1);
	return (1);
}

int		line_ea(char *line, int i, t_map *map)
{
	map->parskey.ea = 1;
	while (ft_isspace(line[i]) == 1)
		i++;
	if (line[i] == 'E' && line[i + 1] == 'A')
		i = i + 2;
	while (ft_isspace(line[i]) == 1)
		i++;
	if (line[i] == 0)
		return (-1);
	if (tryopentext(line + i) == -1)
		return (-1);
	map->ea = ft_worddup(line + i);
	if (map->ea == NULL)
		return (-1);
	return (1);
}

int		line_s(char *line, int i, t_map *map)
{
	map->parskey.s = 1;
	while (ft_isspace(line[i]) == 1)
		i++;
	if (line[i] == 'S')
		i++;
	while (ft_isspace(line[i]) == 1)
		i++;
	if (line[i] == 0)
		return (-1);
	if (tryopentext(line + i) == -1)
		return (-1);
	map->s = ft_worddup(line + i);
	if (map->s == NULL)
		return (-1);
	return (1);
}
