/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:05:17 by dmazari           #+#    #+#             */
/*   Updated: 2025/07/29 17:16:44 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CASTING_H
# define RAY_CASTING_H

typedef struct s_plane {
	double	camera_x;
	double	plane_x;
	double	plane_y;
}	t_plane;

typedef struct s_player {
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
}	t_player;

typedef struct s_ray {
	t_plane		plane;
	t_player	player;
	double		plane_lenght;
	double		ray_dir_x;
	double		ray_dir_y;
	double		dist_x;
	double		dist_y;
	double		side_y;
	double		side_x;
}	t_ray;

#endif