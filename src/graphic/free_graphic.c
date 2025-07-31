/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:11:35 by dmazari           #+#    #+#             */
/*   Updated: 2025/07/31 00:13:18 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs && strs[i])
	{
		if (strs[i])
			free(strs[i]);
		i++;
	}
	free(strs);
}

int	free_graphic(t_context *context)
{
	if (context->mlx.win)
		mlx_destroy_window(context->mlx.mlx, context->mlx.win);
	// mlx_destroy_display(context->mlx.mlx);
	// on mac mlx_destroy_display is not available
	if (context->mlx.img)
		mlx_destroy_image(context->mlx.mlx, context->mlx.img);
	free(context->mlx.mlx);
	free_context(context);
	exit(0);
	return (0);
}