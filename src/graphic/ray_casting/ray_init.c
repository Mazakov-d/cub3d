/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:55:18 by dmazari           #+#    #+#             */
/*   Updated: 2025/07/29 17:35:20 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ray_dir_calc(t_ray *ray, int i)
{
	ray->camera_x = (2 * i / (double)WIN_SIZE_X) - 1;
	ray->ray_dir_x = ray->player.dir_x + ray->plane.plane_x * ray->camera_x;
	ray->ray_dir_y = ray->player.dir_y + ray->plane.plane_y * ray->camera_x;
}

void	init_ray(t_context *ctx)
{
	t_ray	ray;
	int		i;
	(void)ctx;

	i = 0;
	ray.player.pos_x = 1;
	ray.player.pos_y = 2;
	ray.player.dir_x = -1;
	ray.player.dir_y = 0;
	ray.plane.plane_x = -ray.player.dir_y * tan(FOV / 2);
	ray.plane.plane_y = ray.player.dir_x * tan(FOV / 2);
	while (i < WIN_SIZE_X)
	{
		ray_dir_calc(&ray, i);
		printf("[%d]  ray_dir_x :%f\nray_dir_y: %f\n", i, ray.ray_dir_x, ray.ray_dir_y);
		i++;
	}
}