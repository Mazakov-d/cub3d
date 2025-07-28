/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:12:09 by mniemaz           #+#    #+#             */
/*   Updated: 2025/07/28 20:43:27 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

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

# define WIN_SIZE_X 1500
# define WIN_SIZE_Y 1000
# define BUFFER_SIZE 1024
# define COLOR_INIT_VAL 256
# define VALIDE_MAP_CHARS "01NSEW "

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

typedef struct s_graphic_data
{
	char			*north;
	char			*south;
	char			*east;
	char			*west;
	t_color			*floor;
	t_color			*ceiling;
}					t_graphic_data;

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
	t_graphic_data	graphic_data;
	t_mlx			mlx;
}					t_context;

// parsing
void				parse_file(t_context *ctx, char *filename);

// utils
int					ft_strlen(char *str);
int					ft_dprintf(int fd, const char *fmt, ...);
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

#endif