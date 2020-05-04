/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 16:42:33 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/03 21:49:32 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/struct.h"

size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (*s != '\0')
	{
		i++;
		s = s + 1;
	}
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (!(ptr = malloc(count * size)))
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

char	*ft_strjoins1(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		leng;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	leng = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	if (!(ptr = malloc((leng + 1) * sizeof(char))))
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = '\0';
	free((char *)s1);
	return (ptr);
}

int		ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' ||
		c == '\r')
		return (1);
	return (0);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
