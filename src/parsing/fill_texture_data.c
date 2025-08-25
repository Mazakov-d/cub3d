/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_texture_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:10:42 by mniemaz           #+#    #+#             */
/*   Updated: 2025/08/25 12:05:16 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * @returns EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
static int	fill_color(unsigned long *hexa, char *id, char *str_colors)
{
	char	**color_values;
	int		color_error;
	t_color	c;

	if (!str_colors)
		return (printf_err("Missing color for %s\n", id));
	color_values = ft_split(str_colors, ",");
	if (!color_values)
		return (printf_err("fill_color: %s\n", strerror(errno)));
	if (!color_values[0] || !color_values[1] || !color_values[2]
		|| ft_tablen((void **)color_values) != 3)
	{
		ft_free_tab((void **)color_values);
		return (printf_err("Invalid color: '%s'\n", str_colors));
	}
	color_error = 0;
	c.r = (unsigned char)ft_atoi_color(color_values[0], &color_error);
	c.g = (unsigned char)ft_atoi_color(color_values[1], &color_error);
	c.b = (unsigned char)ft_atoi_color(color_values[2], &color_error);
	ft_free_tab((void **)color_values);
	if (color_error)
		return (printf_err("Invalid color: '%s'\n", str_colors));
	*hexa = (c.r << 16) | (c.g << 8) | c.b;
	return (EXIT_SUCCESS);
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
	fill_dirs_ret = fill_wall_types(tex_data, lines_tab);
	if (fill_dirs_ret == EXIT_FAILURE || fill_dirs_ret == EXIT_SUCCESS)
		return (fill_dirs_ret);
	if (ft_strncmp(lines_tab[0], "F", 2) == 0)
		return (fill_color(&tex_data->floor_hexa, lines_tab[0], lines_tab[1]));
	else if (ft_strncmp(lines_tab[0], "C", 2) == 0)
		return (fill_color(&tex_data->ceiling_hexa, lines_tab[0],
				lines_tab[1]));
	else
		return (printf_err("Unknown identifier: '%s'\n", lines_tab[0]));
	return (EXIT_SUCCESS);
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
	curr_line = skip_spaces(curr_line);
	if (curr_line == NULL)
		printf_err("No map provided\n");
	return (curr_line);
}
