/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 16:06:41 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/07 20:40:23 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/struct.h"

int		init_s_text(t_text **text)
{
	if (!(*text = malloc(sizeof(t_text))))
		return (1);
	(*text)->img = NULL;
	(*text)->data = NULL;
	(*text)->bpp = 0;
	(*text)->sizel = 0;
	(*text)->endian = 0;
	(*text)->x = 0;
	(*text)->y = 0;
	return (0);
}

int		init_struc(t_map *map)
{
	int	i;

	i = 0;
	init_s_str(map);
	init_s_key(map);
	i = i + init_s_draw(&(map->draw));
	i = i + init_s_win(&(map->win));
	if (map->numsprite > 0)
		i = i + init_s_slist(map);
	i = i + init_s_text(&(map->text_no));
	i = i + init_s_text(&(map->text_so));
	i = i + init_s_text(&(map->text_ea));
	i = i + init_s_text(&(map->text_we));
	i = i + init_s_text(&(map->text_s));
	if (i > 0)
		return (-1);
	return (0);
}

void	set_texture(t_map *m)
{
	m->text_no->img = mlx_xpm_file_to_image(m->win->mlx, m->no, &m->text_no->x,
		&m->text_no->y);
	m->text_so->img = mlx_xpm_file_to_image(m->win->mlx, m->so, &m->text_so->x,
		&m->text_so->y);
	m->text_ea->img = mlx_xpm_file_to_image(m->win->mlx, m->ea, &m->text_ea->x,
		&m->text_ea->y);
	m->text_we->img = mlx_xpm_file_to_image(m->win->mlx, m->we, &m->text_we->x,
		&m->text_we->y);
	m->text_s->img = mlx_xpm_file_to_image(m->win->mlx, m->s, &m->text_s->x,
		&m->text_s->y);
	m->text_no->data = mlx_get_data_addr(m->text_no->img,
		&m->text_no->bpp, &m->text_no->sizel, &m->text_no->endian);
	m->text_so->data = mlx_get_data_addr(m->text_so->img,
		&m->text_so->bpp, &m->text_so->sizel, &m->text_so->endian);
	m->text_ea->data = mlx_get_data_addr(m->text_ea->img,
		&m->text_ea->bpp, &m->text_ea->sizel, &m->text_ea->endian);
	m->text_we->data = mlx_get_data_addr(m->text_we->img,
		&m->text_we->bpp, &m->text_we->sizel, &m->text_we->endian);
	m->text_s->data = mlx_get_data_addr(m->text_s->img,
		&m->text_s->bpp, &m->text_s->sizel, &m->text_s->endian);
}

int		init_s_map(t_map **map)
{
	(*map)->rx = 0;
	(*map)->ry = 0;
	(*map)->no = NULL;
	(*map)->so = NULL;
	(*map)->we = NULL;
	(*map)->ea = NULL;
	(*map)->s = NULL;
	(*map)->f = -1;
	(*map)->c = -1;
	(*map)->map = NULL;
	(*map)->depx = -1;
	(*map)->depy = -1;
	(*map)->lmap = 0;
	(*map)->dirx = 0;
	(*map)->diry = 0;
	(*map)->plax = 0;
	(*map)->play = 0;
	if (!((*map)->error = ft_strdup("Error\n")))
		return (-1);
	(*map)->numsprite = 0;
	(*map)->sc = 0;
	(*map)->slist = NULL;
	init_parskey(*map);
	(*map)->numl = 0;
	return (0);
}

void	init_ori(t_map *map, char c)
{
	if (c == 'N')
	{
		map->dirx = -1;
		map->play = 0.80;
	}
	if (c == 'S')
	{
		map->dirx = 1;
		map->play = -0.80;
	}
	if (c == 'E')
	{
		map->diry = 1;
		map->plax = 0.80;
	}
	if (c == 'W')
	{
		map->diry = -1;
		map->plax = -0.80;
	}
}
