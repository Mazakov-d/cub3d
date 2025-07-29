/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:12:09 by mniemaz           #+#    #+#             */
/*   Updated: 2025/07/29 17:35:48 by dmazari          ###   ########.fr       */
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
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include "ray_casting.h"


# define WIN_SIZE_X 1920
# define WIN_SIZE_Y 1080
# define BUFFER_SIZE 1024


typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
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
	t_color			floor;
	t_color			ceiling;
}					t_graphic_data;

typedef struct s_context
{
	char			**map;
	t_graphic_data	graphic_data;
	t_mlx			mlx;
}					t_context;

/*
parsing
*/
void				parse_file(char *filename);

/*
utils
*/
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

/*
graphic 
init.c
*/
void				init_graphic(t_context *context);

/*
ray_init.c
*/
void	init_ray(t_context *ctx);


/*
free_graphic.c
*/
int				free_graphic(t_context *context);

#endif