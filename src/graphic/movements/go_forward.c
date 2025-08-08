/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_forward.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 13:32:28 by dmazari           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/08/07 18:13:29 by mniemaz          ###   ########.fr       */
=======
/*   Updated: 2025/08/07 17:45:54 by dmazari          ###   ########.fr       */
>>>>>>> e56fd1131c87c0f6056053606f4c2bf4c6d51bd9
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	go_forward(t_player *player, char **map)
{
	float	i;
	float	j;

	j = player->pos.x + (player->p_vec.x_i * SPEED);
	i = player->pos.y + (player->p_vec.y_i * SPEED);
	if (map[(int)floorf(i)][(int)floorf(player->pos.x)] == '1')
		return ;
	if (map[(int)floorf(player->pos.y)][(int)floorf(j)] == '1')
		return ;
	if (map[(int)floorf(i)][(int)floorf(j)] == '1')
		return ;
	player->pos.x += player->p_vec.x_i * SPEED;
	player->pos.y += player->p_vec.y_i * SPEED;
}
