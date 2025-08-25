/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:03:27 by dmazari           #+#    #+#             */
/*   Updated: 2025/08/25 13:25:15 by mniemaz          ###   ########.fr       */
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
	if (x - ctx->const_datas.center_win_x)
	{
		cos_res = cos(MOUSE_SPEED * (x - ctx->const_datas.center_win_x));
		sin_res = sin(MOUSE_SPEED * (x - ctx->const_datas.center_win_x));
		old_x = ctx->player.p_vec.x_i;
		ctx->player.p_vec.x_i = ctx->player.p_vec.x_i * cos_res
			- ctx->player.p_vec.y_i * sin_res;
		ctx->player.p_vec.y_i = old_x * sin_res + ctx->player.p_vec.y_i
			* cos_res;
		mlx_mouse_move(ctx->mlx->mlx_ptr, ctx->mlx->win_ptr,
			ctx->const_datas.center_win_x, ctx->const_datas.center_win_y);
	}
}
