/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_handling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorianmazari <dorianmazari@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:22:49 by dmazari           #+#    #+#             */
/*   Updated: 2025/08/12 15:02:48 by dorianmazar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	key_hook_press(int keycode, t_context *ctx)
{
	if (keycode == ESC)
		free_graphic(ctx);
	else if (keycode == W)
		ctx->mlx->keys.w_bool = true;
	else if (keycode == A)
		ctx->mlx->keys.a_bool = true;
	else if (keycode == S)
		ctx->mlx->keys.s_bool = true;
	else if (keycode == D)
		ctx->mlx->keys.d_bool = true;
	else if (keycode == LEFT_ARROW)
		ctx->mlx->keys.left_arrow_bool = true;
	else if (keycode == RIGHT_ARROW)
		ctx->mlx->keys.right_arrow_bool = true;
	return (0);
}

int	key_release(int keycode, t_context *ctx)
{
	if (keycode == W)
		ctx->mlx->keys.w_bool = false;
	else if (keycode == A)
		ctx->mlx->keys.a_bool = false;
	else if (keycode == S)
		ctx->mlx->keys.s_bool = false;
	else if (keycode == D)
		ctx->mlx->keys.d_bool = false;
	else if (keycode == LEFT_ARROW)
		ctx->mlx->keys.left_arrow_bool = false;
	else if (keycode == RIGHT_ARROW)
		ctx->mlx->keys.right_arrow_bool = false;
	return (0);
}

int move_player(t_context *ctx)
{
	if (ctx->mlx->keys.w_bool)
		go_forward(&ctx->player, ctx->map);
	if (ctx->mlx->keys.s_bool)
		go_backward(&ctx->player, ctx->map);
	if (ctx->mlx->keys.a_bool)
		go_left(&ctx->player, ctx->map);
	if (ctx->mlx->keys.d_bool)
		go_right(&ctx->player, ctx->map);
	if (ctx->mlx->keys.left_arrow_bool)
		turn_left(ctx);
	if (ctx->mlx->keys.right_arrow_bool)
		turn_right(ctx);
	render_window_pxls(ctx);
	mouse_move(ctx);
	mlx_put_image_to_window(ctx->mlx->mlx_ptr, ctx->mlx->win_ptr, ctx->mlx->img.img_ptr, 0, 0);
	return (0);
}
