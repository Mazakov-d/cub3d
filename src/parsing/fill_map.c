/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:12:36 by mniemaz           #+#    #+#             */
/*   Updated: 2025/08/28 18:42:27 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static bool	is_map_line_valid(char *line, bool *user_found)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (!is_char_in_str(line[i], MAP_CHARS))
		{
			printf_err("Invalid char '%c' in map line: '%s'\n", line[i], line);
			return (false);
		}
		if (is_char_in_str(line[i], USER_CHARS))
		{
			if (*user_found)
			{
				printf_err("Second user '%c' found in map line: '%s'\n",
					line[i], line);
				return (false);
			}
			*user_found = true;
		}
	}
	return (true);
}

static int	check_and_count_map_rows(t_line *line, int *nb_map_rows)
{
	t_line	*curr_line;
	int		nb_empty_lines;
	bool	user_found;

	user_found = false;
	nb_empty_lines = 0;
	curr_line = line;
	while (curr_line)
	{
		if (is_map_line_valid(curr_line->line, &user_found) == false)
			return (EXIT_FAILURE);
		if (ft_is_str_spaces(curr_line->line))
			nb_empty_lines++;
		else
		{
			*nb_map_rows += nb_empty_lines + 1;
			nb_empty_lines = 0;
		}
		if (ft_strlen(curr_line->line) > MAX_MAP_SIZE)
			return (printf_err("Map too big !\n"));
		curr_line = curr_line->next;
	}
	if (!user_found)
		return (printf_err("No user char found in the map\n"));
	return (EXIT_SUCCESS);
}

static char	**get_filled_map(int nb_map_rows, t_line *curr_line)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * (nb_map_rows + 1));
	if (!map)
	{
		printf_err("fill_map: %s\n", strerror(errno));
		return (NULL);
	}
	i = 0;
	while (i < nb_map_rows)
	{
		map[i] = ft_strdup(curr_line->line);
		if (!map[i])
		{
			printf_err("fill_map: %s\n", strerror(errno));
			free(map);
			return (NULL);
		}
		curr_line = curr_line->next;
		i++;
	}
	map[nb_map_rows] = NULL;
	return (map);
}

/**
 * @brief Fills the map in the ctx and checks if:
 * - the map contains valid characters
 */
int	fill_map(t_context *ctx, t_line *map_start_line)
{
	int	nb_map_rows;

	nb_map_rows = 0;
	if (check_and_count_map_rows(map_start_line, &nb_map_rows) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (nb_map_rows > MAX_MAP_SIZE)
		return (printf_err("Map too big !\n"));
	ctx->map = get_filled_map(nb_map_rows, map_start_line);
	if (!ctx->map)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
