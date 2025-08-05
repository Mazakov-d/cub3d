/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_right.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:34:27 by dmazari           #+#    #+#             */
/*   Updated: 2025/08/05 13:39:05 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub.h"

void	go_right(t_player *player, char **map)
{
	float	i;
	float	j;

	j = player->pos.x - ((player->p_vec.y_i * SPEED));
	i = player->pos.y + ((player->p_vec.x_i * SPEED));
	if (map[(int)i][(int)j] == '1')
		return ;
	player->pos.x -= player->p_vec.y_i * SPEED;
	player->pos.y += player->p_vec.x_i * SPEED;
}
