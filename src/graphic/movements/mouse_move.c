/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:03:27 by dmazari           #+#    #+#             */
/*   Updated: 2025/08/07 17:39:42 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	mouse_move(t_context *ctx)
{
	double	old_x;
	int	x;
	int	y;
	double delta_x;
	double	cos_res;
	double	sin_res;

	mlx_mouse_get_pos(ctx->mlx->mlx_ptr, ctx->mlx->win_ptr, &x, &y);
	delta_x = x - (CENTER_WIN_X);
	if (delta_x)
	{
		cos_res = cos(MOUSE_SPEED * delta_x);
		sin_res =  sin(MOUSE_SPEED * delta_x);
		old_x = ctx->player.p_vec.x_i;
		ctx->player.p_vec.x_i = ctx->player.p_vec.x_i * cos_res
		- ctx->player.p_vec.y_i * sin_res;
		ctx->player.p_vec.y_i = old_x * sin_res
		+ ctx->player.p_vec.y_i * cos_res;
		mlx_mouse_move(ctx->mlx->mlx_ptr, ctx->mlx->win_ptr, CENTER_WIN_X, CENTER_WIN_Y);
	}
}
