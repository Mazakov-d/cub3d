/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:11:35 by dmazari           #+#    #+#             */
/*   Updated: 2025/08/12 06:27:13 by miloniemaz       ###   ########.fr       */
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
	if (context->texture_data.east.img_ptr)
		free(context->texture_data.east.img_ptr);
	if (context->texture_data.north.img_ptr)
		free(context->texture_data.north.img_ptr);
	if (context->texture_data.west.img_ptr)
		free(context->texture_data.west.img_ptr);
	if (context->texture_data.south.img_ptr)
		free(context->texture_data.south.img_ptr);
	if (context->mlx->img.img_ptr)
		mlx_destroy_image(context->mlx->mlx_ptr, context->mlx->img.img_ptr);
	if (context->mlx->win_ptr)
		mlx_destroy_window(context->mlx->mlx_ptr, context->mlx->win_ptr);
	// mlx_destroy_display(context->mlx->mlx_ptr);
	free(context->mlx->mlx_ptr);
	free_context(context);
	exit(0);
	return (0);
}
