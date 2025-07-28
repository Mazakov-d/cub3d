/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_nl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 18:08:30 by mniemaz           #+#    #+#             */
/*   Updated: 2025/07/28 18:10:36 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @brief Sets the first newline character in the string to null terminator.
 */
char	*rm_nl(char *str)
{
    int	i;

    if (!str)
        return (NULL);
    i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
        {
            str[i] = '\0';
            break ;
        }
        i++;
    }
    return (str);
}