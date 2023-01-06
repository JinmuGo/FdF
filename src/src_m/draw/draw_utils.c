/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:01:34 by jgo               #+#    #+#             */
/*   Updated: 2023/01/04 14:53:11 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "declaration.h"
#include "color.h"
#include "utils.h"

// void	print_str(t_meta *meta, int x, int y, char *str)
// {
// 	mlx_string_put(meta->vars.mlx, meta->vars.win, x, y, TEXT_COLOR, str);
// }

// void	print_nbr(t_meta *meta, int x, int y, int nbr)
// {
// 	char	*str;

// 	str = ft_itoa(nbr);
// 	mlx_string_put(meta->vars.mlx, meta->vars.win, x, y, NUMBER_COLOR, str);
// 	free (str);
// }

t_bool	invalid_dot(int x, int y)
{
	if (x < 0 || x > WIN_WIDTH)
		return (TRUE);
	if (y < 0 || y > WIN_HEIGHT)
		return (TRUE);
	return (FALSE);
}


int	get_offset(int x, int y, int line_length)
{
	return ((y * line_length + x * 4));
}

int	get_color(t_meta *meta, int color)
{	
	if (meta->img.bits_per_pixel != 32)
		color = mlx_get_color_value(meta->mlx.mlx, color);
	return (color);
}

void	set_color(char *offset, int endian, int color, int alpha)
{
	if (endian)
	{
		offset[A] = alpha;
		offset[R] = (color >> 16) & 0xFF;
		offset[G] = (color >> 8) & 0xFF;
		offset[B] = (color) & 0xFF;
	}
	else
	{
		offset[0] = (color) & 0xFF;
		offset[1] = (color >> 8) & 0xFF;
		offset[2] = (color >> 16) & 0xFF;
		offset[3] = alpha;
	}
}

void	my_dot_put(t_meta *meta, int x, int y, int color)
{
	int offset;
	int alpha;

	if (invalid_dot(x, y))
		return ;
	offset = get_offset(x, y, meta->img.line_length);
	alpha = 1;
	set_color(&meta->img.addr[offset], meta->img.endian, get_color(meta, color), alpha);
}

