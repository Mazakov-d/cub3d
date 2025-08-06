/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_2d_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:48:23 by mniemaz           #+#    #+#             */
/*   Updated: 2025/08/06 16:34:01 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	print_rect(t_context *ctx, int x, int y, int square_x, int square_y,
		char c)
{
	int	i;
	int	j;

	i = 0;
	while (i < square_x)
	{
		j = 0;
		while (j < square_y)
		{
			if (c == '1')
				put_pixel(ctx, x + i, y + j, 0x444444);
			else if (c == '0')
				put_pixel(ctx, x + i, y + j, 0x888888);
			j++;
		}
		i++;
	}
}

void	draw_rays(t_context *ctx, int square_x, int square_y)
{
	int			nb_rays;
	double		step;
	t_vector	ray;
	double		curr_angle;
	t_point_dir	ray_wall;

	nb_rays = 3;
	step = (ctx->player.right_fov_angle - ctx->player.left_fov_angle) / (nb_rays - 1);
	curr_angle = ctx->player.right_fov_angle;
	while (--nb_rays > -1)
	{
		init_vector(&ray, cos(curr_angle), sin(curr_angle));
		ray_wall = get_pos_wall_toward(ctx, ray);
		bresenham_line(ctx, ctx->player.pos, ray_wall.pos, square_x, square_y, 0xFFFFFF);
		curr_angle -= step;
	}
}

void draw_map_squares(t_context *ctx, int square_x, int square_y)
{
	int row;
	int col;

	row = -1;
	while (ctx->map[++row])
	{
		col = -1;
		while (ctx->map[row][++col])
			print_rect(ctx, square_x * col, square_y * row, square_x, square_y,
				ctx->map[row][col]);
	}
}

void calc_square_size(t_context *ctx, int *square_x, int *square_y)
{
	int	largest_line;
	int	i;

	i = 0;
	largest_line = 0;
	while (ctx->map[++i])
		if (ft_strlen(ctx->map[i]) > largest_line)
			largest_line = ft_strlen(ctx->map[i]);
	*square_x = MINI_MAP_X / largest_line;
	*square_y = MINI_MAP_Y / i;
}


void	display_2d_map(t_context *ctx)
{
	int	square_x;
	int	square_y;

	calc_square_size(ctx, &square_x, &square_y);
	draw_map_squares(ctx, square_x, square_y);
	
	draw_rays(ctx, square_x, square_y);
}
