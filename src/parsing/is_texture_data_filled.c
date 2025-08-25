/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_texture_data_filled.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:52:32 by mniemaz           #+#    #+#             */
/*   Updated: 2025/08/25 11:56:10 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	is_texture_data_filled(t_texture_data *tex_data)
{
	return (tex_data->walls[NO].img_name && tex_data->walls[SO].img_name
		&& tex_data->walls[EA].img_name && tex_data->walls[WE].img_name
		&& tex_data->walls[CLOSE].img_name
		&& tex_data->floor_hexa != HEXA_INIT_VAL
		&& tex_data->ceiling_hexa != HEXA_INIT_VAL);
}
