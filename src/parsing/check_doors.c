/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 06:53:23 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/08/25 11:21:56 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @example
 * 000
 * 1c1
 * 000
 * -> true
 * 
 * 010
 * 0c0
 * 010
 * -> true
 * 
 * 000
 * 1c0
 * 000
 * -> false
 * 
 * 000
 * 1c0
 * 010
 * -> false
 */
bool	are_doors_surrounded_by_walls(char **map)
{
	int	row;
	int	col;

	row = -1;
	while (map[++row])
	{
		col = -1;
		while (map[row][++col])
		{
			if (map[row][col] == 'C')
			{
				if (!(((row > 0 && map[row - 1][col] == '1') && ((map[row + 1])
							&& col < ft_strlen(map[row + 1]) && map[row
								+ 1][col] == '1')) || ((col > 0 && map[row][col
								- 1] == '1') && (map[row][col + 1] == '1'))))
				{
					printf_err("Door at line %d, column\
%d is not surrounded by walls.\n", row + 1, col + 1);
					return (false);
				}
			}
		}
	}
	return (true);
}
