/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:34:30 by dmazari           #+#    #+#             */
/*   Updated: 2025/08/08 16:57:30 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_vertical_ray(t_context *ctx, t_point_dir impact, int x,
		double curr_angle)
{
	int		wall_height;
	int		y;
	double	distorded_impact_distance;
	double	impact_distance;
	int		sky_height;
	int		limit;

	(void)curr_angle;
	y = 0;
	distorded_impact_distance = get_distance(ctx->player.pos, impact.pos);
	impact_distance = distorded_impact_distance;
	// printf("before: %f\n", distorded_impact_distance);
	// if (curr_angle > PI_DIV_2 && curr_angle < 3 * PI_DIV_2)
	// 	distorded_impact_distance *= -1;
	

	// // EA
	// if ((curr_angle <= PI * 0.25 || curr_angle >= PI * 1.75))
	// {
	// 	impact_distance = cos(curr_angle) * (double)distorded_impact_distance;
	// }

	// // WE
	// if ((curr_angle >= PI * 0.75 && curr_angle <= PI * 1.25))
	// {
	// 	distorded_impact_distance *= -1;
	// 	impact_distance = cos(curr_angle) * (double)distorded_impact_distance;
	// }
	
	// // SO
	// if ((curr_angle > PI * 0.25 && curr_angle < PI * 0.75))
	// {
	// 	impact_distance = sin(curr_angle) * (double)distorded_impact_distance;
	// }

	// // NO
	// if ((curr_angle > PI * 1.25 && curr_angle < PI * 1.75))
	// {
	// 	distorded_impact_distance *= -1;
	// 	impact_distance = sin(curr_angle) * (double)distorded_impact_distance;
	// }



	// printf("real dist: %f, distorded: %f angle: %f\n", impact_distance,
		// distorded_impact_distance, curr_angle);
	if (impact_distance == 0.0f)
	{
		sky_height = 0;
		wall_height = INT_MAX;
		limit = WIN_SIZE_Y;
	}
	else
	{
		wall_height = WIN_SIZE_X / impact_distance;
		if (wall_height > WIN_SIZE_Y)
		{
			sky_height = 0;
			limit = WIN_SIZE_Y;
		}
		else
		{
			sky_height = (WIN_SIZE_Y - wall_height) >> 1;
			limit = sky_height + wall_height;
		}
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

/**
 * Sets the left and right angles of the player's FOV based on the
 * player's vector direction
 */
void	set_left_right_angles(t_context *ctx)
{
	double angle;

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
	ctx->player.right_fov_angle = angle + FOV_RAD_DIV_2;
	ctx->player.left_fov_angle = angle - FOV_RAD_DIV_2;
}