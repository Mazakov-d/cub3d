/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flood_fill.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:12:42 by mniemaz           #+#    #+#             */
/*   Updated: 2025/07/29 17:19:21 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
		}
	}
    return (EXIT_SUCCESS);
}