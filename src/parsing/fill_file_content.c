/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_file_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 14:09:25 by mniemaz           #+#    #+#             */
/*   Updated: 2025/07/29 15:06:28 by mniemaz          ###   ########.fr       */
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

int	fill_file_content(t_line ***head_file_line, int fd)
{
	char *str;
	t_line *new_line;

	*head_file_line = malloc(sizeof(t_line *));
	if (!*head_file_line)
	{
		close(fd);
		return (printf_err("fill_file_content: %s\n", strerror(errno)));
	}
	**head_file_line = NULL;
	str = get_next_line(fd);
	while (str)
	{
		new_line = malloc(sizeof(t_line));
		if (!new_line)
		{
			ft_free_tab((void **)*head_file_line);
			close(fd);
			free(str);
			return (printf_err("fill_file_content: %s\n", strerror(errno)));
		}
		new_line->line = rm_nl(str);
		line_add_back(head_file_line, new_line);
		str = get_next_line(fd);
	}
	close(fd);
	return (EXIT_SUCCESS);
}
