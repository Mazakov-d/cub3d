/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_man.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:39:07 by mniemaz           #+#    #+#             */
/*   Updated: 2025/08/04 14:19:01 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"



/**
 * @brief Process one step of Bresenham algorithm for vector direction
 */
static void bresenham_step_vector(int *x, int *y, t_vector dir, int error_x, int error_y, int *err)
{
    int temp_err;

    temp_err = 2 * (*err);
    if (temp_err > -error_y)
    {
        *err -= error_y;
        if (dir.x_i >= 0)
            (*x)++;
        else
            (*x)--;
    }
    if (temp_err < error_x)
    {
        *err += error_x;
        if (dir.y_i >= 0)
            (*y)++;
        else
            (*y)--;
    }
}

/**
 * @brief Initialize Bresenham values for vector direction
 */
static void init_bresenham_vector(t_vector dir, int *error_x, int *error_y, int *err, double length)
{
    double norm = sqrt(dir.x_i * dir.x_i + dir.y_i * dir.y_i);
    if (norm == 0)
    {
        *error_x = 0;
        *error_y = 0;
        *err = 0;
        return;
    }
    *error_x = ft_int_abs((int)(dir.x_i / norm * length));
    *error_y = ft_int_abs((int)(dir.y_i / norm * length));
    *err = *error_x - *error_y;
}

/**
 * @brief Draw a ray from player position in given direction for 1500 pixels
 */
void ray_man(t_context *ctx, t_vector dir, double square_x, double square_y)
{
	(void) ctx;
	(void) dir;
    int x, y;
    int error_x, error_y;
    int err;
    int pixels_drawn;
    int color;
    const int MAX_PIXELS = 100;
	(void) square_x; // square_x not used in this function
	(void) square_y; // square_y not used in this function

    // Point de départ : position du joueur
    x = (int)ctx->player.pos.x;
    y = (int)ctx->player.pos.y;

    // Initialiser les valeurs pour Bresenham avec le vecteur directionnel
    init_bresenham_vector(dir, &error_x, &error_y, &err, 1000.0);

    color = 0xFFFFFF; // Rouge par défaut

    pixels_drawn = 0;
    while (pixels_drawn < MAX_PIXELS)
    {
        // Vérifier les limites de l'écran (adapter selon votre structure)
		mlx_pixel_put(ctx->mlx.img, ctx->mlx.win, x, y, color);

        // Faire un pas dans la direction du vecteur
        bresenham_step_vector(&x, &y, dir, error_x, error_y, &err);

        pixels_drawn++;
    }
}