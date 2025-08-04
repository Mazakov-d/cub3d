/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:00:06 by mniemaz           #+#    #+#             */
/*   Updated: 2025/08/04 14:06:32 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_line	*skip_spaces(t_line *line)
{
	t_line	*curr_line;

	curr_line = line;
	while (curr_line && ft_is_str_spaces(curr_line->line))
		curr_line = curr_line->next;
	return (curr_line);
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

static int	return_free_line_on_err(t_line ***head_file_line)
{
	free_lines_lst(*head_file_line);
	return (EXIT_FAILURE);
}

static void	init_player_dir(t_context *ctx)
{
	if (ctx->map[(int)(ctx->player.pos.y)][(int)(ctx->player.pos.x)] == 'E')
		init_vector(&ctx->player.p_vec, 1, 0);
	else if (ctx->map[(int)(ctx->player.pos.y)][(int)(ctx->player.pos.x)] == 'W')
		init_vector(&ctx->player.p_vec, -1, 0);
	else if (ctx->map[(int)(ctx->player.pos.y)][(int)(ctx->player.pos.x)] == 'N')
		init_vector(&ctx->player.p_vec, 1, 0.3);
	else if (ctx->map[(int)(ctx->player.pos.y)][(int)(ctx->player.pos.x)] == 'S')
		init_vector(&ctx->player.p_vec, 0, 1);
	ctx->map[(int)(ctx->player.pos.y)][(int)(ctx->player.pos.x)] = '0';
}

int	parse_file(t_context *ctx, char *filename)
{
	int		fd;
	t_line	*map_start_line;
	t_line	**head_file_line;

	if (check_and_open_file(&fd, filename) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (fill_file_content(&head_file_line, fd) == EXIT_FAILURE)
	{
		close(fd);
		return (EXIT_FAILURE);
	}
	close(fd);
	map_start_line = fill_texture_data(head_file_line, &ctx->texture_data);
	if (!map_start_line)
		return (return_free_line_on_err(&head_file_line));
	if (fill_map(ctx, map_start_line) == EXIT_FAILURE)
		return (return_free_line_on_err(&head_file_line));
	free_lines_lst(head_file_line);
	if (check_flood_fill(ctx) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	init_player_dir(ctx);
	return (EXIT_SUCCESS);
}
