/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_str_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 19:28:30 by mniemaz           #+#    #+#             */
/*   Updated: 2025/07/28 19:28:49 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	ft_is_str_spaces(char *str)
{
	while (*str)
	{
		if (!ft_isspace(*str))
			return (false);
		str++;
	}
	return (true);
}