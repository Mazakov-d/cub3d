/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:03:27 by dmazari           #+#    #+#             */
/*   Updated: 2025/08/25 12:18:59 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	mouse_move(t_context *ctx)
{
	double	old_x;
	int		x;
	int		y;
	double	cos_res;
	double	sin_res;

	mlx_mouse_get_pos(ctx->mlx->mlx_ptr, ctx->mlx->win_ptr, &x, &y);
	if (x - CENTER_WIN_X)
	{
		cos_res = cos(MOUSE_SPEED * (x - CENTER_WIN_X));
		sin_res = sin(MOUSE_SPEED * (x - CENTER_WIN_X));
		old_x = ctx->player.p_vec.x_i;
		ctx->player.p_vec.x_i = ctx->player.p_vec.x_i * cos_res
			- ctx->player.p_vec.y_i * sin_res;
		ctx->player.p_vec.y_i = old_x * sin_res + ctx->player.p_vec.y_i
			* cos_res;
		mlx_mouse_move(ctx->mlx->mlx_ptr, ctx->mlx->win_ptr, CENTER_WIN_X,
			CENTER_WIN_Y);
	}
}
