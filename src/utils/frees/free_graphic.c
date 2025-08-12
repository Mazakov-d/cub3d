/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:11:35 by dmazari           #+#    #+#             */
/*   Updated: 2025/08/12 06:46:28 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs && strs[i])
	{
		if (strs[i])
			free(strs[i]);
		i++;
	}
	free(strs);
}

int	free_graphic(t_context *ctx)
{
	if (ctx->texture_data.walls[NO].img_ptr)
	{
		// mlx_destroy_image(ctx->mlx->mlx_ptr, ctx->texture_data.walls[NO].img_ptr);
		free(ctx->texture_data.walls[NO].img_ptr);
	}
	if (ctx->texture_data.walls[SO].img_ptr)
	{
		// mlx_destroy_image(ctx->mlx->mlx_ptr, ctx->texture_data.walls[NO].img_ptr);
		free(ctx->texture_data.walls[SO].img_ptr);
	}
	if (ctx->texture_data.walls[EA].img_ptr)
		free(ctx->texture_data.walls[EA].img_ptr);
	if (ctx->texture_data.walls[WE].img_ptr)
		free(ctx->texture_data.walls[WE].img_ptr);
	if (ctx->mlx->img.img_ptr)
		mlx_destroy_image(ctx->mlx->mlx_ptr, ctx->mlx->img.img_ptr);
	if (ctx->mlx->win_ptr)
		mlx_destroy_window(ctx->mlx->mlx_ptr, ctx->mlx->win_ptr);
	// mlx_destroy_display(ctx->mlx->mlx_ptr);
	free(ctx->mlx->mlx_ptr);
	free_context(ctx);
	exit(0);
	return (0);
}
