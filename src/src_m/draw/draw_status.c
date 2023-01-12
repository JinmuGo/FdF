/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 20:22:56 by jgo               #+#    #+#             */
/*   Updated: 2023/01/12 20:38:21 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "declaration.h"

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
	print_nbr(meta, 30, 50, meta->map.angle[X]);
	print_nbr(meta, 30, 100, meta->map.angle[Y]);
	print_nbr(meta, 30, 150, meta->map.angle[Z]);
}