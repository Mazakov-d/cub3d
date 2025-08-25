/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_almost_rounded.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:04:22 by mniemaz           #+#    #+#             */
/*   Updated: 2025/08/25 12:24:10 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	is_almost_rounded(double n)
{
	double	fract_part;

	fract_part = (double)n - (int)n;
	return (fract_part < 0.0001 || fract_part > 0.9999);
}
