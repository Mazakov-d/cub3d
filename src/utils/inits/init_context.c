/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_context.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:23:43 by mniemaz           #+#    #+#             */
/*   Updated: 2025/08/04 15:07:49 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	init_texture_data(t_texture_data *tex_data)
{
	tex_data->north = NULL;
	tex_data->south = NULL;
	tex_data->east = NULL;
	tex_data->west = NULL;
	tex_data->floor = NULL;
	tex_data->ceiling = NULL;
	tex_data->floor = malloc(sizeof(t_color));
	if (!tex_data->floor)
		return (EXIT_FAILURE);
	tex_data->ceiling = malloc(sizeof(t_color));
	if (!tex_data->ceiling)
	{
		free(tex_data->floor);
		return (EXIT_FAILURE);
	}
	tex_data->floor->r = (unsigned char)COLOR_INIT_VAL;
	tex_data->ceiling->r = (unsigned char)COLOR_INIT_VAL;
	return (EXIT_SUCCESS);
}

int	init_context(t_context *ctx)
{
    ctx->map = NULL;
	ctx->mlx.keys.w_bool = false;
	ctx->mlx.keys.a_bool = false;
	ctx->mlx.keys.s_bool = false;
	ctx->mlx.keys.d_bool = false;
	ctx->mlx.keys.left_arrow_bool = false;
	ctx->mlx.keys.right_arrow_bool = false;
    if (init_texture_data(&ctx->texture_data) == EXIT_FAILURE)
    {
        printf_err("init_context: Failed to initialize texture data\n");
        return (EXIT_FAILURE);
    }
	return (EXIT_SUCCESS);
}