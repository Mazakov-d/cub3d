/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ends_with.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:28:39 by mniemaz           #+#    #+#             */
/*   Updated: 2025/07/28 15:28:58 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	ends_with(char *str, char *suffix)
{
	if (!str)
		return (false);
	size_t str_len = ft_strlen(str);
	size_t suffix_len = ft_strlen(suffix);

	if (suffix_len > str_len)
		return (false);

	return (ft_strncmp(str + str_len - suffix_len, suffix, suffix_len) == 0);
}