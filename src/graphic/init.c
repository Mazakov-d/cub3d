/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:32:17 by dmazari           #+#    #+#             */
/*   Updated: 2025/07/30 13:54:03 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <stdio.h>

int	key_hook(int keycode, t_context *context)
{
	(void)context;
	printf("keycode: %d\n", keycode);
	if (keycode == 65307)
		free_graphic(context);
	return (0);
}

void	init_graphic(t_context *context)
{
	context->mlx.mlx = mlx_init();
	context->mlx.win = mlx_new_window(context->mlx.mlx, WIN_SIZE_X, WIN_SIZE_Y,
			"Dodo c'est le meilleur");
	mlx_key_hook(context->mlx.win, key_hook, context);
	mlx_hook(context->mlx.win, 17, 0L, free_graphic, (void *)context);
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
