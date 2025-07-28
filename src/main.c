/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 13:59:15 by mniemaz           #+#    #+#             */
/*   Updated: 2025/07/28 16:24:36 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int main(int ac, char **av)
{
    t_context ctx;
    if (ac != 2)
    {
        ft_dprintf(STDERR_FILENO, "Usage: %s <map_file>\n", av[0]);
        return (1);
    }
    parse_file(&ctx, av[1]);
    return (0);
}