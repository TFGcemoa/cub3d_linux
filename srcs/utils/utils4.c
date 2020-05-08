/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 13:37:09 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/07 17:55:42 by nhochstr         ###   ########.fr       */
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

void	init_parskey(t_map *map)
{
	map->parskey.r = 0;
	map->parskey.no = 0;
	map->parskey.so = 0;
	map->parskey.ea = 0;
	map->parskey.we = 0;
	map->parskey.s = 0;
	map->parskey.f = 0;
	map->parskey.c = 0;
}

char	*ft_worddup(char *s)
{
	char	*ptr;
	int		ij[2];

	if (!s)
		return (NULL);
	ij[0] = 0;
	while (s[ij[0]] != '\0' && ft_isspace(s[ij[0]]) == 0)
		ij[0]++;
	ij[1] = ij[0];
	while (s[ij[1]] != '\0')
	{
		if (ft_isspace(s[ij[1]]) == 0)
			return (NULL);
		ij[1]++;
	}
	if (!(ptr = malloc(ij[0] * sizeof(char) + 1)))
		return (NULL);
	ij[0] = 0;
	while (s[ij[0]] != '\0' && ft_isspace(s[ij[0]]) == 0)
	{
		ptr[ij[0]] = s[ij[0]];
		ij[0]++;
	}
	ptr[ij[0]] = '\0';
	return (ptr);
}
