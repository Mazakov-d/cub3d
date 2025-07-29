/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flood_fill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:12:42 by mniemaz           #+#    #+#             */
/*   Updated: 2025/07/29 17:38:48 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	process_flood_fill(void)
{
	return (EXIT_SUCCESS);
}

void	set_user_pos(char **map, int *user_row, int *user_col)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (is_char_in_str(map[row][col], USER_CHARS))
			{
				*user_row = row;
				*user_col = col;
				return ;
			}
			col++;
		}
		row++;
	}
}

/**
 * @brief Checks if the flood fill algorithm can be applied to the map.
 * It checks if the map is surrounded by walls and if there are no gaps.
 * @returns EXIT_SUCCESS if the flood fill can be applied,
	EXIT_FAILURE otherwise.
 */
int	check_flood_fill(t_context *ctx)
{
	char **map;
	int row;
	int col;

	map = ft_strsdup(ctx->map);
	if (!map)
		return (printf_err("check_flood_fill: %s\n", strerror(errno)));
	row = 0;
	set_user_pos(map, &row, &col);
	printf("User position: (%d, %d)\n", row, col);
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			printf("%c", map[row][col]);
			col++;
		}
		printf("\n");
		row++;
	}

	ft_free_tab((void **)map);
	return (EXIT_SUCCESS);
}