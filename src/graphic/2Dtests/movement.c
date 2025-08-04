/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:33:45 by dmazari           #+#    #+#             */
/*   Updated: 2025/08/04 14:13:17 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	go_forward_backward(t_player *player, char **map, char flag)
{
	float	i;
	float	j;

	if (flag == 'W')
	{
		j = player->pos_x + (player->p_vec.x_i * SPEED);
		i = player->pos_y + (player->p_vec.y_i * SPEED);
		if (map[(int)i][(int)j] == '1')
			return ;
		player->pos_x += player->p_vec.x_i * SPEED;
		player->pos_y += player->p_vec.y_i * SPEED;
	}
	else
	{
		j = player->pos_x - (player->p_vec.x_i * SPEED);
		i = player->pos_y - (player->p_vec.y_i * SPEED);
		if (map[(int)i][(int)j] == '1')
			return ;
		player->pos_x -= player->p_vec.x_i * SPEED;
		player->pos_y -= player->p_vec.y_i * SPEED;
	}
}

void	go_left_right(t_player *player, char **map, char flag)
{
	float	i;
	float	j;

	if (flag == 'A')
	{
		j = player->pos_x - cos((player->p_vec.x_i * SPEED));
		i = player->pos_y + sin((player->p_vec.y_i * SPEED));
		if (map[(int)i][(int)j] == '1')
			return ;
		player->pos_x -= player->p_vec.x_i * SPEED;
		player->pos_y += player->p_vec.y_i * SPEED;
	}
	else
	{
		j = player->pos_x + sin((player->p_vec.x_i * SPEED));
		i = player->pos_y - cos((player->p_vec.y_i * SPEED));
		if (map[(int)i][(int)j] == '1')
			return ;
		player->pos_x += player->p_vec.x_i * SPEED;
		player->pos_y -= player->p_vec.y_i * SPEED;
	}
}

void	turn_right(void)
{
	return ;
}

void	turn_left(void)
{
	return ;
}