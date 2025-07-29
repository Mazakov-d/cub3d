/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_graphic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 16:11:35 by dmazari           #+#    #+#             */
/*   Updated: 2025/07/28 17:37:03 by dmazari          ###   ########.fr       */
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
	mlx_destroy_display(context->mlx.mlx);
	free(context->mlx.mlx);
	exit(0);
	return (0);
}