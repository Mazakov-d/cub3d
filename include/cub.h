/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:12:09 by mniemaz           #+#    #+#             */
/*   Updated: 2025/08/26 11:05:23 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define SKY 0
# define WALL 1
# define WIN_SIZE_X 1920
# define WIN_SIZE_Y 1080
# define BUFFER_SIZE 1024
# define HEXA_INIT_VAL 16777216
# define MAP_CHARS "NSEW01OC "
# define USER_CHARS "NSEW"
# define EXIT_NEUTRAL 2
# define SPACE 32
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define ESC 65307
# define SPEED 0.08
# define TURN_SPEED 0.05
# define MOUSE_SPEED 0.0005
# define PI 3.14159265358979323846
# define FOV_DEG 60

typedef enum e_wall_type
{
	NO,
	SO,
	EA,
	WE,
	CLOSE,
	OPEN,
	NONE
}					t_wall_type;

typedef struct const_datas
{
	double			mini_map_x;
	double			mini_map_y;
	double			center_win_x;
	double			center_win_y;
	double			pi_div_2;
	double			pi_times_2;
	double			fov_rad;
	double			fov_rad_div_2;
}					t_const_datas;

typedef struct s_vector
{
	double			x_i;
	double			y_i;
}					t_vector;

typedef struct s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct s_impact
{
	t_point			pos;
	t_wall_type		wall_type;
}					t_impact;

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
	t_img			walls[5];
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
	double			forward_angle;
}					t_player;

typedef struct s_context
{
	char			**map;
	t_texture_data	texture_data;
	t_mlx			*mlx;
	t_player		player;
	int				w_square_2d;
	int				h_square_2d;
	t_const_datas	const_datas;
}					t_context;

/*
** parsing
*/
int					parse_file(t_context *ctx, char *filename);
int					check_flood_fill(t_context *ctx);
t_line				*skip_spaces(t_line *line);
bool				are_doors_surrounded_by_walls(char **map);
bool				is_texture_data_filled(t_texture_data *tex_data);
void				prep_to_fill_wall_types(t_texture_data **tex_data,
						char **wall_type, char ***to_fill);
int					fill_wall_types(t_texture_data *tex_data, char **lines_tab);

/**
 * get_wall_types
 */
t_wall_type			get_south_wall_type(t_point pos, char **map);
t_wall_type			get_north_wall_type(t_point pos, char **map);
t_wall_type			get_east_wall_type(t_point pos, char **map);
t_wall_type			get_west_wall_type(t_point pos, char **map);

/*
** 2D_map
*/
void				display_2d_map(t_context *ctx);
void				bresenham_line(t_context *ctx, t_impact to, int unused,
						double unused_2);

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
void				init_texture(t_context *ctx);
int					open_image(t_img *img, t_mlx *mlx);

/**
 * utils/ft_int_abs.c
 */
int					ft_int_abs(int n);
double				ft_double_abs(double n);

/**
 * graphic
 * init.c
 */
void				init_graphic(t_context *ctx);

/**
 * free_graphic.c
 */
int					free_graphic(t_context *ctx);

/**
 * movements
 */
void				go_forward(t_player *player, char **map);
void				go_backward(t_player *player, char **map);
void				go_left(t_player *player, char **map);
void				go_right(t_player *player, char **map);
void				turn_left(t_context *ctx);
void				turn_right(t_context *ctx);
int					key_hook_press(int keycode, t_context *ctx);
int					key_release(int keycode, t_context *ctx);
int					move_player(t_context *ctx);
void				mouse_move(t_context *ctx);
void				handle_door(t_context *ctx);

/**
 * vector/ft_vector.c
 */
void				init_vector(t_vector *v, double x, double y);
double				get_distance(t_point a, t_point b);

/**
 * ray_casting
 */
t_point				get_intersection_pos(t_point p, t_vector dir);
t_impact			get_impact_wall_toward(t_context *ctx, t_vector dir);

/**
 * maths
 */
bool				is_almost_rounded(double n);
double				ft_min(double a, double b);
bool				is_rounded(double x);

/**
 * graphic_function.c
 */
void				put_pixel(t_context *ctx, int x, int y, int color);
void				clear_image(t_context *ctx);
void				clear_image_fast(t_context *ctx);
int					get_pixel_color_img(t_img img, int y_wall, int length,
						t_impact impact);
void				handle_rays(t_context *ctx, void (*func)(t_context *,
							t_impact, int, double), int nb_rays);
void				render_window_pxls(t_context *ctx);

/**
 * perspective.c
 */
void				vertical_render(t_context *ctx);
void				set_player_angles(t_context *ctx);
void				draw_vertical_ray(t_context *ctx, t_impact impact, int x,
						double curr_angle);
bool				is_rounded(double x);
t_wall_type			stuck_on_wall_dir(char **map, t_point pos, t_vector vec);

#endif