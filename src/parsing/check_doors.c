/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 06:53:23 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/08/12 07:41:28 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool are_doors_surrounded_by_walls(char **map)
{
    int row;
    int col;

    row = 0;
    while (map[row])
    {
        col = 0;
        while (map[row][col])
        {
            if (map[row][col] == 'C')
            {
                if (!(
                    ((row > 0 && map[row - 1][col] == '1') && ((map[row + 1]) && col < ft_strlen(map[row + 1]) && map[row + 1][col] == '1')) ||
                    ((col > 0 && map[row][col - 1] == '1') && (map[row][col + 1] == '1'))
                    ))
                {
                    printf_err("Door at line %d, column %d is not surrounded by walls.\n", row + 1, col + 1);
                    return false;
                }
            }
            col++;
        }
        row++;
    }
    return true;
}
