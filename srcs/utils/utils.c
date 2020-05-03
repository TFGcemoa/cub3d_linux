/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 16:30:49 by nhochstr          #+#    #+#             */
/*   Updated: 2020/04/30 16:57:38 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/struct.h"

void	ft_sort_int_tab(double *tab, int size)
{
	double		tmp;
	int			i;
	int			j;

	i = 0;
	while (i < size)
	{
		j = size - 1;
		while (j > i)
		{
			if (tab[i] <= tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j--;
		}
		i++;
	}
}

int		free_map_end(t_map *map)
{
	int size;
	int i;

	size = map->nbrline - map->lmap + 1;
	i = 0;
	if (!map->map)
		return (-1);
	while (i < size)
	{
		if (map->map[i])
			free(map->map[i]);
		map->map[i++] = NULL;
	}
	if (map->map)
		free(map->map);
	map->map = NULL;
	return (-1);
}

void	ft_putstr_fd(char *s, int fd)
{
	long		i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
			write(fd, &s[i++], 1);
	}
}

int		ft_atoi(const char *str)
{
	int					k;
	unsigned long long	n;

	k = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' ||
			*str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-')
		k = -k;
	if (*str == '+' || *str == '-')
		str++;
	n = 0;
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - 48);
		str++;
	}
	if (n > 9223372036854775807 && k < 0)
		return (0);
	if (n > 9223372036854775807 && k > 0)
		return (-1);
	return (n * k);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len-- > 0)
		*(ptr++) = (unsigned char)c;
	return (b);
}
