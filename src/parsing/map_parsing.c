/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:00:06 by mniemaz           #+#    #+#             */
/*   Updated: 2025/07/29 17:26:49 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

void	print_texture_data(t_texture_data *tex_data)
{
	printf("North: %s\n", tex_data->north);
	printf("South: %s\n", tex_data->south);
	printf("East: %s\n", tex_data->east);
	printf("West: %s\n", tex_data->west);
	printf("Floor Color: %d, %d, %d\n", tex_data->floor->r, tex_data->floor->g,
		tex_data->floor->b);
	printf("Ceiling Color: %d, %d, %d\n", tex_data->ceiling->r,
		tex_data->ceiling->g, tex_data->ceiling->b);
}

/**
 * @brief Checks if the file ends with ".cub" and opens it
 */
static int	check_and_open_file(int *fd, char *filename)
{
	if (!ends_with(filename, ".cub"))
	{
		printf_err("%s: Expected a .cub file\n", filename);
		return (EXIT_FAILURE);
	}
	*fd = open(filename, O_RDONLY);
	if (*fd == -1)
	{
		printf_err("%s: %s\n", filename, strerror(errno));
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	parse_file(t_context *ctx, char *filename)
{
	int		fd;
	t_line	*map_start_line;
	t_line	**head_file_line;

	if (check_and_open_file(&fd, filename) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (fill_file_content(&head_file_line, fd) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	map_start_line = fill_texture_data(head_file_line, &ctx->texture_data);
	if (!map_start_line)
	{
		free_lines_lst(head_file_line);
		return (EXIT_FAILURE);
	}
	if (fill_map(ctx, map_start_line) == EXIT_FAILURE)
	{
		free_lines_lst(head_file_line);
		return (EXIT_FAILURE);
	}
	free_lines_lst(head_file_line);
	return (EXIT_SUCCESS);
}
