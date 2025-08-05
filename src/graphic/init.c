/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:32:17 by dmazari           #+#    #+#             */
/*   Updated: 2025/08/05 13:36:29 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <stdio.h>

int	key_hook_press(int keycode, t_context *context)
{
	if (keycode == ESC)
		free_graphic(context);
	else if (keycode == W)
		context->mlx.keys.w_bool = true;
	else if (keycode == A)
		context->mlx.keys.a_bool = true;
	else if (keycode == S)
		context->mlx.keys.s_bool = true;
	else if (keycode == D)
		context->mlx.keys.d_bool = true;
	else if (keycode == LEFT_ARROW)
		context->mlx.keys.left_arrow_bool = true;
	else if (keycode == RIGHT_ARROW)
		context->mlx.keys.right_arrow_bool = true;
	return (0);
}

int	key_release(int keycode, t_context *context)
{
	if (keycode == W)
		context->mlx.keys.w_bool = false;
	else if (keycode == A)
		context->mlx.keys.a_bool = false;
	else if (keycode == S)
		context->mlx.keys.s_bool = false;
	else if (keycode == D)
		context->mlx.keys.d_bool = false;
	else if (keycode == LEFT_ARROW)
		context->mlx.keys.left_arrow_bool = false;
	else if (keycode == RIGHT_ARROW)
		context->mlx.keys.right_arrow_bool = false;
	return (0);
}

int move_player(t_context *ctx)
{
	if (ctx->mlx.keys.w_bool)
		go_forward(&ctx->player, ctx->map);
	else if (ctx->mlx.keys.s_bool)
		go_backward(&ctx->player, ctx->map);
	else if (ctx->mlx.keys.a_bool)
		go_left(&ctx->player, ctx->map);
	else if (ctx->mlx.keys.d_bool)
		go_right(&ctx->player, ctx->map);
	if (ctx->mlx.keys.left_arrow_bool)
		turn_left(ctx);
	if (ctx->mlx.keys.right_arrow_bool)
		turn_right(ctx);
	display_2d_map(ctx);
	mlx_put_image_to_window(ctx->mlx.mlx, ctx->mlx.win, ctx->mlx.img.img_ptr, 0, 0);
	return (0);
}

void	init_graphic(t_context *ctx)
{
	ctx->mlx.mlx = mlx_init();
	ctx->mlx.win = mlx_new_window(ctx->mlx.mlx, WIN_SIZE_X, WIN_SIZE_Y,
			"Dodo c'est le meilleur");
	ctx->mlx.img.img_ptr = mlx_new_image(ctx->mlx.mlx, WIN_SIZE_X, WIN_SIZE_Y);
	ctx->mlx.img.data = mlx_get_data_addr(ctx->mlx.img.img_ptr, 
		&ctx->mlx.img.bpp, &ctx->mlx.img.line_len, &ctx->mlx.img.endian);
	mlx_hook(ctx->mlx.win, 2, 1L<<0, key_hook_press, ctx);
	mlx_hook(ctx->mlx.win, 3, 1L<<1, key_release, ctx);
	mlx_hook(ctx->mlx.win, 17, 0L, free_graphic, (void *)ctx);
	display_2d_map(ctx);
	mlx_put_image_to_window(ctx->mlx.mlx, ctx->mlx.win, ctx->mlx.img.img_ptr, 0, 0);
	mlx_loop_hook(ctx->mlx.mlx, move_player, ctx);
	mlx_loop(ctx->mlx.mlx);
}

// press = bool a true
// relache = bool a false
// mlx_loop_hook si bool = true alors fait action
// 1 bool par action


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
