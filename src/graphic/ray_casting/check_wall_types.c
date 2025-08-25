/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_types.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 13:16:48 by dmazari           #+#    #+#             */
/*   Updated: 2025/08/25 13:29:54 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_wall_type	check_south_wall(t_point pos, char **map)
{
	if (!map[(int)floorf(pos.y) + 1] || ft_strlen(map[(int)floorf(pos.y)
				+ 1]) <= (int)(pos.x))
		return (SO);
	if (map[(int)floorf(pos.y)][(int)(pos.x)] == '1')
		return (SO);
	if (map[(int)floorf(pos.y)][(int)(pos.x)] == 'C')
		return (CLOSE);
	if (map[(int)floorf(pos.y)][(int)(pos.x)] == 'O')
		return (OPEN);
	return (NONE);
}

t_wall_type	check_east_wall(t_point pos, char **map)
{
	if (map[(int)(pos.y)][(int)floorf(pos.x)]
		&& map[(int)(pos.y)][(int)floorf(pos.x)] == '1')
		return (EA);
	if (map[(int)(pos.y)][(int)floorf(pos.x)]
		&& map[(int)(pos.y)][(int)floorf(pos.x)] == 'C')
		return (CLOSE);
	if (map[(int)(pos.y)][(int)floorf(pos.x)]
		&& map[(int)(pos.y)][(int)floorf(pos.x)] == 'O')
		return (OPEN);
	return (NONE);
}

t_wall_type	check_west_wall(t_point pos, char **map)
{
	if (pos.x == 0.0f)
		return (WE);
	if (map[(int)(pos.y)][(int)floorf(pos.x) - 1]
		&& map[(int)(pos.y)][(int)floorf(pos.x) - 1] == '1')
		return (WE);
	if (map[(int)(pos.y)][(int)floorf(pos.x) - 1]
		&& map[(int)(pos.y)][(int)floorf(pos.x) - 1] == 'C')
		return (CLOSE);
	if (map[(int)(pos.y)][(int)floorf(pos.x) - 1]
		&& map[(int)(pos.y)][(int)floorf(pos.x) - 1] == 'O')
		return (OPEN);
	return (NONE);
}

t_wall_type	check_north_wall(t_point pos, char **map)
{
	if ((int)floorf(pos.y) == 0 || ft_strlen(map[(int)floorf(pos.y)
				- 1]) <= (int)(pos.x))
		return (NO);
	if (map[(int)floorf(pos.y) - 1][(int)(pos.x)] == '1')
		return (NO);
	if (map[(int)floorf(pos.y) - 1][(int)(pos.x)] == 'C')
		return (CLOSE);
	if (map[(int)floorf(pos.y) - 1][(int)(pos.x)] == 'O')
		return (OPEN);
	return (NONE);
}
