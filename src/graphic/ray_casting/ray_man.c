/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_man.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:39:07 by mniemaz           #+#    #+#             */
/*   Updated: 2025/07/30 16:52:49 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @brief Draw a line between two cells of the map
 */
void	ray_man(t_context *ctx, t_vector dir, double square_x, double square_y)
{
	t_vector	v;
	double		x;
	double		y;
	double		x_map;
	double		y_map;

	x = ctx->player.pos_x;
	y = ctx->player.pos_y;
	x_map = x / square_x;
	y_map = y / square_y;
	printf("x,y %f,%f\n", x, y);
	if (dir.x_i == 0)
		init_vector(&v, dir.x_i * 0.1, (dir.y_i * 0.1));
	else
		init_vector(&v, 0.1 * dir.x_i,(dir.y_i * 0.1));
	while (ctx->map[(int)floor(y_map -1)][(int)floor(x_map -1)] != '1')
	{
		mlx_pixel_put(ctx->mlx.mlx, ctx->mlx.win, x, y, 0xffffff);
		x += v.x_i;
		y += v.y_i;
		x_map += v.x_i;
		y_map += v.y_i;
	}
}
