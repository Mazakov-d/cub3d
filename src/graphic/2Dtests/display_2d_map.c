/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_2d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:48:23 by mniemaz           #+#    #+#             */
/*   Updated: 2025/07/30 14:48:54 by mniemaz          ###   ########.fr       */
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
				mlx_pixel_put(ctx->mlx.mlx, ctx->mlx.win, x + i, y + j, 0x440000);
			if (c == '0')
				mlx_pixel_put(ctx->mlx.mlx, ctx->mlx.win, x + i, y + j, 0x004400);
			if (c == 'X')
				mlx_pixel_put(ctx->mlx.mlx, ctx->mlx.win, x + i, y + j, 0x000044);
            j++;
		}
		i++;
	}
}

void	print_square(t_context *ctx, t_int_pos pos, int size, int color)
{
	int	i;
	int	j;
	
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			mlx_pixel_put(ctx->mlx.mlx, ctx->mlx.win, pos.x + i, pos.y + j, color);
			j++;
		}
		i++;
	}
}

void	display_2d_map(t_context *ctx)
{
	int	largest_line;
	int	nb_rows;
	int	i;
	int	square_x;
	int	square_y;
    char **map = ctx->map;

	// int square_size;
	i = 0;
	largest_line = 0;
	while (ctx->map[i])
	{
		if (ft_strlen(ctx->map[i]) > largest_line)
			largest_line = ft_strlen(ctx->map[i]);
		i++;
	}
	nb_rows = i;
	square_x = WIN_SIZE_X / largest_line;
	square_y = WIN_SIZE_Y / nb_rows;
    int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			print_rect(ctx, square_x * col, square_y * row, square_x, square_y, map[row][col]);
            col++;
		}
		row++;
	}
    // ctx->player.pos.x *= square_x;
    // ctx->player.pos.y *= square_y;

	// t_vector dir;

	// init_vector(&dir, 1, 1);

    // ray_man(ctx, dir, square_x, square_y);

	t_pos facing_wall;
	facing_wall = get_pos_wall_toward(ctx, ctx->player.p_vec);
	bresenham_line(ctx, ctx->player.pos, facing_wall, square_x, square_y);

	t_pos right_ray_wall;
	t_vector right_ray;

	init_vector(&right_ray, tan(FOV_RAD/2), -ctx->player.p_vec.length);
	right_ray_wall = get_pos_wall_toward(ctx, right_ray);
	bresenham_line(ctx, ctx->player.pos, right_ray_wall, square_x, square_y);

	t_pos left_ray_wall;
	t_vector left_ray;

	init_vector(&left_ray, -tan(FOV_RAD/2), -ctx->player.p_vec.length);
	left_ray_wall = get_pos_wall_toward(ctx, left_ray);
	bresenham_line(ctx, ctx->player.pos, left_ray_wall, square_x, square_y);


}
