/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_backward.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:33:07 by dmazari           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/08/07 18:13:25 by mniemaz          ###   ########.fr       */
=======
/*   Updated: 2025/08/07 18:03:27 by dmazari          ###   ########.fr       */
>>>>>>> e56fd1131c87c0f6056053606f4c2bf4c6d51bd9
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	go_backward(t_player *player, char **map)
{
	float	i;
	float	j;

	j = player->pos.x - (player->p_vec.x_i * SPEED);
	i = player->pos.y - (player->p_vec.y_i * SPEED);
	if (map[(int)floorf(i)][(int)(player->pos.x)] == '1')
		return ;
	if (map[(int)floorf(player->pos.y)][(int)floorf(j)] == '1')
		return ;
	if (map[(int)floor(i)][(int)floorf(j)] == '1')
		return ;
	player->pos.x -= player->p_vec.x_i * SPEED;
	player->pos.y -= player->p_vec.y_i * SPEED;
}
