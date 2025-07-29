/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:59:15 by mniemaz           #+#    #+#             */
/*   Updated: 2025/07/29 17:28:21 by mniemaz          ###   ########.fr       */
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
	{
		printf("Map OK\n");
	}

	free_context(&ctx);
	return (0);
}