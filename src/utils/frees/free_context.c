/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_context.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:36:31 by mniemaz           #+#    #+#             */
/*   Updated: 2025/08/05 14:56:59 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void free_context(t_context *ctx)
{
    if (!ctx)
        return;

    if (ctx->texture_data.north.img_name)
        free(ctx->texture_data.north.img_name);
    if (ctx->texture_data.south.img_name)
        free(ctx->texture_data.south.img_name);
    if (ctx->texture_data.east.img_name)
        free(ctx->texture_data.east.img_name);
    if (ctx->texture_data.west.img_name)
        free(ctx->texture_data.west.img_name);
    if (ctx->texture_data.floor)
        free(ctx->texture_data.floor);
    if (ctx->texture_data.ceiling)
        free(ctx->texture_data.ceiling);
    if (ctx->mlx)
        free(ctx->mlx);
    ft_free_tab((void **)ctx->map);
}
