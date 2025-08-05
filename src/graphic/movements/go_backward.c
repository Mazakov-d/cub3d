/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_backward.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:33:07 by dmazari           #+#    #+#             */
/*   Updated: 2025/08/05 13:35:48 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	go_backward(t_player *player, char **map)
{
	float	i;
	float	j;

	j = player->pos.x - (player->p_vec.x_i * SPEED);
	i = player->pos.y - (player->p_vec.y_i * SPEED);
	if (map[(int)i][(int)j] == '1')
		return ;
	player->pos.x -= player->p_vec.x_i * SPEED;
	player->pos.y -= player->p_vec.y_i * SPEED;
}
