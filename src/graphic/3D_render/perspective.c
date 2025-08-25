/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:34:30 by dmazari           #+#    #+#             */
/*   Updated: 2025/08/25 13:47:29 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double	get_player_forward_angle(t_context *ctx)
{
	double	angle;

	angle = 0;
	if (ctx->player.p_vec.x_i > 0.0f)
	{
		if (ctx->player.p_vec.y_i > 0.0f)
			angle = atan(ctx->player.p_vec.y_i / ctx->player.p_vec.x_i);
		else if (ctx->player.p_vec.y_i < 0.0f)
			angle = atan(ctx->player.p_vec.y_i / ctx->player.p_vec.x_i) + 2
				* PI;
	}
	else if (ctx->player.p_vec.x_i > 0.0f && ctx->player.p_vec.y_i < 0.0f)
		angle = atan(ctx->player.p_vec.y_i / ctx->player.p_vec.x_i) + 2 * PI;
	else if (ctx->player.p_vec.x_i < 0.0f)
		angle = atan(ctx->player.p_vec.y_i / ctx->player.p_vec.x_i) + PI;
	else if (ctx->player.p_vec.x_i == 0.0f)
	{
		if (ctx->player.p_vec.y_i < 0.0f)
			angle = -PI_DIV_2;
		else
			angle = PI_DIV_2;
	}
	return (angle);
}

/**
 * Sets toward, left and right angles
 */
void	set_player_angles(t_context *ctx)
{
	double	forward_angle;

	forward_angle = get_player_forward_angle(ctx);
	ctx->player.forward_angle = forward_angle;
	ctx->player.right_fov_angle = forward_angle + FOV_RAD_DIV_2;
	ctx->player.left_fov_angle = forward_angle - FOV_RAD_DIV_2;
}

int	calculate_dimensions(t_context *ctx, t_impact impact, double curr_angle,
		int *heights)
{
	double	impact_distance;
	int		limit;

	impact_distance = get_distance(ctx->player.pos, impact.pos) * cos(curr_angle
			- ctx->player.forward_angle);
	if (impact_distance == 0.0f)
	{
		heights[SKY] = 0;
		heights[WALL] = INT_MAX;
		limit = WIN_SIZE_Y;
	}
	else
	{
		heights[WALL] = WIN_SIZE_X / impact_distance;
		heights[SKY] = (WIN_SIZE_Y - heights[WALL]) >> 1;
		limit = heights[SKY] + heights[WALL];
		if (WIN_SIZE_Y < limit)
			limit = WIN_SIZE_Y;
	}
	return (limit);
}

void	draw_vertical_ray(t_context *ctx, t_impact impact, int x,
		double curr_angle)
{
	int		heights[2];
	int		y;
	int		limit;

	y = 0;
	limit = calculate_dimensions(ctx, impact, curr_angle,
			heights);
	while (y < heights[SKY])
	{
		put_pixel(ctx, x, y, ctx->texture_data.ceiling_hexa);
		y++;
	}
	while (y < limit)
	{
		put_pixel(ctx, x, y,
			get_pixel_color_img(ctx->texture_data.walls[impact.wall_type], y
				- heights[SKY], heights[WALL], impact));
		y++;
	}
	while (y < WIN_SIZE_Y)
	{
		put_pixel(ctx, x, y, ctx->texture_data.floor_hexa);
		y++;
	}
}
