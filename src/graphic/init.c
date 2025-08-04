/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:32:17 by dmazari           #+#    #+#             */
/*   Updated: 2025/08/04 13:22:21 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <stdio.h>

int	key_hook(int keycode, t_context *context)
{
	if (keycode == ESC)
		free_graphic(context);
	else if (keycode == W)
		go_forward_backward(&context->player, context->map, 'W');
	else if (keycode == A)
		go_left_right(&context->player, context->map, 'A');
	else if (keycode == S)
		go_forward_backward(&context->player, context->map, 'S');
	else if (keycode == D)
		go_left_right(&context->player, context->map, 'D');
	else if (keycode == LEFT_ARROW)
		turn_left();
	else if (keycode == RIGHT_ARROW)
		turn_right();
	printf("pos_x: %f, pos_y: %f\n", context->player.pos_x, context->player.pos_y);
	// display_2d_map(context);
	return (0);
}

void	init_graphic(t_context *context)
{
	context->mlx.mlx = mlx_init();
	context->mlx.win = mlx_new_window(context->mlx.mlx, WIN_SIZE_X, WIN_SIZE_Y,
			"Dodo c'est le meilleur");
	mlx_key_hook(context->mlx.win, key_hook, context);
	mlx_hook(context->mlx.win, 17, 0L, free_graphic, (void *)context);
	display_2d_map(context);
	mlx_loop(context->mlx.mlx);
}

// void init_graphic(t_context *ctx)
// {
// 	float	dx = cos(M_PI/6);
// 	float	dy = sin(M_PI/6);
// 	float	pos_x = 2.5f;
// 	float	pos_y = 1.5f;
// 	// (void)ctx;

// 	// float touch_point_x;
// 	// float touch_point_y;
// 	while (ctx->map[(int)floor(pos_y)][(int)floor(pos_x)] != '1')
// 	{
// 		printf("(%f, %f)\n", pos_x, pos_y);
// 		pos_x += dx * 0.1;
// 		pos_y += dy * 0.1;
// 	}
// 	printf("%f || %f\n", pos_x, pos_y);
// }
