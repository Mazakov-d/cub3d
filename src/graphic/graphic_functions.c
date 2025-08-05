/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:08:30 by dmazari           #+#    #+#             */
/*   Updated: 2025/08/05 16:31:05 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	put_pixel(t_context *ctx, int x, int y, int color)
{
	char	*pixel;
	int		offset;

	if (x < 0 || x >= WIN_SIZE_X || y < 0 || y >= WIN_SIZE_Y)
		return ;
	offset = y * ctx->mlx->img.line_len + x * (ctx->mlx->img.bpp / 8);
	pixel = ctx->mlx->img.data + offset;
	*(int*)pixel = color;
}

// void	clear_image(t_context *ctx)
// {
// 	int	x;
// 	int	y;

// 	y = 0;
// 	while (y < WIN_SIZE_Y)
// 	{
// 		x = 0;
// 		while (x < WIN_SIZE_X)
// 		{
// 			put_pixel(ctx, x, y, 0x000000);
// 			x++;
// 		}
// 		y++;
// 	}
// }

// void	clear_image_fast(t_context *ctx)
// {
// 	int total_pixels = WIN_SIZE_X * WIN_SIZE_Y * (ctx->mlx->img.bpp / 8);
// 	memset(ctx->mlx->img.data, 0, total_pixels);
// }