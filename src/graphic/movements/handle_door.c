/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmazari <dmazari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:04:16 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/08/25 12:59:06 by dmazari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	change_char_door_x_dir(char **map, t_point pos, t_vector vec)
{
	if (is_almost_rounded(pos.x) && vec.x_i > 0)
	{
		if (map[(int)(pos.y)][(int)floorf(pos.x)]
			&& map[(int)(pos.y)][(int)floorf(pos.x)] == 'C')
			map[(int)(pos.y)][(int)floorf(pos.x)] = 'O';
		else if (map[(int)(pos.y)][(int)floorf(pos.x)]
			&& map[(int)(pos.y)][(int)floorf(pos.x)] == 'O')
			map[(int)(pos.y)][(int)floorf(pos.x)] = 'C';
	}
	if (is_almost_rounded(pos.x) && vec.x_i < 0)
	{
		if (map[(int)(pos.y)][(int)floorf(pos.x) - 1]
			&& map[(int)(pos.y)][(int)floorf(pos.x) - 1] == 'C')
			map[(int)(pos.y)][(int)floorf(pos.x) - 1] = 'O';
		else if (map[(int)(pos.y)][(int)floorf(pos.x) - 1]
			&& map[(int)(pos.y)][(int)floorf(pos.x) - 1] == 'O')
			map[(int)(pos.y)][(int)floorf(pos.x) - 1] = 'C';
	}
}

void	change_char_door_y_dir(char **map, t_point pos, t_vector vec)
{
	if (is_almost_rounded(pos.y) && vec.y_i < 0)
	{
		if ((int)floorf(pos.y) == 0 || ft_strlen(map[(int)floorf(pos.y)
					- 1]) <= (int)(pos.x))
			return ;
		if (map[(int)floorf(pos.y) - 1][(int)(pos.x)] == 'C')
			map[(int)floorf(pos.y) - 1][(int)(pos.x)] = 'O';
		else if (map[(int)floorf(pos.y) - 1][(int)(pos.x)] == 'O')
			map[(int)floorf(pos.y) - 1][(int)(pos.x)] = 'C';
	}
	if (is_almost_rounded(pos.y) && vec.y_i > 0)
	{
		if (!map[(int)floorf(pos.y) + 1] || ft_strlen(map[(int)floorf(pos.y)
					+ 1]) <= (int)(pos.x))
			return ;
		if (map[(int)floorf(pos.y)][(int)(pos.x)] == 'C')
			map[(int)floorf(pos.y)][(int)(pos.x)] = 'O';
		else if (map[(int)floorf(pos.y)][(int)(pos.x)] == 'O')
			map[(int)floorf(pos.y)][(int)(pos.x)] = 'C';
	}
}

t_impact	get_impact_door(t_context *ctx, t_vector vec)
{
	t_impact	impact;

	impact.pos = ctx->player.pos;
	impact.wall_type = stuck_on_wall_dir(ctx->map, impact.pos, vec);
	while (impact.wall_type == NONE)
	{
		impact.pos = get_intersection_pos(impact.pos, vec);
		impact.wall_type = stuck_on_wall_dir(ctx->map, impact.pos, vec);
		if (impact.wall_type == NONE)
		{
			if (vec.x_i < 0 && is_rounded(impact.pos.x))
				impact.pos.x -= 0.0001;
			if (vec.y_i < 0 && is_rounded(impact.pos.y))
				impact.pos.y -= 0.0001;
			if (vec.x_i > 0 && is_rounded(impact.pos.x))
				impact.pos.x += 0.0001;
			if (vec.y_i > 0 && is_rounded(impact.pos.y))
				impact.pos.y += 0.0001;
		}
	}
	return (impact);
}

void	handle_door(t_context *ctx)
{
	t_impact	impact_toward;

	impact_toward = get_impact_door(ctx, ctx->player.p_vec);
	if (impact_toward.wall_type == OPEN)
	{
		change_char_door_y_dir(ctx->map, impact_toward.pos, ctx->player.p_vec);
		change_char_door_x_dir(ctx->map, impact_toward.pos, ctx->player.p_vec);
	}
	if (impact_toward.wall_type == CLOSE)
	{
		change_char_door_y_dir(ctx->map, impact_toward.pos, ctx->player.p_vec);
		change_char_door_x_dir(ctx->map, impact_toward.pos, ctx->player.p_vec);
	}
}
