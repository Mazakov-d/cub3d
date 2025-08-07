/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:03:27 by dmazari           #+#    #+#             */
/*   Updated: 2025/08/07 15:47:06 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	mouse_move(t_context *ctx)
{
	double	old_x;
	int	x;
	int	y;
	double delta_x;

	mlx_mouse_get_pos(ctx->mlx->mlx_ptr, ctx->mlx->win_ptr, &x, &y);
	delta_x = x - (WIN_SIZE_X >> 1);
	if (delta_x)
	{
		old_x = ctx->player.p_vec.x_i;
		ctx->player.p_vec.x_i = ctx->player.p_vec.x_i * cos(MOUSE_SPEED * delta_x)
		- ctx->player.p_vec.y_i * sin(MOUSE_SPEED * delta_x);
		ctx->player.p_vec.y_i = old_x * sin(MOUSE_SPEED *delta_x)
		+ ctx->player.p_vec.y_i * cos(MOUSE_SPEED * delta_x);
		mlx_mouse_move(ctx->mlx->mlx_ptr, ctx->mlx->win_ptr, WIN_SIZE_X >> 1, WIN_SIZE_Y >> 1);
	}
}
