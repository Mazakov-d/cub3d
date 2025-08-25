/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:39:07 by mniemaz           #+#    #+#             */
/*   Updated: 2025/08/25 13:23:44 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * t is the minimum number of times pos has to travel v to get to an edge of a
 * square (1,1)
 * @returns the least t because it means it is the closest to an edge
 */
double	get_t(t_point pos, t_vector vec)
{
	double	t;
	double	tmp;

	t = DBL_MAX;
	if (vec.x_i > 0)
	{
		tmp = (1 - pos.x) / vec.x_i;
		t = ft_min(t, tmp);
	}
	else if (vec.x_i < 0)
	{
		tmp = -pos.x / vec.x_i;
		t = ft_min(t, tmp);
	}
	if (vec.y_i > 0)
	{
		tmp = (1 - pos.y) / vec.y_i;
		t = ft_min(t, tmp);
	}
	else if (vec.y_i < 0)
	{
		tmp = -pos.y / vec.y_i;
		t = ft_min(t, tmp);
	}
	return (t);
}

/**
 * @returns the intersection pos of the edge of a square (1,1) and
 * a line starting at p, going in direction dir
 * pos_in_square_1 is the position of p in the square (1,1)
 */
t_point	get_intersection_pos(t_point p, t_vector vec)
{
	t_point	pos_in_square_1;
	int		floor_p_x;
	int		floor_p_y;
	double	t;
	t_point	res;

	floor_p_x = (int)(p.x);
	floor_p_y = (int)(p.y);
	pos_in_square_1.x = p.x - floor_p_x;
	pos_in_square_1.y = p.y - floor_p_y;
	t = get_t(pos_in_square_1, vec);
	res.x = (pos_in_square_1.x + vec.x_i * t) + floor_p_x;
	res.y = (pos_in_square_1.y + vec.y_i * t) + floor_p_y;
	return (res);
}

/**
 * todo what if both are rounded (corner)
 * @returns true if pos is stuck on a wall (or a non allocated) in the
 * direction of dir
 * "stuck on a wall" means it is at the edge of a square, and the next square
 * in the direction of dir is a wall (or not allocated)
 */
t_wall_type	stuck_on_wall_dir(char **map, t_point pos, t_vector vec)
{
	if (is_almost_rounded(pos.y) && vec.y_i < 0)
	{
		return (check_north_wall(pos, map));
	}
	if (is_almost_rounded(pos.y) && vec.y_i > 0)
	{
		return (check_south_wall(pos, map));
	}
	if (is_almost_rounded(pos.x) && vec.x_i > 0)
	{
		return (check_east_wall(pos, map));
	}
	if (is_almost_rounded(pos.x) && vec.x_i < 0)
	{
		return (check_west_wall(pos, map));
	}
	return (NONE);
}

t_impact	get_impact_wall_toward(t_context *ctx, t_vector vec)
{
	t_impact	impact;

	impact.pos = ctx->player.pos;
	impact.wall_type = stuck_on_wall_dir(ctx->map, impact.pos, vec);
	while (impact.wall_type == NONE || impact.wall_type == OPEN)
	{
		impact.pos = get_intersection_pos(impact.pos, vec);
		impact.wall_type = stuck_on_wall_dir(ctx->map, impact.pos, vec);
		if (impact.wall_type == NONE || impact.wall_type == OPEN)
		{
			if (vec.x_i < 0 && is_rounded(impact.pos.x))
				impact.pos.x -= 0.0001;
			if (vec.y_i < 0 && is_rounded(impact.pos.y))
				impact.pos.y -= 0.0001;
			if (vec.x_i > 0 && is_rounded(impact.pos.x))
				impact.pos.x += 0.0001;
			if (vec.y_i > 0 && is_rounded(impact.pos.y))
				impact.pos.y += 0.0001;
		}
	}
	return (impact);
}
