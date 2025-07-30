/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:44:45 by mniemaz           #+#    #+#             */
/*   Updated: 2025/07/30 09:38:27 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>

int	ft_atoi_color(const char *nptr, int *error)
{
	int				i;
	unsigned int	res;

	i = 0;
	res = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i++] - '0';
		if (res > 255)
		{
			*error = 1;
			return (-1);
		}
	}
	if (nptr[i] != '\0')
	{
		*error = 1;
		return (-1);
	}
	return (res);
}
