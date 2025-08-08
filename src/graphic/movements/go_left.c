/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_left.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:33:35 by dmazari           #+#    #+#             */
/*   Updated: 2025/08/07 18:13:30 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"


void	go_left(t_player *player, char **map)
{
	float	i;
	float	j;


	j = player->pos.x + ((player->p_vec.y_i * SPEED));
	i = player->pos.y - ((player->p_vec.x_i * SPEED));
	if (map[(int)floorf(i)][(int)floorf(player->pos.x)] == '1')
		return ;
	if (map[(int)floorf(player->pos.y)][(int)floorf(j)] == '1')
		return ;
	if (map[(int)floorf(i)][(int)floorf(j)] == '1')
		return ;
	player->pos.x += player->p_vec.y_i * SPEED;
	player->pos.y -= player->p_vec.x_i * SPEED;
}
