/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:39:07 by mniemaz          #+#    #+#             */
/*   Updated: 2025/08/04 11:40:11 by mniemaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @brief Process the Bresenham calculation (used in bresenham algorithm)
 */
static int process_bresenham_calc(t_point *from, t_point to, t_point d, int err)
{
    int temp_err;

    temp_err = 2 * err;
    if (temp_err > -d.y)
    {
        err -= d.y;
        if (from->x < to.x)
            from->x++;
        else
            from->x--;
    }
    if (temp_err < d.x)
    {
        err += d.x;
        if (from->y < to.y)
            from->y++;
        else
            from->y--;
    }
    return (err);
}

static void init_err_and_d(t_point from, t_point to, t_point *d, int *err)
{
    d->x = ft_double_abs((to.x - from.x));
    d->y = ft_double_abs((to.y - from.y));
    *err = d->x - d->y;
}

/**
 * @returns the number of pixels that would be drawn by the
 * Bresenham algorithm for a given line
 */
int bresenham_line_counter(t_point from, t_point to)
{
    t_point d;
    int err;
    int counter;
    t_point cur;

    counter = 0;
    cur = from;
    init_err_and_d(from, to, &d, &err);
    while (1)
    {
        counter++;
        if (cur.x == to.x && cur.y == to.y)
            break ;
        err = process_bresenham_calc(&cur, to, d, err);
    }
    return (counter);
}

/**
 * @brief Draw a line between two cells of the map using the Bresenham algorithm
 */
void bresenham_line(t_context *ctx, t_point_dir to, int unused)
{
    t_point d;
    int err;
    int i;
    t_int_pos from_pxl;
    t_int_pos to_pxl;
    t_point cur;
    (void)unused;

    from_pxl.x = ctx->player.pos.x * ctx->w_square_2d;
    from_pxl.y = ctx->player.pos.y * ctx->h_square_2d;
    to_pxl.x = to.pos.x * ctx->w_square_2d;
    to_pxl.y = to.pos.y * ctx->h_square_2d;

    cur.x = from_pxl.x;
    cur.y = from_pxl.y;
    
    d.x = ft_double_abs((double)(to_pxl.x - from_pxl.x));
    d.y = ft_double_abs((double)(to_pxl.y - from_pxl.y));
    err = d.x - d.y;
    
    i = 0;
    while (1)
    {
        put_pixel(ctx, (int)cur.x + 10, (int)cur.y + 10, 0xFFFFFF);

        if ((int)cur.x == to_pxl.x && (int)cur.y == to_pxl.y)
            break ;
        
        err = process_bresenham_calc(&cur, (t_point){to_pxl.x, to_pxl.y}, d, err);
        i++;
    }
}