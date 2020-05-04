/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 20:16:28 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/04 10:08:03 by nhochstr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <assert.h>
# include "struct.h"
# include "../mlx/mlx.h"

# define UDIV 1
# define VDIV 1
# define VMOVE 0.0
# define BUFFER_SIZE 64

typedef unsigned char	t_uc;

int				isscreenshot(t_map *map, char *argv, char *save);
int				get_next_line(int fd, char **line);
unsigned long	ft_n(char *str, int line);
char			*ft_join(char *s1, char *s2);
void			ft_bzero(void *s, size_t n);
int				ft_get_line(char *buff, char **line, int reset);
int				ft_resetbuleffer(char **buff, int endline, int fd, char **line);
char			*ft_del_return_line(char *str);
char			*ft_strdup(char *s);
int				ft_returnfreebuff(int endline, char **buff);
void			fr_freeptr(char **ptr);
void			move_cam_left(t_map *map, double rotspeed);
void			move_cam_right(t_map *map, double rotspeed);
int				moveplayer(t_map *map);
int				exit_hook(t_map *map);
int				key_press_hook(int key, t_map *map);
int				key_release_hook(int key, t_map *map);
void			move_front(t_map *map, double ms);
void			move_back(t_map *map, double ms);
void			move_right(t_map *map, double ms);
void			move_left(t_map *map, double ms);
int				ismap(char c, t_map *map, int i, int numl);
int				verifspacemap(char *line, int i, t_map *map, int numl);
int				verifothermap(char *line, int i, t_map *map, int numl);
int				verifcharmap(char *line, int i, t_map *map, int numl);
int				verifmap(char *line, t_map *map, int numl);
int				getrgb(char *line, int i);
int				rgb_to_int(int r, int g, int b);
int				rgbhex_to_int(char *hex);
char			*colorrgb_to_hexa(int nbr);
int				writeerror(t_map *map);
int				verif_ext(char *argv);
int				verifsizemap(t_map *map);
int				free_path(t_map *map);
int				free_map(t_map *map);
int				line_r(char *line, int i, t_map *map);
int				line_f(char *line, int i, t_map *map);
int				line_c(char *line, int i, t_map *map);
int				line_no(char *line, int i, t_map *map);
int				line_so(char *line, int i, t_map *map);
int				line_we(char *line, int i, t_map *map);
int				line_ea(char *line, int i, t_map *map);
int				line_s(char *line, int i, t_map *map);
int				gotomap(int fd, t_map *map);
int				getlinemap(int fd, t_map *map);
int				opencubmap(t_map *map, int ok, int fd);
int				opencub(char *argv, t_map *map);
int				parsing(char *argv, t_map *map);
int				verif_id_line(char *line, int i, t_map *map);
int				verifline(char *line, t_map *map);
int				firstlinemap(char *line, t_map *map);
int				countline(char *argv);
int				getmapempty(char *line);
int				tryopentext(char *path);
int				ft_verif_rgb(int r, int g, int b);
void			freergb(char **r, char **g, char **b);
void			setwalldraw(t_map *map);
void			setratiopixel(t_map *map);
void			setbg(t_map *map);
void			drawwall(t_map *map, int x);
void			setdist(t_map *map);
void			checkhit(t_map *map);
void			setraymapdel(t_map *map, int x);
void			setstpsdi(t_map *map);
int				raycasting(t_map *map);
void			wirteheader(int fd, t_bmphead *head);
int				setheader(t_bmphead *h, t_map *map);
int				setpix(int fd, int pitch, t_map *map);
int				screenshot(t_map *map);
void			sortsprites(t_map *m ,int i, int j);
void			classsprite(t_map *m);
void			castsprite(t_map *map, double *zbuffer);
int				set_sprites(t_map *map);
int				preparesprite(t_map *map, double *zbuffer);
void			drawspritecolor(t_map *map, t_paramspt *spt, int d);
void			calculsprite(t_map *map, t_paramspt *spt);
void			drawsprite(t_map *map, t_paramspt *s, double *zbuffer);
int				init_struc(t_map *map);
void			set_texture(t_map *map);
int				init_s_map(t_map **map);
void			init_ori(t_map *map, char c);
void			ft_sort_int_tab(double *tab, int size);
int				free_map_end(t_map *map);
void			ft_putstr_fd(char *s, int fd);
int				ft_atoi(const char *str);
void			*ft_memset(void *b, int c, size_t len);
size_t			ft_strlen(char const *s);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strjoins1(char const *s1, char const *s2);
int				ft_isspace(int c);
int				ft_isdigit(int c);
void			setcorrpitch(char *corrpitch);
void			ft_bzero_sc(void *s, size_t n);
void			*ft_calloc_sc(size_t count, size_t size);
void			set_res(t_map *map);
int				free_null(char **str);
void			freeend(t_map *map);
int				initdraw(t_draw **draw);
int				free_all(t_map *map);
void			free_all2(t_map *map);
void			init_s_str(t_map *map);
void			init_s_key(t_map *map);
int				init_s_draw(t_draw **draw);
int				init_s_win(t_win **win);
int				init_s_slist(t_map *map);
int				free_opencub(t_map *map);
int				verifendmap(t_map *map);
int				init_img(t_map *map);

#endif
