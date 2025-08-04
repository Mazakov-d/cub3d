/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_2d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:48:23 by mniemaz           #+#    #+#             */
/*   Updated: 2025/07/30 14:48:54 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	print_square(t_context *ctx, int x, int y, int square_x, int square_y,
		char c)
{
	int	i;
	int	j;

	i = 0;
	while (i < square_x)
	{
		j = 0;
		while (j < square_y)
		{
			if (c == '1')
				mlx_pixel_put(ctx->mlx.mlx, ctx->mlx.win, x + i, y + j, 0x444444);
			if (c == '0')
				mlx_pixel_put(ctx->mlx.mlx, ctx->mlx.win, x + i, y + j, 0xbbbbbb);
            j++;
		}
		i++;
	}
}

void	display_2d_map(t_context *ctx)
{
	int	largest_line;
	int	nb_rows;
	int	i;
	int	square_x;
	int	square_y;
    char **map = ctx->map;

	// int square_size;
	i = 0;
	largest_line = 0;
	while (ctx->map[i])
	{
		if (ft_strlen(ctx->map[i]) > largest_line)
			largest_line = ft_strlen(ctx->map[i]);
		i++;
	}
	nb_rows = i;
	printf("largest line, %d, rows: %d", largest_line, nb_rows);
	square_x = WIN_SIZE_X / largest_line;
	square_y = WIN_SIZE_Y / nb_rows;
    int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			print_square(ctx, square_x * col, square_y * row, square_x - 1, square_y - 1, map[row][col]);
            col++;
		}
		row++;
	}
    ctx->player.pos_x *= square_x;
    ctx->player.pos_y *= square_y;
    // ray_man(ctx, ctx->player.p_vec, square_x, square_y);
}
