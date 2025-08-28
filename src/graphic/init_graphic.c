/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:32:17 by dmazari           #+#    #+#             */
/*   Updated: 2025/08/28 13:05:51 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	open_image(t_img *img, t_mlx *mlx)
{
	img->img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, img->img_name,
			&img->width, &img->height);
	if (!img->img_ptr)
	{
		printf_err("Can't open the file: '%s'\n", img->img_name);
		return (EXIT_FAILURE);
	}
	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->line_len,
			&img->endian);
	if (!img->data)
	{
		printf_err("%s: %s\n", img->img_name, strerror(errno));
		return (EXIT_FAILURE);
	}
	free(img->img_name);
	img->img_name = NULL;
	return (EXIT_SUCCESS);
}

void	render_window_pxls(t_context *ctx)
{
	set_player_angles(ctx);
	handle_rays(ctx, draw_vertical_ray, WIN_SIZE_X);
	display_2d_map(ctx);
}

static void	init_texture(t_context *ctx)
{
	if (open_image(&ctx->texture_data.walls[NO], ctx->mlx))
		free_graphic(ctx);
	if (open_image(&ctx->texture_data.walls[SO], ctx->mlx))
		free_graphic(ctx);
	if (open_image(&ctx->texture_data.walls[EA], ctx->mlx))
		free_graphic(ctx);
	if (open_image(&ctx->texture_data.walls[WE], ctx->mlx))
		free_graphic(ctx);
	if (BONUS && open_image(&ctx->texture_data.walls[CLOSE], ctx->mlx))
		free_graphic(ctx);
}

void	init_graphic(t_context *ctx)
{
	ctx->mlx->mlx_ptr = mlx_init();
	if (!ctx->mlx->mlx_ptr)
		return ;
	ctx->mlx->win_ptr = mlx_new_window(ctx->mlx->mlx_ptr, WIN_SIZE_X,
			WIN_SIZE_Y, "Cub3D");
	if (!ctx->mlx->win_ptr)
		free_graphic(ctx);
	init_texture(ctx);
	ctx->mlx->img.img_ptr = mlx_new_image(ctx->mlx->mlx_ptr, WIN_SIZE_X,
			WIN_SIZE_Y);
	if (!ctx->mlx->img.img_ptr)
		free_graphic(ctx);
	ctx->mlx->img.data = mlx_get_data_addr(ctx->mlx->img.img_ptr,
			&ctx->mlx->img.bpp, &ctx->mlx->img.line_len, &ctx->mlx->img.endian);
	mlx_mouse_hide(ctx->mlx->mlx_ptr, ctx->mlx->win_ptr);
	mlx_mouse_move(ctx->mlx->mlx_ptr, ctx->mlx->win_ptr,
		ctx->const_datas.center_win_x, ctx->const_datas.center_win_y);
	mlx_hook(ctx->mlx->win_ptr, 2, 1L << 0, key_hook_press, ctx);
	mlx_hook(ctx->mlx->win_ptr, 3, 1L << 1, key_release, ctx);
	mlx_hook(ctx->mlx->win_ptr, 17, 0L, free_graphic, (void *)ctx);
	render_window_pxls(ctx);
	mlx_put_image_to_window(ctx->mlx->mlx_ptr, ctx->mlx->win_ptr,
		ctx->mlx->img.img_ptr, 0, 0);
	mlx_loop_hook(ctx->mlx->mlx_ptr, move_player, ctx);
	mlx_loop(ctx->mlx->mlx_ptr);
}
