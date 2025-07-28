/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:12:09 by mniemaz           #+#    #+#             */
/*   Updated: 2025/07/28 15:41:01 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "minilibx-linux/mlx.h"

# define WIN_SIZE_X 3000
# define WIN_SIZE_Y 2000

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

#endif