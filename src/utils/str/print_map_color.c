/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:38:28 by mniemaz           #+#    #+#             */
/*   Updated: 2025/08/25 11:11:19 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/**
 * prints the map, the char at pos (row, col) is colored in red
 */
void	print_map_color(char **map, int row, int col)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (i == row && j == col && map[i][j] == 'X')
				printf("\033[31m%c\033[0m", '0');
			else if (i == row && j == col)
				printf("\033[31m%c\033[0m", map[i][j]);
			else if (map[i][j] == 'X')
				printf("\033[32m%c\033[0m", '0');
			else
				printf("%c", map[i][j]);
		}
		printf("\n");
	}
}
