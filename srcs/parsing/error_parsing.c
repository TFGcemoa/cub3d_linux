/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 16:34:53 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/07 22:54:26 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/struct.h"

int 	put_error_screen2(t_map *map)
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

int		writeerror(t_map *map)
{
	if (map->rx <= 0 || map->ry <= 0)
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
	return (put_error_screen2(map));
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
#include <stdio.h>
int		verifendmap(t_map *map)
{
	int	i;
	int j;

	i = 0;
	if (ft_strlen(map->error) > 6)
		return (-1);
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '0' || map->map[i][j] == '2' ||
				map->map[i][j] == 'E' || map->map[i][j] == 'N' ||
				map->map[i][j] == 'S' || map->map[i][j] == 'W')
			{
				if (i == map->numl - 1 || (map->map[i + 1] && (int)ft_strlen(map->map[i + 1]) <= j))
				{
					printf("%s\n", map->map[i]);
					map->error = ft_strjoins1(map->error, "Mauvaise carte\n");
					return (-1);
				}
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
	if (ft_strlen(map->error) > 6)
		return (-1);
	if (!map->map)
	{
		map->error = ft_strjoins1(map->error, "Mauvaise carte\n");
		return (-1);
	}
	while (i < 3)
	{
		j = 0;
		if (!map->map[i])
		{
			map->error = ft_strjoins1(map->error, "Mauvaise carte\n");
			return (-1);
		}
		while (j < 3)
		{
			if (map->map[i][j])
				j++;
			else
			{
				map->error = ft_strjoins1(map->error, "Mauvaise carte\n");
				return (-1);
			}
		}
		i++;
	}
	return (0);
}
