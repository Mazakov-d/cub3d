/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:08:30 by dmazari           #+#    #+#             */
/*   Updated: 2025/08/05 19:44:03 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	get_pixel_data(t_img img, int y_wall, int length, t_point_dir impact)
{
	double	fract_part;
	double	ratio;
	int		x_img;
	int		y_img;
	int		offset;
	char	*pixel;
	int		color;

	ratio = y_wall / (double)length;
	if (impact.dir == SO || impact.dir == NO)
		fract_part = fabs(impact.pos.x - round(impact.pos.x));
	else
		fract_part = fabs(impact.pos.y - round(impact.pos.y));
	x_img = fract_part * img.width;
	y_img = ratio * img.height;
	offset = y_img * img.line_len + x_img * (img.bpp / 8);
	// printf("offset: %d\n", offset);
	pixel = img.data + offset;
	color = *(int*)pixel;
	return (color); 
}

int	get_pixel_color_img(t_context *ctx, t_point_dir impact, int length, int y_wall)
{
	if (impact.dir == NO)
		return (get_pixel_data(ctx->texture_data.north, y_wall, length, impact));
	else if (impact.dir == SO)
		return (get_pixel_data(ctx->texture_data.south, y_wall, length, impact));
	else if (impact.dir == WE)
		return (get_pixel_data(ctx->texture_data.west, y_wall, length, impact));
	else
		return (get_pixel_data(ctx->texture_data.east, y_wall, length, impact));
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