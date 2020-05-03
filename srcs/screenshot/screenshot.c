/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 16:10:05 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/01 01:11:23 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/struct.h"

int		isscreenshot(t_map *map, char *argv, char *save)
{
	size_t	i;
	size_t	leng;

	i = 0;
	leng = ft_strlen(save);
	while (argv[i] && i < leng && argv[i] == save[i])
		i++;
	if (i == leng && argv[i] == '\0')
	{
		map->sc = 1;
		raycasting(map);
		return (1);
	}
	else
		map->sc = 0;
	return (0);
}

void	wirteheader(int fd, t_bmphead *head)
{
	write(fd, &head->signature[0], 1);
	write(fd, &head->signature[1], 1);
	write(fd, &head->taille, 4);
	write(fd, &head->rsv, 4);
	write(fd, &head->offsetim, 4);
	write(fd, &head->imhead.size_imhead, 4);
	write(fd, &head->imhead.width, 4);
	write(fd, &head->imhead.height, 4);
	write(fd, &head->imhead.nbplans, 2);
	write(fd, &head->imhead.bpp, 2);
	write(fd, &head->imhead.compression, 4);
	write(fd, &head->imhead.sizeim, 4);
	write(fd, &head->imhead.hres, 4);
	write(fd, &head->imhead.vres, 4);
	write(fd, &head->imhead.cpalette, 4);
	write(fd, &head->imhead.cipalette, 4);
}

int		setheader(t_bmphead *h, t_map *map)
{
	int		p;
	char	corrpitch[4];
	int		tailledata;

	setcorrpitch(corrpitch);
	p = 0;
	h->signature[0] = 'B';
	h->signature[1] = 'M';
	h->rsv = 0;
	h->offsetim = 54;
	h->imhead.size_imhead = 40;
	h->imhead.width = map->rx;
	h->imhead.height = map->ry;
	h->imhead.nbplans = 1;
	h->imhead.bpp = 24;
	h->imhead.compression = 0;
	p = corrpitch[(3 * h->imhead.width) % 4];
	tailledata = 3 * h->imhead.height * h->imhead.width + h->imhead.height * p;
	h->imhead.sizeim = tailledata;
	h->imhead.hres = 0;
	h->imhead.vres = 0;
	h->imhead.cpalette = 0;
	h->imhead.cipalette = 0;
	h->taille = h->offsetim + h->imhead.sizeim;
	return (p);
}

int		setpix(int fd, int pitch, t_map *map)
{
	int				i;
	int				j;
	int				color;
	int				(*rgb)[map->rx][1];
	int				k;

	j = map->ry - 1;
	rgb = (void *)map->draw->data;
	while (j >= 0)
	{
		i = -1;
		while (++i < map->rx)
		{
			color = *rgb[j][i];
			if (write(fd, &color, 3) != 3)
				return (-1);
		}
		k = 0;
		while (k++ < pitch)
			write(fd, 0, 1);
		j--;
	}
	return (0);
}

int		screenshot(t_map *map)
{
	t_bmphead	head;
	int			pitch;
	int			fd;
	int			k;

	k = 0;
	map->sc = 0;
	if (!(fd = open("screenshot.bmp", O_RDWR | O_CREAT, 0666)))
		return (-1);
	ft_memset(&head, 0, 54);
	pitch = setheader(&head, map);
	wirteheader(fd, &head);
	k = setpix(fd, pitch, map);
	close(fd);
	free_all(map);
	return (k);
}
