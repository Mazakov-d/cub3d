/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_context.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:23:43 by mniemaz           #+#    #+#             */
/*   Updated: 2025/08/28 12:59:08 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	init_const_datas(t_context *ctx)
{
	ctx->const_datas.fov_rad = FOV_DEG * (PI / 180);
	ctx->const_datas.fov_rad_div_2 = ctx->const_datas.fov_rad * 0.5;
	ctx->const_datas.pi_div_2 = PI * 0.5;
	ctx->const_datas.pi_times_2 = PI * 2;
	ctx->const_datas.center_win_x = WIN_SIZE_X * 0.5;
	ctx->const_datas.center_win_y = WIN_SIZE_Y * 0.5;
	ctx->const_datas.mini_map_x = WIN_SIZE_X * 0.2;
	ctx->const_datas.mini_map_y = WIN_SIZE_Y * 0.2;
}

static void	init_texture_data(t_texture_data *tex_data)
{
	tex_data->walls[NO].img_name = NULL;
	tex_data->walls[SO].img_name = NULL;
	tex_data->walls[EA].img_name = NULL;
	tex_data->walls[WE].img_name = NULL;
	tex_data->walls[NO].data = NULL;
	tex_data->walls[SO].data = NULL;
	tex_data->walls[EA].data = NULL;
	tex_data->walls[WE].data = NULL;
	tex_data->walls[NO].img_ptr = NULL;
	tex_data->walls[SO].img_ptr = NULL;
	tex_data->walls[EA].img_ptr = NULL;
	tex_data->walls[WE].img_ptr = NULL;
	tex_data->floor_hexa = HEXA_INIT_VAL;
	tex_data->ceiling_hexa = HEXA_INIT_VAL;
	if (BONUS)
	{
		tex_data->walls[CLOSE].img_name = NULL;
		tex_data->walls[CLOSE].data = NULL;
		tex_data->walls[CLOSE].img_ptr = NULL;
	}
}

int	init_mlx_data(t_context *ctx)
{
	ctx->mlx = malloc(sizeof(t_mlx));
	if (!ctx->mlx)
		return (printf_err("Failed to initialize texture data\n"));
	ctx->mlx->img.img_ptr = NULL;
	ctx->mlx->img.data = NULL;
	ctx->mlx->keys.w_bool = false;
	ctx->mlx->keys.a_bool = false;
	ctx->mlx->keys.s_bool = false;
	ctx->mlx->keys.d_bool = false;
	ctx->mlx->keys.left_arrow_bool = false;
	ctx->mlx->keys.right_arrow_bool = false;
	return (EXIT_SUCCESS);
}

int	init_context(t_context *ctx)
{
	ctx->map = NULL;
	init_texture_data(&ctx->texture_data);
	if (init_mlx_data(ctx) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	init_const_datas(ctx);
	return (EXIT_SUCCESS);
}
