/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_2d_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:48:23 by mniemaz           #+#    #+#             */
/*   Updated: 2025/08/04 18:17:00 by dmazari          ###   ########.fr       */
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
				put_pixel(ctx, x + i, y + j, 0x440000);
			else if (c == '0')
				put_pixel(ctx, x + i, y + j, 0x004400);
			else if (c == 'X')
				put_pixel(ctx, x + i, y + j, 0x000044);
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
			put_pixel(ctx, pos.x + i, pos.y + j, color);
			j++;
		}
		i++;
	}
}

/*
** @returns the angle of forward vec and x absis
** still need to remove or add FOV / 2
*/
double	get_fov_angle(t_context *ctx)
{
	double	angle;

	angle = 0;
	if (ctx->player.p_vec.x_i > 0.0f)
		angle = atan(ctx->player.p_vec.y_i / ctx->player.p_vec.x_i);
	else if (ctx->player.p_vec.x_i < 0.0f)
		angle = atan(ctx->player.p_vec.y_i / ctx->player.p_vec.x_i) + PI;
	else if (ctx->player.p_vec.x_i == 0.0f)
	{
		if (ctx->player.p_vec.y_i > 0.0f)
			angle = PI / 2;
		else
			angle = -PI / 2;
	}
	return (angle);
}

void	draw_rays(t_context *ctx, int square_x, int square_y)
{
	t_pos		facing_wall;
	t_pos		right_ray_wall;
	t_pos		left_ray_wall;
	t_vector	right_ray;
	t_vector	left_ray;
	double		angle;
	double		right_fov;
	double		left_fov;
	int			i;
	int			nb_rays;
	double		diff_angles;
	t_vector	ray;

	angle = get_fov_angle(ctx);
	right_fov = angle + FOV_RAD * 0.5;
	left_fov = angle - FOV_RAD * 0.5;

	/* Draw center ray */
	facing_wall = get_pos_wall_toward(ctx, ctx->player.p_vec);
	bresenham_line(ctx, ctx->player.pos, facing_wall, square_x, square_y, 0xFFFFFF);
	
	/* Draw right FOV boundary */
	init_vector(&right_ray, cos(right_fov), sin(right_fov));
	right_ray_wall = get_pos_wall_toward(ctx, right_ray);
	bresenham_line(ctx, ctx->player.pos, right_ray_wall, square_x, square_y, 0xFFFF00);

	/* Draw left FOV boundary - FIXED: was using left_fov instead of sin(left_fov) */
	init_vector(&left_ray, cos(left_fov), sin(left_fov));
	left_ray_wall = get_pos_wall_toward(ctx, left_ray);
	bresenham_line(ctx, ctx->player.pos, left_ray_wall, square_x, square_y, 0x00FFFF);

	/* Draw intermediate rays */
	i = 1;
	nb_rays = 4;
	diff_angles = right_fov - left_fov;
	while (i < nb_rays)
	{
		double add = i * (diff_angles / nb_rays);
		init_vector(&ray, cos(left_fov + add), sin(left_fov + add));
		t_pos ray_wall = get_pos_wall_toward(ctx, ray);
		bresenham_line(ctx, ctx->player.pos, ray_wall, square_x, square_y, 0x00FF00);
		i++;
	}
}

void	display_2d_map(t_context *ctx)
{
	int		largest_line;
	int		nb_rows;
	int		i;
	int		square_x;
	int		square_y;
	char	**map;
	int		row;
	int		col;

	// clear_image_fast(ctx);
	map = ctx->map;
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
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			print_rect(ctx, square_x * col, square_y * row, square_x, square_y,
				map[row][col]);
			col++;
		}
		row++;
	}
	draw_rays(ctx, square_x, square_y);
}
