/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazakov <mazakov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:04:16 by dorianmazar       #+#    #+#             */
/*   Updated: 2025/08/12 16:05:12 by mazakov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_point_dir	get_impact_door(t_context *ctx, t_vector vec)
{
	t_point_dir	impact;

	impact.pos = ctx->player.pos;
	impact.dir = stuck_on_wall_dir(ctx->map, impact.pos, vec);
	while (impact.dir == NONE)
	{
		impact.pos = get_intersection_pos(impact.pos, vec);
		impact.dir = stuck_on_wall_dir(ctx->map, impact.pos, vec);
		if (impact.dir == NONE)
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
	t_point_dir	impact_toward;

	impact_toward = get_impact_door(ctx, ctx->player.p_vec);
	if (impact_toward.dir == OPEN)
		ctx->map[(int)floorf(impact_toward.pos.y)][(int)floorf(impact_toward.pos.x)] = 'C';
	if (impact_toward.dir == CLOSE)
		ctx->map[(int)floorf(impact_toward.pos.y)][(int)floorf(impact_toward.pos.x)] = 'O';
}