/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_forward.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:32:28 by dmazari           #+#    #+#             */
/*   Updated: 2025/08/07 11:55:34 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	go_forward(t_player *player, char **map)
{
	float	i;
	float	j;

	j = player->pos.x + (player->p_vec.x_i * SPEED);
	i = player->pos.y + (player->p_vec.y_i * SPEED);
	if (map[(int)floorf(i)][(int)floorf(j)] != '1')
	{
		player->pos.x += player->p_vec.x_i * SPEED;
		player->pos.y += player->p_vec.y_i * SPEED;
	}
}
