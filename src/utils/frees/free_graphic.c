/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:11:35 by dmazari           #+#    #+#             */
/*   Updated: 2025/08/26 14:21:32 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	free_graphic(t_context *ctx)
{
	int	i;

	i = 0;
	while (i < NB_TEXTURES)
	{
		if (ctx->texture_data.walls[i].img_ptr)
			mlx_destroy_image(ctx->mlx->mlx_ptr,
				ctx->texture_data.walls[i].img_ptr);
		i++;
	}
	if (ctx->mlx->img.img_ptr)
		mlx_destroy_image(ctx->mlx->mlx_ptr, ctx->mlx->img.img_ptr);
	if (ctx->mlx->win_ptr)
	{
		mlx_clear_window(ctx->mlx->mlx_ptr, ctx->mlx->win_ptr);
		mlx_destroy_window(ctx->mlx->mlx_ptr, ctx->mlx->win_ptr);
	}
	mlx_destroy_display(ctx->mlx->mlx_ptr);
	free(ctx->mlx->mlx_ptr);
	free_context(ctx);
	exit(EXIT_SUCCESS);
	return (0);
}
