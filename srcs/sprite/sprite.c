/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 16:25:43 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/04 00:43:37 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/struct.h"

void	sortsprites(t_map *m ,int i, int j)
{
	double				x;
	double				y;
	double				dist;

	x = m->slist[i].x;
	y = m->slist[i].y;
	dist = m->slist[i].dist;

	m->slist[i].x = m->slist[j].x;
	m->slist[i].y = m->slist[j].y;
	m->slist[i].dist = m->slist[j].dist;

	m->slist[j].x = x;
	m->slist[j].y = y;
	m->slist[j].dist = dist;
}


void	classsprite(t_map *m)
{
	double	a;
	double	b;
	int		i;
	int		j;

	i = 0;
	while (i < m->numsprite)
	{
		a = (m->str.posx - m->slist[i].x) * (m->str.posx - m->slist[i].x);
		b = (m->str.posy - m->slist[i].y) * (m->str.posy - m->slist[i].y);
		m->slist[i++].dist = (a + b);
	}
	i = 0;
	while (i < m->numsprite)
	{
		j = i;
		while (j < m->numsprite)
		{
			if (m->slist[i].dist < m->slist[j].dist)
				sortsprites(m, i, j);
			j++;
		}
		i++;
	}
}

int		preparesprite(t_map *map, double *zbuffer)
{
	int			i;
	t_paramspt	spt;

	if (map->numsprite <= 0)
		return (0);
	classsprite(map);
	i = 0;
	while (i < map->numsprite)
	{
		spt.sptx = map->slist[i].x - map->str.posx;
		spt.spty = map->slist[i].y - map->str.posy;
		calculsprite(map, &spt);
		drawsprite(map, &spt, zbuffer);
		i++;
	}
	return (0);
}
