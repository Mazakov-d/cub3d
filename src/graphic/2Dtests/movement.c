/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 11:33:45 by dmazari           #+#    #+#             */
/*   Updated: 2025/08/04 15:56:14 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	go_forward_backward(t_player *player, char **map, char flag)
{
	float	i;
	float	j;

	if (flag == 'W')
	{
		j = player->pos.x + (player->p_vec.x_i * SPEED);
		i = player->pos.y + (player->p_vec.y_i * SPEED);
		if (map[(int)i][(int)j] == '1')
			return ;
		player->pos.x += player->p_vec.x_i * SPEED;
		player->pos.y += player->p_vec.y_i * SPEED;
	}
	else
	{
		j = player->pos.x - (player->p_vec.x_i * SPEED);
		i = player->pos.y - (player->p_vec.y_i * SPEED);
		if (map[(int)i][(int)j] == '1')
			return ;
		player->pos.x -= player->p_vec.x_i * SPEED;
		player->pos.y -= player->p_vec.y_i * SPEED;
	}
}

void	go_left_right(t_player *player, char **map, char flag)
{
	float	i;
	float	j;

	if (flag == 'A')
	{
		j = player->pos.x + ((player->p_vec.y_i * SPEED));
		i = player->pos.y - ((player->p_vec.x_i * SPEED));
		if (map[(int)i][(int)j] == '1')
			return ;
		player->pos.x += player->p_vec.y_i * SPEED;
		player->pos.y -= player->p_vec.x_i * SPEED;
	}
	else
	{
		j = player->pos.x - ((player->p_vec.y_i * SPEED));
		i = player->pos.y + ((player->p_vec.x_i * SPEED));
		if (map[(int)i][(int)j] == '1')
			return ;
		player->pos.x -= player->p_vec.y_i * SPEED;
		player->pos.y += player->p_vec.x_i * SPEED;
	}
}

void turn_right(t_context *ctx)
{
	double	old_x;

	old_x = ctx->player.p_vec.x_i;
	ctx->player.p_vec.x_i = ctx->player.p_vec.x_i * cos(TURN_SPEED)
		- ctx->player.p_vec.y_i * sin(TURN_SPEED);
	ctx->player.p_vec.y_i = old_x * sin(TURN_SPEED)
		+ ctx->player.p_vec.y_i * cos(TURN_SPEED);
	ctx->player.p_vec.length = sqrt(ctx->player.p_vec.x_i * ctx->player.p_vec.x_i
			+ ctx->player.p_vec.y_i * ctx->player.p_vec.y_i);
	// if (ctx->player.p_vec.length != 0)
	// {
	// 	ctx->player.p_vec.x_i /= ctx->player.p_vec.length;
	// 	ctx->player.p_vec.y_i /= ctx->player.p_vec.length;
	// }
}

void turn_left(t_context *ctx)
{
	double	old_x;

	old_x = ctx->player.p_vec.x_i;
	ctx->player.p_vec.x_i = ctx->player.p_vec.x_i * cos(-TURN_SPEED)
		- ctx->player.p_vec.y_i * sin(-TURN_SPEED);
	ctx->player.p_vec.y_i = old_x * sin(-TURN_SPEED)
		+ ctx->player.p_vec.y_i * cos(-TURN_SPEED);
	ctx->player.p_vec.length = sqrt(ctx->player.p_vec.x_i * ctx->player.p_vec.x_i
			+ ctx->player.p_vec.y_i * ctx->player.p_vec.y_i);
	// if (ctx->player.p_vec.length != 0)
	// {
	// 	ctx->player.p_vec.x_i /= ctx->player.p_vec.length;
	// 	ctx->player.p_vec.y_i /= ctx->player.p_vec.length;
	// }
}