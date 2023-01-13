/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:48:38 by jgo               #+#    #+#             */
/*   Updated: 2023/01/13 23:22:44 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"
#include "hooks.h"
#include "draw.h"
#include "utils.h"

int	rotate_planet(t_meta *meta)
{
	if (!meta->key.rotate)
		return (0);
	meta->map.angle[Y] = rotate_angle(meta->map.angle[Y], 1.5);
	draw_process(meta, FALSE);
	return (0);
}

void	hooks(t_meta *meta)
{
	key_hooks(meta);
	mouse_hooks(meta);
	mlx_loop_hook(meta->mlx.mlx, rotate_planet, meta);
	// mlx_loop_hook() 지구본이 빙글빙글 돌아가는 걸 만들자! 
}