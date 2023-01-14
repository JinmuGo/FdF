/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:10:04 by jgo               #+#    #+#             */
/*   Updated: 2023/01/14 17:49:12 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration_bonus.h"
#include "draw_bonus.h"
#include "color_bonus.h"

t_bool	get_profit_scale(t_dot *dot, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (dot[i].axis[X] < (MARGIN) || \
			dot[i].axis[X] > (WIN_WIDTH - MARGIN))
			return (FALSE);
		if (dot[i].axis[Y] < MARGIN || \
			dot[i].axis[Y] > (WIN_HEIGHT - MARGIN))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	copy_dot(t_dot *src, t_dot *dst, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}

void	get_proper_scale(t_meta *meta, t_dot *projection)
{
	if (meta->key.planet)
	{
		meta->map.scale *= 3;
		return ;
	}
	meta->map.src.axis[X] = WIN_WIDTH / 2;
	meta->map.src.axis[Y] = WIN_HEIGHT / 2;
	meta->map.src.axis[Z] = 0;
	meta->map.scale = 1;
	copy_dot(meta->map.dot, projection, meta->map.total_len);
	edit_map(meta, projection, meta->map.total_len);
	while (get_profit_scale(projection, meta->map.total_len))
	{
		copy_dot(meta->map.dot, projection, meta->map.total_len);
		edit_map(meta, projection, meta->map.total_len);
		meta->map.scale = meta->map.scale + 0.2;
	}
}

static void	init_map_color(t_color *color)
{
	color->back_color = BACK_COLOR;
	color->text_color = TEXT_COLOR;
	color->land_color = LAND_COLOR;
	color->peak_color = PEAK_COLOR;
	color->menu_color = MENU_COLOR;
	color->bottom_color = BOTTOM_COLOR;
}

void	init_map(t_map *map)
{
	map->angle[X] = 280;
	map->angle[Y] = 0;
	map->angle[Z] = 0;
	map->min_z = 0;
	map->src.axis[X] = WIN_WIDTH / 2;
	map->src.axis[Y] = WIN_HEIGHT / 2;
	map->src.axis[Z] = 0;
	map->mid.painted = FALSE;
	map->scale = 1;
	map->radius = map->max.axis[X] / (M_PI * 2);
	ft_bzero(&map->max.axis, 3 * sizeof(float));
	ft_bzero(&map->mid.axis, 3 * sizeof(float));
	init_map_color(&map->color);
}
