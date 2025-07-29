/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_context.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:23:43 by mniemaz           #+#    #+#             */
/*   Updated: 2025/07/29 15:10:57 by mniemaz          ###   ########.fr       */
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
    if (init_texture_data(&ctx->texture_data) == EXIT_FAILURE)
    {
        printf_err("init_context: Failed to initialize texture data\n");
        return (EXIT_FAILURE);
    }
	return (EXIT_SUCCESS);
}