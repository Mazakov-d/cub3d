/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:55:18 by dmazari           #+#    #+#             */
/*   Updated: 2025/07/29 17:16:24 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ray_dir_calc(t_ray *ray, int i)
{
	ray->camera_x = (2 * i / WIN_SIZE_X) - 1;
	
}

void	init_ray(t_context *ctx)
{
	t_ray	ray;
	int		i;

	i = 0;
	ray.player.pos_x = 1;
	ray.player.pos_y = 2;
	ray.player.dir_x = -1;
	ray.player.dir_y = 0;
	ray.plane.plane_x = 0;
	ray.plane.plane_y = 0.66;
	while (i < WIN_SIZE_X)
	{
		ray_dir_cal(&ray, i);
	}
}