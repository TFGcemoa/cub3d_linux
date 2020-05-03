/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 16:34:53 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/03 17:47:10 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/struct.h"

int		writeerror(t_map *map)
{
	int		leng;

	if (map->rx == 0 || map->ry == 0)
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
	verifsizemap(map);
	if ((leng = ft_strlen(map->error)) > 6)
		ft_putstr_fd(map->error, 1);
	if (leng > 6)
		return (free_opencub(map));
	return (0);
}

int		verif_ext(char *argv)
{
	int	i;

	i = ft_strlen(argv);
	if (argv[i - 1] == 'b' && argv[i - 2] == 'u' && argv[i - 3] == 'c' &&
		argv[i - 4] == '.')
		return (0);
	else
		write(1, "Error\nMauvaise extension de fichier\n", 36);
	return (-1);
}

int		verifendmap(t_map *map)
{
	int	i;
	int j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '0' || map->map[i][j] == '2' ||
				map->map[i][j] == 'E' || map->map[i][j] == 'N' ||
				map->map[i][j] == 'S' || map->map[i][j] == 'W')
			{
				if (map->map[i + 1] && !map->map[i + 1][j])
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		verifsizemap(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	if (!map->map)
		return (0);
	if (map->depx == -1 || map->depy == -1)
		return (free_map(map));
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (map->map[i][j])
				j++;
			else
				return (free_map(map));
		}
		i++;
	}
	if (verifendmap(map) == -1)
		return (free_map(map));
	return (0);
}
