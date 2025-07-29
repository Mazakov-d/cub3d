/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flood_fill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:12:42 by mniemaz           #+#    #+#             */
/*   Updated: 2025/07/29 19:33:27 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	process_flood_fill(char **map, int row, int col)
{
	if (map[row][col] == '0')
		map[row][col] = 'X';
	else if (!is_char_in_str(map[row][col], USER_CHARS))
		return ;
	if (row > 0 && ft_strlen(map[row - 1]) > col)
		process_flood_fill(map, row - 1, col);
	process_flood_fill(map, row, col + 1);
	if (map[row + 1] && ft_strlen(map[row + 1]) > col)
		process_flood_fill(map, row + 1, col);
	if (col > 0)
		process_flood_fill(map, row, col - 1);
}

static void	set_user_pos(char **map, int *user_row, int *user_col)
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

static bool	are_side_chars_valid(char **map, int row, int col)
{
	if (col == 0 || col == (ft_strlen(map[row]) - 1))
		return (false);
	if (!(map[row + 1] && ft_strlen(map[row + 1]) > col))
		return (false);
	if ((row == 0 || ft_strlen(map[row - 1]) <= col))
		return (false);
	if (map[row - 1][col] == ' ')
		return (false);
	if (map[row + 1][col] == ' ')
		return (false);
	if (map[row][col - 1] == ' ')
		return (false);
	if (map[row][col + 1] == ' ')
		return (false);
	return (true);
}

bool	is_map_valid(char **map)
{
	int	row;
	int	col;

	row = -1;
	while (map[++row])
	{
		col = -1;
		while (map[row][++col])
		{
			if (map[row][col] == 'X' || is_char_in_str(map[row][col],
					USER_CHARS))
			{
				if (are_side_chars_valid(map, row, col) == false)
					return (false);
			}
		}
	}
	return (true);
}

/**
 * @brief Checks if the flood fill algorithm can be applied to the map.
 * It checks if the map is surrounded by walls and if there are no gaps.
 * @returns EXIT_SUCCESS if the flood fill can be applied,
	EXIT_FAILURE otherwise.
 */
int	check_flood_fill(t_context *ctx)
{
	char	**map;
	int		row;
	int		col;

	map = ft_strsdup(ctx->map);
	if (!map)
		return (printf_err("check_flood_fill: %s\n", strerror(errno)));
	set_user_pos(map, &row, &col);
	process_flood_fill(map, row, col);
	if (!is_map_valid(map))
	{
		printf_err("Map is not valid after flood fill.\n");
		ft_free_tab((void **)map);
		return (EXIT_FAILURE);
	}
	ft_free_tab((void **)map);
	return (EXIT_SUCCESS);
}
