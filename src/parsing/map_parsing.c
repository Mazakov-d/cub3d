/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:00:06 by mniemaz           #+#    #+#             */
/*   Updated: 2025/07/28 21:00:58 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	line_add_back(t_parsing_data *p_data, t_line *new_line)
{
	t_line	*last;
	t_line	**content;

	content = p_data->file_content;
	if (!content || !*content)
	{
		*content = new_line;
		return ;
	}
	last = *content;
	while (last->next)
		last = last->next;
	last->next = new_line;
}

void	fill_parsing_data(t_parsing_data *p_data)
{
	char	*str;
	t_line	*new_line;

	p_data->file_content = malloc(sizeof(t_line *));
	if (!p_data->file_content)
		return ;
	*p_data->file_content = NULL;
	str = get_next_line(p_data->fd);
	while (str)
	{
		new_line = malloc(sizeof(t_line));
		if (!new_line)
		{
			close(p_data->fd);
			return ;
		}
		new_line->line = rm_nl(str);
		new_line->next = NULL;
		line_add_back(p_data, new_line);
		str = get_next_line(p_data->fd);
	}
	close(p_data->fd);
}

int	fill_color(t_color *color, char *str_colors)
{
	char	**color_values;
    int		error;

	color_values = ft_split(str_colors, ",");
	if (!color_values)
	{
		ft_dprintf(STDERR_FILENO, "fill_color: %s\n", strerror(errno));
		return (EXIT_FAILURE);
	}
	if (!color_values[0] || !color_values[1] || !color_values[2])
	{
		free(color_values);
		return (EXIT_FAILURE);
	}
	color->r = (unsigned char)ft_atoi_color(color_values[0], &error);
	color->g = (unsigned char)ft_atoi_color(color_values[1], &error);
	color->b = (unsigned char)ft_atoi_color(color_values[2], &error);
    free(color_values);
    if (error)
        return (EXIT_FAILURE);
    color->rgba = (color->r << 16) | (color->g << 8) | color->b;
	return (EXIT_SUCCESS);
}

bool	is_graphic_data_filled(t_graphic_data *gr_data)
{
	return (gr_data->north && gr_data->south && gr_data->east && gr_data->west
		&& gr_data->floor && gr_data->ceiling
		&& gr_data->floor->r != (unsigned char)COLOR_INIT_VAL
		&& gr_data->ceiling->r != (unsigned char)COLOR_INIT_VAL);
}

int	process_line_fill_graphic_data(t_graphic_data *gr_data, char **lines_tab)
{
	if (ft_strncmp(lines_tab[0], "NO", 3) == 0 && lines_tab[1])
		gr_data->north = ft_strdup(lines_tab[1]);
	else if (ft_strncmp(lines_tab[0], "SO", 3) == 0 && lines_tab[1])
		gr_data->south = ft_strdup(lines_tab[1]);
	else if (ft_strncmp(lines_tab[0], "WE", 3) == 0 && lines_tab[1])
		gr_data->west = ft_strdup(lines_tab[1]);
	else if (ft_strncmp(lines_tab[0], "EA", 3) == 0 && lines_tab[1])
		gr_data->east = ft_strdup(lines_tab[1]);
	else if (ft_strncmp(lines_tab[0], "F", 2) == 0 && lines_tab[1])
	{
		if (fill_color(gr_data->floor, lines_tab[1]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else if (ft_strncmp(lines_tab[0], "C", 2) == 0 && lines_tab[1])
	{
		if (fill_color(gr_data->ceiling, lines_tab[1]) == EXIT_FAILURE)
			return (EXIT_FAILURE);
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/**
 * @returns a pointer to the line where the graphic data is filled.
 */
t_line	*fill_graphic_data(t_parsing_data *p_data, t_graphic_data *gr_data)
{
	t_line	*curr_line;
	char	**lines_tab;

	curr_line = *p_data->file_content;
	while (curr_line)
	{
		lines_tab = ft_split(curr_line->line, " ");
		if (!lines_tab)
		{
			ft_dprintf(STDERR_FILENO, "fill_graphic_data: %s\n",
				strerror(errno));
			return (NULL);
		}
		if (!lines_tab[0])
		{
			curr_line = curr_line->next;
			continue ;
		}
		if (process_line_fill_graphic_data(gr_data, lines_tab) == EXIT_FAILURE)
		{
            ft_dprintf(STDERR_FILENO, "Invalid line: \"%s\"\n",
                curr_line->line);
			return (NULL);
		}
		free(lines_tab);
		curr_line = curr_line->next;
		if (is_graphic_data_filled(gr_data))
			break ;
	}
	return (curr_line);
}

void	init_graphic_data(t_graphic_data *gr_data)
{
	gr_data->north = NULL;
	gr_data->south = NULL;
	gr_data->east = NULL;
	gr_data->west = NULL;
	gr_data->floor = NULL;
	gr_data->ceiling = NULL;
	gr_data->floor = malloc(sizeof(t_color));
	if (!gr_data->floor)
	{
		ft_dprintf(STDERR_FILENO, "init_graphic_data: %s\n", strerror(errno));
		return ;
	}
	gr_data->ceiling = malloc(sizeof(t_color));
	if (!gr_data->ceiling)
	{
		ft_dprintf(STDERR_FILENO, "init_graphic_data: %s\n", strerror(errno));
		free(gr_data->floor);
		return ;
	}
	gr_data->floor->r = (unsigned char)COLOR_INIT_VAL;
	gr_data->ceiling->r = (unsigned char)COLOR_INIT_VAL;
}

t_line	*get_start_of_map(t_line *line)
{
	t_line	*curr_line;

	curr_line = line;
	while (curr_line && ft_is_str_spaces(curr_line->line))
		curr_line = curr_line->next;
	return (curr_line);
}

bool	is_map_line_valid(char *line, char *valid_chars)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!is_char_in_str(line[i], valid_chars))
			return (false);
		i++;
	}
	return (true);
}

int	check_and_count_map_rows(t_line *line, int *nb_map_rows)
{
	t_line	*curr_line;
	int		nb_empty_lines;

	*nb_map_rows = 0;
	nb_empty_lines = 0;
	curr_line = line;
	while (curr_line)
	{
		if (!is_map_line_valid(curr_line->line, VALIDE_MAP_CHARS))
		{
			ft_dprintf(STDERR_FILENO, "Invalid map line: '%s'\n",
				curr_line->line);
			return (EXIT_FAILURE);
		}
		if (ft_is_str_spaces(curr_line->line))
			nb_empty_lines++;
		else
		{
			*nb_map_rows += nb_empty_lines + 1;
			nb_empty_lines = 0;
		}
		curr_line = curr_line->next;
	}
	return (EXIT_SUCCESS);
}

char	**get_filled_map(int nb_map_rows, t_line *curr_line)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * (nb_map_rows + 1));
	if (!map)
	{
		ft_dprintf(STDERR_FILENO, "fill_map: %s\n", strerror(errno));
		return (NULL);
	}
	i = 0;
	while (i < nb_map_rows)
	{
		map[i] = ft_strdup(curr_line->line);
		if (!map[i])
		{
			ft_dprintf(STDERR_FILENO, "fill_map: %s\n", strerror(errno));
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
 * @brief Fills the map in the context and checks if:
 * - the map contains valid characters
 * - the map does not contain empty lines
 */
int	fill_map(t_context *ctx, t_line *end_graphic_data_line)
{
	t_line	*start_of_map;
	int		nb_map_rows;

	start_of_map = get_start_of_map(end_graphic_data_line);
	if (check_and_count_map_rows(start_of_map, &nb_map_rows) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	ctx->map = get_filled_map(nb_map_rows, start_of_map);
	if (!ctx->map)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	print_map(t_context *ctx)
{
	char	**map;

	map = ctx->map;
	while (*map)
	{
		printf("%s\n", *map);
		map++;
	}
}

void	print_graphic_data(t_graphic_data *gr_data)
{
	printf("North: %s\n", gr_data->north);
	printf("South: %s\n", gr_data->south);
	printf("East: %s\n", gr_data->east);
	printf("West: %s\n", gr_data->west);
	printf("Floor Color: %d, %d, %d\n", gr_data->floor->r, gr_data->floor->g,
		gr_data->floor->b);
	printf("Ceiling Color: %d, %d, %d\n", gr_data->ceiling->r,
		gr_data->ceiling->g, gr_data->ceiling->b);
}

void	parse_file(t_context *ctx, char *filename)
{
	t_parsing_data	p_data;
	t_line			*end_graphic_data_line;

	if (!ends_with(filename, ".cub"))
	{
		ft_dprintf(STDERR_FILENO, "%s: Expected a .cub file\n", filename);
		return ;
	}
	p_data.fd = open(filename, O_RDONLY);
	if (p_data.fd == -1)
	{
		ft_dprintf(STDERR_FILENO, "%s: %s\n", filename, strerror(errno));
		return ;
	}
	fill_parsing_data(&p_data);
	init_graphic_data(&ctx->graphic_data);
	end_graphic_data_line = fill_graphic_data(&p_data, &ctx->graphic_data);
	if (!end_graphic_data_line)
	{
		return ;
	}
	if (fill_map(ctx, end_graphic_data_line) == EXIT_FAILURE)
        return ;
	print_graphic_data(&ctx->graphic_data);
	print_map(ctx);
}
