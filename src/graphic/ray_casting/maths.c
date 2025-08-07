/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:39:07 by mniemaz           #+#    #+#             */
/*   Updated: 2025/08/07 10:35:01 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * modf takes a double and returns the fractional part of it
 */
int	is_rounded(double x)
{
	double	int_part;
	double	frac_part;

	frac_part = modf(x, &int_part);
	return (frac_part == 0.0);
}

bool is_almost_rounded(double n)
{
    double nearest_int = round(n);
    double distance = fabs(n - nearest_int);

    return distance < 0.0001;
}

double	ft_min(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}

/**
 * t is the minimum number of times pos has to travel v to get to an edge of a
 * square (1,1)
 * @returns the least t because it means it is the closest to an edge
 */
double	get_t(t_point pos, t_vector v)
{
	double	t;
	double	tmp;

	t = DBL_MAX;
	if (v.x_i > 0)
	{
		tmp = (1 - pos.x) / v.x_i;
		t = ft_min(t, tmp);
	}
	else if (v.x_i < 0)
	{
		tmp = -pos.x / v.x_i;
		t = ft_min(t, tmp);
	}
	if (v.y_i > 0)
	{
		tmp = (1 - pos.y) / v.y_i;
		t = ft_min(t, tmp);
	}
	else if (v.y_i < 0)
	{
		tmp = -pos.y / v.y_i;
		t = ft_min(t, tmp);
	}
	return (t);
}

/**
 * @returns the intersection pos of the edge of a square (1,1) and
 * a line starting at p, going in direction dir
 * pos_in_square_1 is the position of p in the square (1,1)
 */
t_point	get_intersection_pos(t_point p, t_vector dir)
{
	t_point	pos_in_square_1;
	int		floor_p_x;
	int		floor_p_y;
	double	t;
	t_point	res;

	// edge cases
	if (dir.x_i < 0 && is_rounded(p.x))
		p.x -= 0.0001;
	if (dir.y_i < 0 && is_rounded(p.y))
		p.y -= 0.0001;
	if (dir.x_i > 0 && is_rounded(p.x))
		p.x += 0.0001;
	if (dir.y_i > 0 && is_rounded(p.y))
		p.y += 0.0001;
	floor_p_x = floor(p.x);
	floor_p_y = floor(p.y);
	pos_in_square_1.x = p.x - floor_p_x;
	pos_in_square_1.y = p.y - floor_p_y;
	t = get_t(pos_in_square_1, dir);
	res.x = (pos_in_square_1.x + dir.x_i * t) + floor_p_x;
	res.y = (pos_in_square_1.y + dir.y_i * t) + floor_p_y;
	return (res);
}

/**
 * todo what if both are rounded (corner)
 * @returns true if pos is stuck on a wall (or a non allocated) in the
 * direction of dir
 * "stuck on a wall" means it is at the edge of a square, and the next square
 * in the direction of dir is a wall (or not allocated)
 */
t_cardinal_dir	stuck_on_wall_dir(char **map, t_point pos, t_vector dir)
{
	if (is_almost_rounded(pos.x) && dir.x_i > 0)
	{
		if (map[(int)(pos.y)][(int)floorf(pos.x)]
			&& map[(int)(pos.y)][(int)floorf(pos.x)] == '1')
			return (EA);
	}
	if (is_almost_rounded(pos.x) && dir.x_i < 0)
	{
		if (pos.x == 0.0f)
			return (WE);
		if (map[(int)(pos.y)][(int)floorf(pos.x) - 1]
			&& map[(int)(pos.y)][(int)floorf(pos.x) - 1] == '1')
			return (WE);
	}
	if (is_almost_rounded(pos.y) && dir.y_i > 0)
	{
		if (!map[(int)floorf(pos.y) + 1] || ft_strlen(map[(int)floorf(pos.y) + 1]) <= (int)(pos.x))
			return (SO);
		if (map[(int)floorf(pos.y)][(int)(pos.x)] == '1')
			return (SO);
	}
	if (is_almost_rounded(pos.y) && dir.y_i < 0)
	{
		if ((int)floorf(pos.y) == 0 || ft_strlen(map[(int)floorf(pos.y) - 1]) <= (int)(pos.x))
			return (NO);
		if (map[(int)floorf(pos.y) - 1][(int)(pos.x)] == '1')
			return (NO);
	}
	return (NONE);
}

t_point_dir	get_impact_wall_toward(t_context *ctx, t_vector vec)
{
	t_point_dir	impact;
	impact.pos = ctx->player.pos;

	impact.dir = stuck_on_wall_dir(ctx->map, impact.pos, vec);
	while (impact.dir == NONE)
	{
		impact.pos = get_intersection_pos(impact.pos, vec);
		impact.dir = stuck_on_wall_dir(ctx->map, impact.pos, vec);
	}
	return (impact);
}