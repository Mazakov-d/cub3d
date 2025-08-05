/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:05:17 by dmazari           #+#    #+#             */
/*   Updated: 2025/08/05 17:20:17 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_CASTING_H
# define RAY_CASTING_H

# define PI 3.14159265358979323846
# define FOV 60
# define FOV_RAD (FOV * (PI / 180))

typedef struct s_vector {
	double	x_i;
	double	y_i;
}	t_vector;

typedef struct s_ray {

}	t_ray;


#endif