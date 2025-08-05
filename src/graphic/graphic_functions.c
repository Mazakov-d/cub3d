/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:08:30 by dmazari           #+#    #+#             */
/*   Updated: 2025/08/05 18:36:03 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	get_pixel_color_img(t_img *img, int i, int length, t_point impact_point)
{
	int		color;
	double	nearest_int;
	double	distance;
	int		pos_x;

	pos_x = ;
	if (impact_point.dir == NO || impact_point == SO)
	{
		nearest_int = round(impact_point.x);
		distance = fabs(impact_point.x - nearest_int);
		
		printf("distance %f\n", distance);
	}
	else
	{
		nearest_int = round(impact_point.y);
		distance = fabs(impact_point.y - nearest_int);
		printf("distance %f\n", distance);
	}
	return (0xffffff);
}

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