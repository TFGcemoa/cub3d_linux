/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 15:14:04 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/07 20:40:04 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct			s_draw
{
	int					drws;
	int					drwe;
	void				*img;
	char				*data;
	int					bpp;
	int					sizel;
	int					endian;
	char				*buff;
	int					linh;
}						t_draw;

typedef struct			s_win
{
	void				*win;
	void				*mlx;
}						t_win;

typedef struct			s_key
{
	int					keyz;
	int					keys;
	int					keyq;
	int					keyd;
	int					keyfd;
	int					keyfg;
}						t_key;

typedef struct			s_text
{
	void				*img;
	char				*data;
	int					bpp;
	int					sizel;
	int					endian;
	int					x;
	int					y;
}						t_text;

typedef struct			s_sprite
{
	double				x;
	double				y;
	double				dist;
}						t_sprite;

typedef struct			s_vec
{
	double				posx;
	double				posy;
	double				rayx;
	double				rayy;
	int					mapx;
	int					mapy;
	double				sdix;
	double				sdiy;
	double				delx;
	double				dely;
	double				dist;
	int					stpx;
	int					stpy;
	int					hit;
	int					side;
	int					texx;
	int					texy;
	double				step;
	double				wallx;
	double				texpos;
}						t_vec;

typedef struct			s_paramsprite
{
	double				sptx;
	double				spty;
	double				transx;
	double				transy;
	int					spritescreenx;
	int					spriteheight;
	int					move;
	int					drawstarty;
	int					drawendy;
	int					spritewidth;
	int					drawstartx;
	int					drawendx;
	int					stripe;
	int					texsx;
}						t_paramspt;

typedef struct			s_pars
{
	int					r;
	int					no;
	int					so;
	int					ea;
	int					we;
	int					s;
	int					f;
	int					c;
}						t_pars;

typedef struct			s_map
{
	int					rx;
	int					ry;
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	char				*s;
	int					f;
	int					c;
	char				**map;
	int					nbrline;
	double				depx;
	double				depy;
	int					lmap;
	double				dirx;
	double				diry;
	double				plax;
	double				play;
	char				*error;
	t_vec				str;
	t_key				key;
	t_text				*text_no;
	t_text				*text_so;
	t_text				*text_ea;
	t_text				*text_we;
	t_text				*text_s;
	t_draw				*draw;
	t_win				*win;
	t_pars				parskey;
	int					sc;
	int					numsprite;
	t_sprite			*slist;
	int					numl;
}						t_map;

typedef struct			s_bmpimhead
{
	int					size_imhead;
	int					width;
	int					height;
	short				nbplans;
	short				bpp;
	int					compression;
	int					sizeim;
	int					hres;
	int					vres;
	int					cpalette;
	int					cipalette;
}						t_bmpimhead;

typedef struct			s_bmphead
{
	char				signature[2];
	int					taille;
	int					rsv;
	int					offsetim;
	t_bmpimhead			imhead;
}						t_bmphead;

#endif
