/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 17:08:30 by dmazari           #+#    #+#             */
/*   Updated: 2025/08/08 17:41:39 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	get_pixel_color_img(t_img img, int y_wall, int length, t_point_dir impact)
{
	double	fract_part;
	double	ratio;
	int		x_img;
	int		y_img;
	char	*pixel;

	ratio = y_wall / (double)length;
	if (impact.dir == SO || impact.dir == NO)
		fract_part = (double)impact.pos.x - (int)(impact.pos.x);
	else
		fract_part = (double)impact.pos.y - (int)(impact.pos.y);
	x_img = fract_part * img.width;
	y_img = ratio * img.height;

	pixel = img.data + (y_img * img.line_len + x_img * (img.bpp >> 3));
	return (*(int *)pixel);
}

inline void	put_pixel(t_context *ctx, int x, int y, int color)
{
	*(int *)(ctx->mlx->img.data + y * ctx->mlx->img.line_len + x
			* (ctx->mlx->img.bpp >> 3)) = color;
}
