/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 16:44:18 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/03 16:26:40 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"
#include "../../includes/struct.h"

char	*colorrgb_to_hexa(int nbr)
{
	char	*color;
	int		k;
	int		res;

	k = 1;
	if (!(color = ft_calloc(sizeof(char), 3)))
		return (NULL);
	while (k >= 0 && nbr >= 16)
	{
		res = nbr % 16;
		nbr = nbr / 16;
		if (res <= 9)
			color[k--] = res + 48;
		else
			color[k--] = res + 55;
	}
	if (nbr <= 9 && nbr > 0 && nbr < 16 && k >= 0)
		color[k--] = nbr + 48;
	else if (nbr > 0 && nbr < 16 && k >= 0)
		color[k--] = nbr + 55;
	while (k >= 0)
		color[k--] = '0';
	return (color);
}

int		rgbhex_to_int(char *hex)
{
	int leng;
	int total;
	int i;

	leng = ft_strlen(hex) - 1;
	total = 0;
	i = 1;
	if (leng != 5)
		return (-1);
	while (leng >= 0)
	{
		if (hex[leng] >= '0' && hex[leng] <= '9')
			total = total + (hex[leng] - 48) * i;
		else if (hex[leng] >= 'A' && hex[leng] <= 'F')
			total = total + (hex[leng] - 55) * i;
		else
			return (-1);
		leng--;
		i = i * 16;
	}
	return (total);
}

int		rgb_to_int(int r, int g, int b)
{
	char	*hexr;
	char	*hexg;
	char	*hexb;
	char	*hex;
	int		dec;

	hexr = colorrgb_to_hexa(r);
	hexg = colorrgb_to_hexa(g);
	hexb = colorrgb_to_hexa(b);
	if (!hexr || !hexg || !hexb)
	{
		freergb(&hexr, &hexg, &hexb);
		return (-1);
	}
	hex = ft_strdup(hexr);
	hex = ft_strjoins1(hex, hexg);
	hex = ft_strjoins1(hex, hexb);
	freergb(&hexr, &hexg, &hexb);
	if (!hex)
		return (-1);
	dec = rgbhex_to_int(hex);
	free(hex);
	return (dec);
}

int		getrgb(char *line, int i)
{
	int r;
	int	g;
	int	b;

	r = -1;
	g = -1;
	b = -1;
	r = ft_atoi(line + i);
	while (ft_isdigit(line[i]) == 1 && line[i] != 0)
		i++;
	while (ft_isdigit(line[i]) == 0 && line[i] != 0)
		i++;
	if (ft_isdigit(line[i]) == 1)
		g = ft_atoi(line + i);
	while (ft_isdigit(line[i]) == 1 && line[i] != 0)
		i++;
	while (ft_isdigit(line[i]) == 0 && line[i] != 0)
		i++;
	if (ft_isdigit(line[i]) == 1)
		b = ft_atoi(line + i);
	if (ft_verif_rgb(r, g, b) == -1)
		return (-1);
	return (rgb_to_int(r, g, b));
}
