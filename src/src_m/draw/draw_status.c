/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:22:56 by jgo               #+#    #+#             */
/*   Updated: 2023/01/13 21:14:40 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"
#include "color.h"

void	print_str(t_meta *meta, int x, int y, char *str)
{
	mlx_string_put(meta->mlx.mlx, meta->mlx.win, x, y, TEXT_COLOR, str);
}

void	print_nbr(t_meta *meta, int x, int y, int nbr)
{
	char	*str;

	str = ft_itoa(nbr);
	mlx_string_put(meta->mlx.mlx, meta->mlx.win, x, y, TEXT_COLOR, str);
	free (str);
}



void    draw_status(t_meta *meta)
{
	// 맵 이름
	// 각도, 
	// 현재 가운데 있는 점의 위치.
	// 모드들 on, off 상태인지. 
	print_nbr(meta, 30, 50, meta->map.angle[X]);
	print_nbr(meta, 30, 100, meta->map.angle[Y]);
	print_nbr(meta, 30, 150, meta->map.angle[Z]);
}