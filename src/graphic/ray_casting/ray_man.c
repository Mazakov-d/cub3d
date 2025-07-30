/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_man.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:39:07 by mniemaz           #+#    #+#             */
/*   Updated: 2025/07/30 17:32:15 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @brief Draw a line between two cells of the map
 */
void	ray_man(t_context *ctx, t_vector dir, double square_x, double square_y)
{
	t_vector	step;
	double		x;
	double		y;
	double		x_map;
	double		y_map;
	double m;

	m = dir.y_i / dir.x_i;

	x = ctx->player.pos_x;
	y = ctx->player.pos_y;
	x_map = x / square_x;
	y_map = y / square_y;
	printf("x,y %f,%f\n", x, y);
	init_vector(&step, 1, (dir.y_i * m));
	int limit = 0;
	while (limit < 1500)
	{
		mlx_pixel_put(ctx->mlx.mlx, ctx->mlx.win, x, y, 0xffffff);
		x += step.x_i;
		y += step.y_i;
		x_map += step.x_i;
		y_map += step.y_i;
		limit++;
	}
}
