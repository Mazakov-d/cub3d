/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandatory_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:04:35 by dmazari           #+#    #+#             */
/*   Updated: 2025/08/26 11:15:51 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub.h"

void	init_texture(t_context *ctx)
{
	if (open_image(&ctx->texture_data.walls[NO], ctx->mlx))
		free_graphic(ctx);
	if (open_image(&ctx->texture_data.walls[SO], ctx->mlx))
		free_graphic(ctx);
	if (open_image(&ctx->texture_data.walls[EA], ctx->mlx))
		free_graphic(ctx);
	if (open_image(&ctx->texture_data.walls[WE], ctx->mlx))
		free_graphic(ctx);
}

bool	is_texture_data_filled(t_texture_data *tex_data)
{
	return (tex_data->walls[NO].img_name && tex_data->walls[SO].img_name
		&& tex_data->walls[EA].img_name && tex_data->walls[WE].img_name
		&& tex_data->floor_hexa != HEXA_INIT_VAL
		&& tex_data->ceiling_hexa != HEXA_INIT_VAL);
}

void	prep_to_fill_wall_types(t_texture_data **tex_data, char **wall_type,
		char ***to_fill)
{
	wall_type[NO] = "NO";
	wall_type[SO] = "SO";
	wall_type[EA] = "EA";
	wall_type[WE] = "WE";
	to_fill[NO] = &((*tex_data)->walls[NO].img_name);
	to_fill[SO] = &((*tex_data)->walls[SO].img_name);
	to_fill[EA] = &((*tex_data)->walls[EA].img_name);
	to_fill[WE] = &((*tex_data)->walls[WE].img_name);
}

/**
 * @returns EXIT_SUCCESS if a direction was filled, EXIT_FAILURE on error,
 * EXIT_NEUTRAL if nothing happened.
 */
int	fill_wall_types(t_texture_data *tex_data, char **lines_tab)
{
	char	*wall_type[4];
	char	**to_fill[4];
	int		i;

	prep_to_fill_wall_types(&tex_data, wall_type, to_fill);
	i = -1;
	while (++i < 4)
	{
		if (ft_strncmp(lines_tab[0], wall_type[i], 3) != 0)
			continue ;
		if (!lines_tab[1])
			return (printf_err("No texture for: %s\n", wall_type[i]));
		*to_fill[i] = ft_strdup(lines_tab[1]);
		if (!*to_fill[i])
			return (printf_err("fill_wall_type: %s\n", strerror(errno)));
		return (EXIT_SUCCESS);
	}
	return (EXIT_NEUTRAL);
}

int	free_graphic(t_context *ctx)
{
	int	i;

	i = 0;
	while (i < 4)
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
		mlx_mouse_show(ctx->mlx->mlx_ptr, ctx->mlx->win_ptr);
		mlx_destroy_window(ctx->mlx->mlx_ptr, ctx->mlx->win_ptr);
	}
	mlx_destroy_display(ctx->mlx->mlx_ptr);
	free(ctx->mlx->mlx_ptr);
	free_context(ctx);
	exit(EXIT_SUCCESS);
	return (0);
}
