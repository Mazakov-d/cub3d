/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:59:15 by mniemaz           #+#    #+#             */
/*   Updated: 2025/08/05 14:38:40 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **av)
{
	t_context ctx;
	if (ac != 2)
		return (printf_err("Usage: %s <map_file>\n", av[0]));
	if (init_context(&ctx) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (parse_file(&ctx, av[1]) == EXIT_SUCCESS)
		init_graphic(&ctx);
	free_context(&ctx);
	return (0);
}