/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:12:09 by mniemaz           #+#    #+#             */
/*   Updated: 2025/07/30 14:40:47 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "ray_casting.h"
# include <errno.h>
# include <fcntl.h>
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
# define BUFFER_SIZE 1024
# define COLOR_INIT_VAL 256
# define MAP_CHARS "NSEW01 "
# define USER_CHARS "NSEW"
# define OUR_USER_CHAR 'P'
# define EXIT_NEUTRAL 2

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned long rgba; // c fabien qua dit
}					t_color;

typedef struct s_mlx
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	void			*mlx;
	void			*win;
}					t_mlx;

typedef struct s_texture_data
{
	char			*north;
	char			*south;
	char			*east;
	char			*west;
	t_color			*floor;
	t_color			*ceiling;
}					t_texture_data;

typedef struct s_line
{
	char			*line;
	struct s_line	*next;
}					t_line;

typedef struct s_parsing_data
{
	t_line			**file_content;
	int				fd;
}					t_parsing_data;

typedef struct s_context
{
	char			**map;
	t_texture_data	texture_data;
	t_mlx			mlx;
}					t_context;

/**
 * parsing
 */
int					parse_file(t_context *ctx, char *filename);
int					check_flood_fill(t_context *ctx);
t_line				*skip_spaces(t_line *line);

/**
 * utils
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
 * graphic
 * init.c
 */
void				init_graphic(t_context *context);

/**
 * ray_init.c
 */
void				init_ray(t_context *ctx);

/**
 * free_graphic.c
 */
int					free_graphic(t_context *context);

#endif