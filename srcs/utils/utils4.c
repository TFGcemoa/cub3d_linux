/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 13:37:09 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/03 22:56:46 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/struct.h"

int		initdraw(t_draw **draw)
{
	if (!(*draw = malloc(sizeof(t_draw))))
		return (-1);
	(*draw)->drws = 0;
	(*draw)->drwe = 0;
	(*draw)->linh = 0;
	return (0);
}

int		verif_img(t_map *m)
{
	if (!m->text_no->img || !m->text_no->data ||
		!m->text_so->img || !m->text_so->data ||
		!m->text_ea->img || !m->text_ea->data ||
		!m->text_we->img || !m->text_we->data ||
		!m->text_s->img || !m->text_s->data ||
		!m->draw->img || !m->draw->data)
		return (free_all(m));
	return (0);

}

int		init_img(t_map *map)
{
	if (!(map->win->mlx = mlx_init()))
		return (free_all(map));
	set_res(map);
	map->draw->img = mlx_new_image(map->win->mlx, map->rx, map->ry);
	map->draw->data = mlx_get_data_addr(map->draw->img, &map->draw->bpp,
		&map->draw->sizel, &map->draw->endian);
	set_texture(map);
	free_path(map);
	return (verif_img(map));
}