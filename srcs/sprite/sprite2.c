/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 16:27:55 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/02 18:39:18 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/struct.h"

void	drawspritecolor(t_map *map, t_paramspt *spt, int d)
{
	int		y;
	int		texsy;
	char	*color;

	texsy = 0;
	y = spt->drawstarty;
	while (y < spt->drawendy)
	{
		d = (y - spt->move) * 256 - map->ry * 128 + spt->spriteheight * 128;
		texsy = ((d * map->text_s->y) / spt->spriteheight) / 256;
		color = map->text_s->data + (texsy * map->text_s->sizel +
			spt->texsx * (map->text_s->bpp / 8));
		map->draw->buff = map->draw->data + (y * map->draw->sizel) +
		(spt->stripe * (map->draw->bpp / 8));
		if (*(unsigned int*)color != 0xFF000000 && *(unsigned int*)color)
			*(unsigned int*)map->draw->buff = *(unsigned int*)color;
		y++;
	}
}

void	calculsprite(t_map *map, t_paramspt *spt)
{
	double invdet;

	invdet = 1.0 / (map->plax * map->diry - map->dirx * map->play);
	spt->transx = invdet * (map->diry * spt->sptx - map->dirx * spt->spty);
	spt->transy = invdet * (-map->play * spt->sptx + map->plax * spt->spty);
	spt->spritescreenx = (int)((map->rx / 2) * (1 + spt->transx / spt->transy));
	spt->spriteheight = (int)fabs((double)map->ry / spt->transy);
	spt->move = (int)(VMOVE / spt->transy);
	spt->drawstarty = (-spt->spriteheight) / 2 + map->ry / 2 + spt->move;
	if (spt->drawstarty < 0)
		spt->drawstarty = 0;
	spt->drawendy = spt->spriteheight / 2 + map->ry / 2 + spt->move;
	if (spt->drawendy >= map->ry)
		spt->drawendy = map->ry - 1;
	spt->spritewidth = (int)fabs((double)map->ry / spt->transy);
	spt->drawstartx = (-spt->spritewidth) / 2 + spt->spritescreenx;
	if (spt->drawstartx < 0)
		spt->drawstartx = 0;
	spt->drawendx = spt->spritewidth / 2 + spt->spritescreenx;
	if (spt->drawendx >= map->rx)
		spt->drawendx = map->rx - 1;
	spt->stripe = spt->drawstartx;
}

void	drawsprite(t_map *map, t_paramspt *spt, double *zbuffer)
{
	int		d;
	double	calc;

	d = 0;
	while (spt->stripe < spt->drawendx)
	{
		calc = (spt->stripe - (-spt->spritewidth / 2 + spt->spritescreenx));
		spt->texsx = (int)(calc * map->text_s->x / spt->spritewidth);
		if (spt->transy > 0 && spt->stripe > 0 && spt->stripe < map->rx &&
			spt->transy < zbuffer[spt->stripe] && spt->texsx < map->text_s->x)
			drawspritecolor(map, spt, d);
		spt->stripe++;
	}
}
