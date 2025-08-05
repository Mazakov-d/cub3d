/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:34:53 by dmazari           #+#    #+#             */
/*   Updated: 2025/08/05 13:35:33 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void turn_left(t_context *ctx)
{
	double	old_x;

	old_x = ctx->player.p_vec.x_i;
	ctx->player.p_vec.x_i = ctx->player.p_vec.x_i * cos(-TURN_SPEED)
		- ctx->player.p_vec.y_i * sin(-TURN_SPEED);
	ctx->player.p_vec.y_i = old_x * sin(-TURN_SPEED)
		+ ctx->player.p_vec.y_i * cos(-TURN_SPEED);
}
