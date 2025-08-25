/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:34:30 by dmazari           #+#    #+#             */
/*   Updated: 2025/08/08 17:52:15 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double	get_player_angle(t_context *ctx)
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
 * Sets the left and right angles of the player's FOV based on the
 * player's vector direction
 */
void	set_player_angles(t_context *ctx)
{
	double	angle;

	angle = get_player_angle(ctx);
	ctx->player.forward_angle = angle;
	ctx->player.right_fov_angle = angle + FOV_RAD_DIV_2;
	ctx->player.left_fov_angle = angle - FOV_RAD_DIV_2;
}

void	draw_vertical_ray(t_context *ctx, t_point_dir impact, int x,
		double curr_angle)
{
	int		wall_height;
	int		y;
	double	impact_distance;
	int		sky_height;
	int		limit;

	y = 0;
	impact_distance = get_distance(ctx->player.pos, impact.pos) * cos(curr_angle
			- ctx->player.forward_angle);
	if (impact_distance == 0.0f)
	{
		sky_height = 0;
		wall_height = INT_MAX;
		limit = WIN_SIZE_Y;
	}
	else
	{
		wall_height = WIN_SIZE_X / impact_distance;
		sky_height = (WIN_SIZE_Y - wall_height) >> 1;
		limit = sky_height + wall_height;
		if (WIN_SIZE_Y < limit)
			limit = WIN_SIZE_Y;
	}
	while (y < sky_height)
	{
		put_pixel(ctx, x, y, ctx->texture_data.ceiling_hexa);
		y++;
	}
	while (y < limit)
	{
		put_pixel(ctx, x, y,
			get_pixel_color_img(ctx->texture_data.walls[impact.dir], y
				- sky_height, wall_height, impact));
		y++;
	}
	while (y < WIN_SIZE_Y)
	{
		put_pixel(ctx, x, y, ctx->texture_data.floor_hexa);
		y++;
	}
}
