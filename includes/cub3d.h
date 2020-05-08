/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhochstr <nhochstr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 20:16:28 by nhochstr          #+#    #+#             */
/*   Updated: 2020/05/08 16:40:04 by nhochstr         ###   ########.fr       */
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

void			fr_freeptr(char **ptr);
void			ft_bzero(void *s, size_t n);
int				ft_resetbuffer(char **buff, int endline, int fd, char **line);
int				ft_returnfreebuff(int endline, char **buff);
int				get_next_line(int fd, char **line);
unsigned long	ft_len(char *str, int line);
char			*ft_del_return_line(char *str);
char			*ft_join(char *s1, char *s2);
char			*ft_strdup(char *s);
int				ft_get_line(char *buff, char **line, int reset);
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
char			*colorrgb_to_hexa(int nbr);
int				rgbhex_to_int(char *hex);
int				rgb_to_int(int r, int g, int b);
int				go_to_next_rgb(char *line, int i);
int				getrgb(char *line, int i);
int				put_error_screen(t_map *map);
int				verifendmap(t_map *map);
int				verifsizemap(t_map *map);
int				verif_map_final(t_map *map);
int				parsing_error(t_map *map);
int				parsing_keys2(char *line, int i, t_map *map);
int				parsing_keys(char *line, t_map *map, int keys);
int				parsing_map(char *line, t_map *map);
int				parsing_keys_map(char *argv, t_map *map);
int				parsing(char *argv, t_map *map);
int				verif_end_file(char *line, t_map *map);
int				check_file(char *argv, t_map *map);
int				map_realloc(t_map *map, char **buff);
int				ft_realloc(t_map *map);
int				join_wrong(t_map *map, char *str, int r);
int				line_r(char *line, int i, t_map *map);
int				line_f(char *line, int i, t_map *map);
int				line_c(char *line, int i, t_map *map);
int				line_no(char *line, int i, t_map *map);
int				line_so(char *line, int i, t_map *map);
int				line_we(char *line, int i, t_map *map);
int				line_ea(char *line, int i, t_map *map);
int				line_s(char *line, int i, t_map *map);
int				countline(char *argv);
int				getmapempty(char *line, t_map *map);
int				tryopentext(char *str);
int				ft_verif_rgb(int r, int g, int b);
void			freergb(char **r, char **g, char **b);
void			setwalldraw(t_map *map);
void			setratiopixel(t_map *map);
void			setbg(t_map *map);
char			*set_color(t_map *map, t_text *t);
void			drawwall(t_map *map, int x);
void			setdist(t_map *map);
void			checkhit(t_map *map);
void			setraymapdel(t_map *map, int x);
void			setstpsdi(t_map *map);
int				raycasting(t_map *map);
int				isscreenshot(t_map *map, char *argv, char *save);
void			wirteheader(int fd, t_bmphead *head);
int				setheader(t_bmphead *h, t_map *map);
int				setpix(int fd, int pitch, t_map *map);
int				screenshot(t_map *map);
void			sortsprites(t_map *m, int i, int j);
void			classsprite(t_map *m);
int				preparesprite(t_map *map, double *zbuffer);
void			drawspritecolor(t_map *map, t_paramspt *spt, int d);
void			calculsprite(t_map *map, t_paramspt *spt);
void			drawsprite(t_map *map, t_paramspt *s, double *zbuffer);
int				free_path(t_map *map);
int				free_map(t_map *map);
void			free_all2(t_map *map);
int				free_all(t_map *map);
int				free_opencub(t_map *map);
int				init_s_text(t_text **text);
int				init_struc(t_map *map);
void			set_texture(t_map *m);
int				init_s_map(t_map **map);
void			init_ori(t_map *map, char c);
void			init_s_str(t_map *map);
void			init_s_key(t_map *map);
int				init_s_draw(t_draw **draw);
int				init_s_win(t_win **win);
int				init_s_slist(t_map *map);
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
int				initdraw(t_draw **draw);
int				verif_img(t_map *m);
int				init_img(t_map *map);
void			init_parskey(t_map *map);
char			*ft_worddup(char *s);

#endif
