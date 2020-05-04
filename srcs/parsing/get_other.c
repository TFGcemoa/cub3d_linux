/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_other.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 16:46:58 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/03 21:10:30 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/struct.h"

int		line_r(char *line, int i, t_map *map)
{
	while (ft_isspace(line[i]) == 1)
		i++;
	if (line[i] == 'R')
		i++;
	while (ft_isspace(line[i]) == 1)
		i++;
	if (ft_isdigit(line[i]) == 1)
		map->rx = ft_atoi(line + i);
	else
		return (-1);
	while (ft_isdigit(line[i]) == 1)
		i++;
	while (ft_isspace(line[i]) == 1)
		i++;
	if (ft_isdigit(line[i]) == 1)
		map->ry = ft_atoi(line + i);
	else
		return (-1);
	return (1);
}

int		line_f(char *line, int i, t_map *map)
{
	int color;

	color = 0;
	while (ft_isspace(line[i]) == 1)
		i++;
	if (line[i] == 'F')
		i++;
	while (ft_isspace(line[i]) == 1)
		i++;
	if (ft_isdigit(line[i]) == 1)
		color = getrgb(line, i);
	if (color == -1)
		return (-1);
	else
		map->f = color;
	return (1);
}

int		line_c(char *line, int i, t_map *map)
{
	int color;

	color = 0;
	while (ft_isspace(line[i]) == 1)
		i++;
	if (line[i] == 'C')
		i++;
	while (ft_isspace(line[i]) == 1)
		i++;
	if (ft_isdigit(line[i]) == 1)
		color = getrgb(line, i);
	if (color == -1)
		return (-1);
	else
		map->c = color;
	return (1);
}
