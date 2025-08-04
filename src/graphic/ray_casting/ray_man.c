/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_man.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:39:07 by mniemaz           #+#    #+#             */
/*   Updated: 2025/08/04 10:01:50 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @brief Draw a line between two cells of the map
 */

// t_point	find_next_vertical_hit(t_context *ctx, int n, )


// void	ray_man(t_context *ctx, t_vector dir, double square_x, double square_y)
// {
// 	t_vector	v;
// 	double		x;
// 	double		y;
// 	double		x_map;
// 	double		y_map;

// 	x = ctx->player.pos_x;
// 	y = ctx->player.pos_y;
// 	x_map = (x / square_x);
// 	y_map = (y / square_y);
// 	printf("x,y %f,%f\n", x, y);
// 	init_vector(&v, (dir.x_i * 0.1), (dir.y_i * 0.1));
// 	while (ctx->map[(int)(y_map)][(int)(x_map)] != '1')
// 	{
// 		printf("x,y\n %f,%f\nmap_x.map_y\n%f.%f\n", x, y, x_map, y_map);
// 		mlx_pixel_put(ctx->mlx.mlx, ctx->mlx.win, x, y, 0x00ff00);
// 		x += v.x_i;
// 		y += v.y_i;
// 		x_map += v.x_i;
// 		y_map += v.y_i;
// 	}
// }
