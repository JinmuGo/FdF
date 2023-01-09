/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:10:04 by jgo               #+#    #+#             */
/*   Updated: 2023/01/07 19:41:33 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"
#include "draw.h"

t_bool	get_profit_scale(t_dot *dot, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (dot[i].axis[X] < (MENU_WIDTH + MARGIN) || \
			dot[i].axis[X] > (WIN_WIDTH - MARGIN))
			return (FALSE);
		if (dot[i].axis[Y] < MARGIN || \
			dot[i].axis[Y] > (WIN_HEIGHT - MARGIN))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	copy_map(t_dot *src, t_dot *dst, int len)
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
	meta->map.src.axis[X] = ((WIN_WIDTH + MENU_WIDTH) / 2);
	meta->map.src.axis[Y] = WIN_HEIGHT / 2;
	meta->map.src.axis[Z] = 0;
	meta->map.scale = 1;
	copy_map(meta->map.dot, projection, meta->map.total_len);
	edit_map(meta, projection);
	while (get_profit_scale(projection, meta->map.total_len))
	{
		copy_map(meta->map.dot, projection, meta->map.total_len);
		edit_map(meta, projection);
		meta->map.scale = meta->map.scale + 0.2;
	}
}
