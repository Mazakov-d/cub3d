/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putendl_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:10:12 by nle-gued          #+#    #+#             */
/*   Updated: 2025/07/28 14:39:07 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	counter;

	counter = 0;
	if (!s)
		return (-2);
	counter += write(fd, s, ft_strlen(s));
	counter += write(fd, "\n", 1);
	if (counter < 0)
		return (-1);
	return (counter);
}
