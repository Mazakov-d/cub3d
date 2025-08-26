/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_context.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:36:31 by mniemaz           #+#    #+#             */
/*   Updated: 2025/08/26 11:11:49 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_context(t_context *ctx)
{
	if (!ctx)
		return ;
	if (ctx->texture_data.walls[NO].img_name)
		free(ctx->texture_data.walls[NO].img_name);
	if (ctx->texture_data.walls[SO].img_name)
		free(ctx->texture_data.walls[SO].img_name);
	if (ctx->texture_data.walls[EA].img_name)
		free(ctx->texture_data.walls[EA].img_name);
	if (ctx->texture_data.walls[WE].img_name)
		free(ctx->texture_data.walls[WE].img_name);
	if (ctx->texture_data.walls[CLOSE].img_name)
		free(ctx->texture_data.walls[CLOSE].img_name);
	if (ctx->mlx)
		free(ctx->mlx);
	ft_free_tab((void **)ctx->map);
}
