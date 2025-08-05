/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:34:30 by dmazari           #+#    #+#             */
/*   Updated: 2025/08/05 18:36:58 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	draw_vertical_ray(t_point_dir impact, t_context *ctx, int x)
{
	int		length;
	int		i;
	double	impact_distance;

	i = 0;
	impact_distance = get_distance(ctx->player.pos, impact.pos);
	if (impact_distance == 0.0f)
		length = WIN_SIZE_Y;
	else
		length = 1 / impact_distance * WIN_SIZE_Y;
	while (i < WIN_SIZE_Y)
	{
		if (i < (WIN_SIZE_Y - length) / 2)
			put_pixel(ctx, x, i, 0x87CEEB);
		else if (i > (WIN_SIZE_Y - length) / 2 + length)
			put_pixel(ctx, x, i, 0x8B4513);
		else
			put_pixel(ctx, x, i, 0x228B22);
		i++;
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

	set_left_right_angles(ctx);
	nb_rays = WIN_SIZE_X;
	step = (ctx->player.right_fov_angle - ctx->player.left_fov_angle) / (nb_rays
			- 1);
	curr_angle = ctx->player.right_fov_angle;
	while (--nb_rays > -1)
	{
		curr_angle -= step;
		init_vector(&ray, cos(curr_angle), sin(curr_angle));
		impact = get_pos_wall_toward(ctx, ray);
		draw_vertical_ray(impact, ctx, nb_rays);
	}
}
