/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:34:30 by dmazari           #+#    #+#             */
/*   Updated: 2025/08/06 17:25:35 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_vertical_ray(t_point_dir impact, t_context *ctx, int x)
{
	int		wall_height;
	int		y;
	double	impact_distance;
	int		sky_height;
	int		limit;

	y = 0;
	impact_distance = get_distance(ctx->player.pos, impact.pos);
	if (impact_distance == 0.0f)
		wall_height = INT_MAX;
	else
		wall_height = WIN_SIZE_X / impact_distance;
	sky_height = (WIN_SIZE_Y - wall_height) >> 1;
	while (y < sky_height)
	{
		put_pixel(ctx, x, y, ctx->texture_data.ceiling->hexa);
		y++;
	}
	limit = sky_height + wall_height;
	if (limit > WIN_SIZE_Y)
		limit = WIN_SIZE_Y;
	while (y < limit)
	{
		put_pixel(ctx, x, y,
			get_pixel_color_img(ctx->texture_data.walls[impact.dir], y
				- sky_height, wall_height, impact));
		y++;
	}
	while (y < WIN_SIZE_Y)
	{
		put_pixel(ctx, x, y, ctx->texture_data.floor->hexa);
		y++;
	}
}

/**
 * Sets the left and right angles of the player's FOV based on the
 * player's vector direction
 */
void	set_left_right_angles(t_context *ctx)
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
			angle = PI * 0.5;
		angle = -PI * 0.5;
	}
	ctx->player.right_fov_angle = angle + FOV_RAD * 0.5;
	ctx->player.left_fov_angle = angle - FOV_RAD * 0.5;
}

void	vertical_render(t_context *ctx)
{
	int			nb_rays;
	double		step;
	t_vector	ray;
	double		curr_angle;
	t_point_dir	impact;

	nb_rays = WIN_SIZE_X;
	step = (ctx->player.right_fov_angle - ctx->player.left_fov_angle) / (nb_rays - 1);
	curr_angle = ctx->player.right_fov_angle;
	while (--nb_rays > -1)
	{
		curr_angle -= step;
		init_vector(&ray, cos(curr_angle), sin(curr_angle));
		impact = get_pos_wall_toward(ctx, ray);
		draw_vertical_ray(impact, ctx, nb_rays);
	}
}
