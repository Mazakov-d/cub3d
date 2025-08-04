/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:39:07 by mniemaz           #+#    #+#             */
/*   Updated: 2025/08/04 18:23:15 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * modf takes a double and returns the fractional part of it
 */
int is_rounded(double x)
{
    return (fabs(x - round(x)) < 0.0001);

}

double ft_min(double a, double b)
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
double get_t(t_pos pos, t_vector v)
{
    double t;
    double tmp;

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
t_pos   get_intersection_pos(t_pos p, t_vector dir)
{
    t_pos pos_in_square_1;

    // edge cases
    if (dir.x_i < 0 && is_rounded(p.x))
        p.x -= 0.0001;
    if (dir.y_i < 0 && is_rounded(p.y))
        p.y -= 0.0001;
    if (dir.x_i > 0 && is_rounded(p.x))
        p.x += 0.0001;
    if (dir.y_i > 0 && is_rounded(p.y))
        p.y += 0.0001;
    int floor_p_x = floor(p.x);
    int floor_p_y = floor(p.y);

    pos_in_square_1.x = p.x - floor_p_x;
    pos_in_square_1.y = p.y - floor_p_y;
    double t = get_t(pos_in_square_1, dir);
    t_pos res;

    res.x = (pos_in_square_1.x + dir.x_i * t) + floor_p_x;
    res.y = (pos_in_square_1.y + dir.y_i * t) + floor_p_y;

    return (res);
}

/**
 * todo what if both are rounded (corner)
 * @returns true if pos is stuck on a wall (or a non allocated) in the direction of dir
 * "stuck on a wall" means it is at the edge of a square, and the next square in the
 * direction of dir is a wall (or not allocated)
 */
bool is_stuck_on_wall(char **map, t_pos pos, t_vector dir)
{
    if (is_rounded(pos.x) && dir.x_i > 0)
    {
        if (map[(int)floor(pos.y)][(int)pos.x]
            && map[(int)floor(pos.y)][(int)pos.x] == '1')
        return (true);
    }
    if (is_rounded(pos.x) && dir.x_i < 0)
    {
        if (pos.x == 0.0f)
            return true;
        if (map[(int)floor(pos.y)][(int)pos.x - 1]
        && map[(int)floor(pos.y)][(int)pos.x - 1] == '1')
            return (true);
    }
    if (is_rounded(pos.y) && dir.y_i > 0)
    {
        if (!map[(int)pos.y + 1]
            || ft_strlen(map[(int)pos.y + 1]) <= (int)floor(pos.x))
            return true;
        if (map[(int)pos.y][(int)floor(pos.x)] == '1')
            return (true);
    }
    if (is_rounded(pos.y) && dir.y_i < 0)
    {
        if (pos.y == 0.0f
            || ft_strlen(map[(int)pos.y - 1]) <= (int)floor(pos.x))
            return true;
        if (map[(int)pos.y - 1][(int)floor(pos.x)] == '1')
            return (true);
    }
    return (false);
}

t_pos   get_pos_wall_toward(t_context *ctx, t_vector dir)
{
    t_pos inters;

    inters = ctx->player.pos;

    while (!is_stuck_on_wall(ctx->map, inters, dir))
    {
        inters = get_intersection_pos(inters, dir);
    }
    return inters;
}