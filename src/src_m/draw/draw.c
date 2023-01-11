/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:22:56 by jgo               #+#    #+#             */
/*   Updated: 2023/01/11 09:21:07 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  -> 이미지가 실시간으로 window에 표시되는데 동일한 이미지를 변경 중이면 이미지가 깨질 수도 있음
//  -> 그러므로 이미지를 2개 이상 만드는 것이 안정적임 
// img copy가 필요하겠군. 

#include "declaration.h"
#include "utils.h"
#include "draw.h"
#include "error.h"
#include "color.h"

void	draw_background(t_meta *meta, int back_color, int menu_color)
{
	int	axis[2];
	int	draw_color;

	menu_color = get_color(meta, menu_color);
	back_color = get_color(meta, back_color);
	axis[Y] = 0;
	while (axis[Y] < WIN_HEIGHT)
	{
		axis[X] = 0;
		while (axis[X] < WIN_WIDTH)
		{
			if (axis[X] < MENU_WIDTH)
				draw_color = menu_color;
			else
				draw_color = back_color;
			my_dot_put(meta, axis[X], axis[Y], draw_color);
			axis[X]++;
		}
		axis[Y]++;
	}	
}

void	draw_axis(t_meta *meta, t_dot *axis_arr)
{
	int	i;
	
	i = 0;
	while (i < 6)
	{
		if (i < 2)
			axis_arr[6].color = AXIS_X_COLOR;
		else if (2 <= i && i < 4)
			axis_arr[6].color = AXIS_Y_COLOR;
		else
			axis_arr[6].color = AXIS_Z_COLOR;
		draw_dot_between(meta, axis_arr[6], axis_arr[i]);
		i++;
	}
}

void	draw_process(t_meta *meta, t_bool init)
{
	t_dot	*projection;
	t_dot	*axis_projection;

	projection = malloc(meta->map.total_len * sizeof(t_dot));
	if (!projection)
		err_terminate_process(ERR_ALLOCATE);
	axis_projection = malloc(AXIS_SIZE * sizeof(t_dot));
	if (!axis_projection)
		err_terminate_process(ERR_ALLOCATE);
	draw_background(meta, meta->map.color.back_color, meta->map.color.menu_color);
	copy_dot(meta->map.dot, projection, meta->map.total_len);
	copy_dot(meta->map.axis, axis_projection, AXIS_SIZE);
	edit_map(meta, projection, meta->map.total_len);
	edit_map(meta, axis_projection, AXIS_SIZE);

	draw(meta, projection, init);
	draw_axis(meta, axis_projection);
	mlx_put_image_to_window(meta->mlx.mlx, meta->mlx.win, meta->img.img, 0, 0);
	draw_status(meta);
	free(projection);
	free(axis_projection);
}