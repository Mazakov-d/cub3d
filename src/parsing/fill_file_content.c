/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_file_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:09:25 by mniemaz           #+#    #+#             */
/*   Updated: 2025/09/01 10:43:18 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void	line_add_back(t_line ***head_file_line, t_line *new_line)
{
	t_line	*last;
	t_line	**content;

	content = *head_file_line;
	new_line->next = NULL;
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

static int	return_free_on_err(t_line ***head_file_line)
{
	free_lines_lst(*head_file_line);
	return (printf_err("fill_file_content: %s\n", strerror(errno)));
}

/**
 * @brief Reads the file line by line and fills the linked list with each line.
 * @returns EXIT_SUCCESS on success, EXIT_FAILURE on error.
 */
int	fill_file_content(t_line ***head_file_line, int fd)
{
	char	*str;
	t_line	*new_line;

	*head_file_line = malloc(sizeof(t_line *));
	if (!*head_file_line)
		return (printf_err("fill_file_content: %s\n", strerror(errno)));
	**head_file_line = NULL;
	str = get_next_line(fd);
	if (errno != 0)
		return (return_free_on_err(head_file_line));
	while (str)
	{
		new_line = malloc(sizeof(t_line));
		if (!new_line)
		{
			free(str);
			return (return_free_on_err(head_file_line));
		}
		new_line->line = rm_nl(str);
		line_add_back(head_file_line, new_line);
		str = get_next_line(fd);
		if (errno != 0)
			return (return_free_on_err(head_file_line));
	}
	return (EXIT_SUCCESS);
}
