/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_texture_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:10:42 by mniemaz           #+#    #+#             */
/*   Updated: 2025/07/29 17:05:32 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @returns EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
static int	fill_color(t_color *color, char *id, char *str_colors)
{
	char	**color_values;
	int		error;

	if (!str_colors)
		return (printf_err("Missing color for %s\n", id));
	color_values = ft_split(str_colors, ",");
	if (!color_values)
		return (printf_err("fill_color: %s\n", strerror(errno)));
	if (!color_values[0] || !color_values[1] || !color_values[2])
	{
		free(color_values);
		return (printf_err("Invalid color: '%s'\n", str_colors));
	}
	color->r = (unsigned char)ft_atoi_color(color_values[0], &error);
	color->g = (unsigned char)ft_atoi_color(color_values[1], &error);
	color->b = (unsigned char)ft_atoi_color(color_values[2], &error);
	ft_free_tab((void **)color_values);
	if (error)
		return (printf_err("Invalid color: '%s'\n", str_colors));
	color->rgba = (color->r << 16) | (color->g << 8) | color->b;
	return (EXIT_SUCCESS);
}

bool	is_texture_data_filled(t_texture_data *tex_data)
{
	return (tex_data->north && tex_data->south && tex_data->east
		&& tex_data->west && tex_data->floor && tex_data->ceiling
		&& tex_data->floor->r != (unsigned char)COLOR_INIT_VAL
		&& tex_data->ceiling->r != (unsigned char)COLOR_INIT_VAL);
}

/**
 * @returns EXIT_SUCCESS if a direction was filled, EXIT_FAILURE on error,
 * EXIT_NEUTRAL if nothing happened.
 */
static int	fill_directions(t_texture_data *tex_data, char **lines_tab)
{
	char	*dirs[] = {"NO", "SO", "WE", "EA"};
	char	**to_fill[] = {&tex_data->north, &tex_data->south, &tex_data->west,
			&tex_data->east};
	int		i;

	i = -1;
	while (++i < 4)
	{
		if (ft_strncmp(lines_tab[0], dirs[i], 3) == 0)
		{
			if (!lines_tab[1])
				return (printf_err("No texture for: %s\n", dirs[i]));
			*to_fill[i] = ft_strdup(lines_tab[1]);
			if (!*to_fill[i])
				return (printf_err("fill_dirs: %s\n", strerror(errno)));
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_NEUTRAL);
}

/**
 * @returns EXIT_FAILURE on error
 */
static int	process_line_fill_texture_data(t_texture_data *tex_data,
		char **lines_tab, char *str_line)
{
	int	fill_dirs_ret;

	if (!lines_tab[0])
		return (EXIT_SUCCESS);
	if (ft_tablen((void **)lines_tab) > 2)
		return (printf_err("Too many args: '%s'\n", str_line));
	fill_dirs_ret = fill_directions(tex_data, lines_tab);
	if (fill_dirs_ret == EXIT_FAILURE || fill_dirs_ret == EXIT_SUCCESS)
		return (fill_dirs_ret);
	if (ft_strncmp(lines_tab[0], "F", 2) == 0)
		return (fill_color(tex_data->floor, lines_tab[0], lines_tab[1]));
	else if (ft_strncmp(lines_tab[0], "C", 2) == 0)
		return (fill_color(tex_data->ceiling, lines_tab[0], lines_tab[1]));
	else
		return (printf_err("Unknown identifier: '%s'\n", lines_tab[0]));
	return (EXIT_SUCCESS);
}

static t_line	*get_start_of_map(t_line *line)
{
	t_line	*curr_line;

	curr_line = line;
	while (curr_line && ft_is_str_spaces(curr_line->line))
		curr_line = curr_line->next;
	return (curr_line);
}

/**
 * @returns a pointer to the line of the chained list where the map starts,
 */
t_line	*fill_texture_data(t_line **head_file_line, t_texture_data *tex_data)
{
	t_line	*curr_line;
	char	**lines_tab;

	curr_line = *head_file_line;
	while (curr_line && !is_texture_data_filled(tex_data))
	{
		lines_tab = ft_split(curr_line->line, " ");
		if (!lines_tab)
		{
			printf_err("fill_texture_data: %s\n", strerror(errno));
			return (NULL);
		}
		if (process_line_fill_texture_data(tex_data, lines_tab,
				curr_line->line) == EXIT_FAILURE)
		{
			ft_free_tab((void **)lines_tab);
			return (NULL);
		}
		ft_free_tab((void **)lines_tab);
		curr_line = curr_line->next;
	}
	curr_line = get_start_of_map(curr_line);
	if (curr_line == NULL)
		printf_err("No map provided\n");
	return (curr_line);
}
