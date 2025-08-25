/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lines_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 10:47:36 by mniemaz           #+#    #+#             */
/*   Updated: 2025/08/25 11:13:47 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_lines_lst(t_line **head)
{
	t_line	*prev;
	t_line	*curr;

	if (!head || !*head)
		return ;
	curr = *head;
	while (curr)
	{
		prev = curr;
		curr = curr->next;
		free(prev->line);
		free(prev);
	}
	free(head);
}
