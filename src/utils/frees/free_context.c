/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_context.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:36:31 by mniemaz           #+#    #+#             */
/*   Updated: 2025/07/29 10:38:21 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void free_context(t_context *ctx)
{
    if (!ctx)
        return;

    if (ctx->texture_data.north)
        free(ctx->texture_data.north);
    if (ctx->texture_data.south)
        free(ctx->texture_data.south);
    if (ctx->texture_data.east)
        free(ctx->texture_data.east);
    if (ctx->texture_data.west)
        free(ctx->texture_data.west);
    if (ctx->texture_data.floor)
        free(ctx->texture_data.floor);
    if (ctx->texture_data.ceiling)
        free(ctx->texture_data.ceiling);

    ft_free_tab((void **)ctx->map);
}