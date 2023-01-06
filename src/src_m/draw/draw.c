/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:22:56 by jgo               #+#    #+#             */
/*   Updated: 2023/01/05 07:00:40 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  -> 이미지가 실시간으로 window에 표시되는데 동일한 이미지를 변경 중이면 이미지가 깨질 수도 있음
//  -> 그러므로 이미지를 2개 이상 만드는 것이 안정적임 
// img copy가 필요하겠군. 

#include "declaration.h"
#include "utils.h"
#include "draw.h"

void	draw_background(t_meta *meta, int back_color)
{
	int	axis[2];

	back_color = get_color(meta, back_color);
	axis[Y] = 0;
	while (axis[Y] < WIN_HEIGHT)
	{
		axis[X] = 0;
		while (axis[X] < WIN_WIDTH)
		{
			my_dot_put(meta, axis[X], axis[Y], back_color);
			axis[X]++;
		}
		axis[Y]++;
	}	
}
/*
void	draw_axis(t_meta *meta)
{
	

}
*/


void	draw_process(t_meta *meta)
{
	t_dot *projection;

	projection = malloc(meta->map.total_len * sizeof(t_dot));
	// draw_axis(meta);
	draw_background(meta, meta->map.color.back_color);
	copy_map(meta->map.dot, projection, meta->map.total_len);
	edit_map(meta, projection);
	
	draw(meta, projection);
	mlx_put_image_to_window(meta->mlx.mlx, meta->mlx.win, meta->img.img, 0, 0);	
	free(projection);
}