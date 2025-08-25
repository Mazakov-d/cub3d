/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_left.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:33:35 by dmazari           #+#    #+#             */
/*   Updated: 2025/08/12 16:23:18 by mazakov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


void	go_left(t_player *player, char **map)
{
	float	i;
	float	j;


	j = player->pos.x + ((player->p_vec.y_i * SPEED));
	i = player->pos.y - ((player->p_vec.x_i * SPEED));
	if (map[(int)floorf(i)][(int)(player->pos.x)] == '1'
		|| map[(int)floorf(i)][(int)(player->pos.x)] == 'C')
		return ;
	if (map[(int)floorf(player->pos.y)][(int)floorf(j)] == '1'
		|| map[(int)floorf(player->pos.y)][(int)floorf(j)] == 'C')
		return ;
	if (map[(int)floor(i)][(int)floorf(j)] == '1'
		|| map[(int)floorf(i)][(int)floorf(j)] == 'C')
		return ;
	player->pos.x += player->p_vec.y_i * SPEED;
	player->pos.y -= player->p_vec.x_i * SPEED;
}
