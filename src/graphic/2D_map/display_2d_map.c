/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_2d_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:48:23 by mniemaz           #+#    #+#             */
/*   Updated: 2025/08/12 16:20:00 by mazakov          ###   ########.fr       */
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
			else if (c == 'C')
				put_pixel(ctx, x + i, y + j, 0x666666);
			else if (c == 'O')
				put_pixel(ctx, x + i, y + j, 0x777777);
			j++;
		}
		i++;
	}
}
/**
 * @param this function is used twice, once to draw the rays and once to
 * draw the 3D (vertical lines).
 */
void	handle_rays(t_context *ctx, void (*func)(t_context *, t_point_dir, int),
		int nb_rays)
{
	double		step;
	t_vector	ray;
	double		curr_angle;
	t_point_dir	impact;

	step = (ctx->player.right_fov_angle - ctx->player.left_fov_angle) / (nb_rays
			- 1);
	curr_angle = ctx->player.right_fov_angle;
	while (--nb_rays > -1)
	{
		init_vector(&ray, cos(curr_angle), sin(curr_angle));
		impact = get_impact_wall_toward(ctx, ray);
		func(ctx, impact, nb_rays);
		curr_angle -= step;
	}
}

void	draw_2d_map(t_context *ctx)
{
	int	row;
	int	col;

	row = -1;
	while (ctx->map[++row])
	{
		col = -1;
		while (ctx->map[row][++col])
			print_rect(ctx, ctx->w_square_2d * col + 10, ctx->h_square_2d * row + 10,
				ctx->w_square_2d, ctx->h_square_2d, ctx->map[row][col]);
	}
}

void	set_squares_2d_sizes(t_context *ctx)
{
	int	largest_line;
	int	i;

	i = 0;
	largest_line = 0;
	while (ctx->map[++i])
		if (ft_strlen(ctx->map[i]) > largest_line)
			largest_line = ft_strlen(ctx->map[i]);
	if (largest_line == 0)
		largest_line = 1;
	if (i == 0)
		i = 1;
	ctx->w_square_2d = MINI_MAP_X / largest_line;
	ctx->h_square_2d = MINI_MAP_Y / i;
}

void	display_2d_map(t_context *ctx)
{
	set_squares_2d_sizes(ctx);
	draw_2d_map(ctx);
	handle_rays(ctx, bresenham_line, 3);
}
