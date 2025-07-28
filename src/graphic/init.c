/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:32:17 by dmazari           #+#    #+#             */
/*   Updated: 2025/07/28 15:43:41 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void init_graphic(t_context *context)
{
	context->mlx.mlx = mlx_init();
	context->mlx.win = mlx_new_window(context->mlx.mlx, WIN_SIZE_X, WIN_SIZE_Y
			, "Dodo c'est le meilleur");
	mlx_loop(context->mlx.mlx);
}