/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_context.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:23:43 by mniemaz           #+#    #+#             */
/*   Updated: 2025/08/06 14:42:58 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	init_texture_data(t_texture_data *tex_data)
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
	tex_data->floor = malloc(sizeof(t_color));
	if (!tex_data->floor)
		return (EXIT_FAILURE);
	tex_data->ceiling = malloc(sizeof(t_color));
	if (!tex_data->ceiling)
		return (EXIT_FAILURE);
	tex_data->floor->r = (unsigned char)COLOR_INIT_VAL;
	tex_data->ceiling->r = (unsigned char)COLOR_INIT_VAL;
	return (EXIT_SUCCESS);
}

int	init_context(t_context *ctx)
{
    ctx->map = NULL;
	ctx->mlx = malloc(sizeof(t_mlx));
	if (!ctx->mlx)
		return (printf_err("init_context: Failed to initialize texture data\n"));
	ctx->mlx->img.img_ptr = NULL;
	ctx->mlx->img.data = NULL;
    if (init_texture_data(&ctx->texture_data) == EXIT_FAILURE)
    {
        printf_err("init_context: Failed to initialize texture data\n");
        free_context(ctx);
		return (EXIT_FAILURE);
    }
	ctx->mlx->keys.w_bool = false;
	ctx->mlx->keys.a_bool = false;
	ctx->mlx->keys.s_bool = false;
	ctx->mlx->keys.d_bool = false;
	ctx->mlx->keys.left_arrow_bool = false;
	ctx->mlx->keys.right_arrow_bool = false;
	return (EXIT_SUCCESS);
}
