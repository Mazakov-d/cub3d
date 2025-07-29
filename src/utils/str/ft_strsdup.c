/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:14:04 by mniemaz           #+#    #+#             */
/*   Updated: 2025/07/29 17:14:29 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	**ft_strsdup(char **src)
{
    char	**dup;
    int		i;

    if (!src)
        return (NULL);
    i = 0;
    while (src[i])
        i++;
    dup = malloc(sizeof(char *) * (i + 1));
    if (!dup)
        return (NULL);
    i = 0;
    while (src[i])
    {
        dup[i] = ft_strdup(src[i]);
        if (!dup[i])
        {
            ft_free_tab((void **)dup);
            return (NULL);
        }
        i++;
    }
    dup[i] = NULL;
    return (dup);
}