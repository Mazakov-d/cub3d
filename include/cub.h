/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:12:09 by mniemaz           #+#    #+#             */
/*   Updated: 2025/08/07 11:43:52 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "ray_casting.h"
# include <errno.h>
# include <fcntl.h>
# include <float.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIN_SIZE_X 1920
# define WIN_SIZE_Y 1080
# define MINI_MAP_X WIN_SIZE_X * 0.2
# define MINI_MAP_Y WIN_SIZE_Y * 0.2
# define BUFFER_SIZE 1024
# define HEXA_INIT_VAL 0xFFFFFF + 1
# define MAP_CHARS "NSEW01 "
# define USER_CHARS "NSEW"
# define EXIT_NEUTRAL 2
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define ESC 65307
# define SPEED 0.05
# define TURN_SPEED 0.05

typedef enum e_cardinal_dir
{
	NO,
	SO,
	EA,
	WE,
	NONE
}					t_cardinal_dir;

typedef struct s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct s_point_dir
{
	t_point			pos;
	t_cardinal_dir	dir;
}					t_point_dir;

typedef struct s_key_bool
{
	bool			w_bool;
	bool			a_bool;
	bool			s_bool;
	bool			d_bool;
	bool			left_arrow_bool;
	bool			right_arrow_bool;
}					t_key_bool;

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

typedef struct s_img
{
	char			*img_name;
	void			*img_ptr;
	char			*data;
	int				width;
	int				height;
	int				bpp;
	int				line_len;
	int				endian;
}					t_img;

typedef struct s_mlx
{
	t_key_bool		keys;
	t_img			img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*mlx_ptr;
	void			*win_ptr;
}					t_mlx;

typedef struct s_texture_data
{
	t_img			walls[4];
	unsigned long	floor_hexa;
	unsigned long	ceiling_hexa;
}					t_texture_data;

typedef struct s_line
{
	char			*line;
	struct s_line	*next;
}					t_line;

typedef struct s_int_pos
{
	int				x;
	int				y;
}					t_int_pos;

typedef struct s_player
{
	t_point			pos;
	t_vector		p_vec;
	double			left_fov_angle;
	double			right_fov_angle;
}					t_player;

typedef struct s_context
{
	char			**map;
	t_texture_data	texture_data;
	t_mlx			*mlx;
	t_player		player;
	int				w_square_2d;
	int				h_square_2d;
}					t_context;

/*
** parsing
*/
int					parse_file(t_context *ctx, char *filename);
int					check_flood_fill(t_context *ctx);
t_line				*skip_spaces(t_line *line);

/*
** 2Dtests
*/
void				display_2d_map(t_context *ctx);

/*
** utils/str
*/
int					ft_strlen(char *str);
int					printf_err(const char *fmt, ...);
int					is_char_in_str(char c, char *str);
char				*ft_strndup(const char *s, size_t n);
char				*ft_strdup(char *s1);
char				*ft_strjoin(char *s1, char *s2);
int					ft_strchr_idx(const char *s, int c);
void				*ft_memcpy(void *dest, const void *src, size_t n);
bool				ends_with(char *str, char *suffix);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*get_next_line(int fd);
char				**ft_split(char const *s, char *delim);
int					ft_atoi_color(const char *nptr, int *error);
char				*rm_nl(char *str);
int					ft_isspace(int c);
bool				ft_is_str_spaces(char *str);
void				ft_free_tab(void **tab);
void				free_context(t_context *ctx);
void				free_lines_lst(t_line **head_lst);
int					init_context(t_context *ctx);
void				*ft_calloc(size_t nmemb, size_t size);
int					fill_file_content(t_line ***head_file_line, int fd);
t_line				*fill_texture_data(t_line **head_file_line,
						t_texture_data *tex_data);
int					fill_map(t_context *ctx, t_line *end_texture_data_line);
size_t				ft_tablen(void **tab);
char				**ft_strsdup(char **src);
void				print_map_color(char **map, int row, int col);

/**
 * utils/ft_int_abs.c
 */
int					ft_int_abs(int n);
double				ft_double_abs(double n);

/**
 * graphic
 * init.c
 */
void				init_graphic(t_context *context);

/**
 * free_graphic.c
 */
int					free_graphic(t_context *context);

/**
 * movements
 */
void				go_forward(t_player *player, char **map);
void				go_backward(t_player *player, char **map);
void				go_left(t_player *player, char **map);
void				go_right(t_player *player, char **map);
void				turn_left(t_context *ctx);
void				turn_right(t_context *ctx);
int					key_hook_press(int keycode, t_context *context);
int					key_release(int keycode, t_context *context);
int					move_player(t_context *ctx);

/**
 * vector/ft_vector.c
 */
void				init_vector(t_vector *v, double x, double y);
double				get_distance(t_point a, t_point b);

/**
 * maths
 */
t_point				get_intersection_pos(t_point p, t_vector dir);
void				bresenham_line(t_context *ctx, t_point_dir to, int unused);
void				print_square(t_context *ctx, t_int_pos pos, int size,
						int color);
t_point_dir			get_impact_wall_toward(t_context *ctx, t_vector dir);
bool				is_almost_rounded(double n);

/**
 * graphic_function.c
 */
void				put_pixel(t_context *ctx, int x, int y, int color);
void				clear_image(t_context *ctx);
void				clear_image_fast(t_context *ctx);
int					get_pixel_color_img(t_img img, int y_wall, int length,
						t_point_dir impact);
void				handle_rays(t_context *ctx, void (*func)(t_context *,
							t_point_dir, int), int nb_rays);
void				render_window_pxls(t_context *ctx);

/**
 * perspective.c
 */
void				vertical_render(t_context *ctx);
void				set_left_right_angles(t_context *ctx);
void				draw_vertical_ray(t_context *ctx, t_point_dir impact,
						int x);

#endif