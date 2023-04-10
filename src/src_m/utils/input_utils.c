/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 15:13:14 by jgo               #+#    #+#             */
/*   Updated: 2023/04/10 14:11:38 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "declaration.h"
#include "error.h"

t_bool	is_valid_dot(char *dot)
{
	int	i;

	i = 0;
	if (dot[i] == '-' || dot[i] == '+' || dot[i] == '\n')
		i++;
	while (ft_isdigit(dot[i]))
		i++;
	if (i)
		return (FT_TRUE);
	else
		return (FT_FALSE);
}

void	cal_z(t_map *map, char **split_arr)
{
	int	i;
	int	num;

	i = 0;
	while (split_arr[i])
	{
		num = ft_atoi(&split_arr[i][0]);
		if (map->max.axis[Z] < num)
			map->max.axis[Z] = num;
		if (map->min_z > num)
			map->min_z = num;
		if (!is_valid_dot(&split_arr[i][0]))
			err_terminate_process(ERR_INVALID_MAP);
		i++;
	}
}

int	cal_line_len(char **split_arr)
{
	int	len;

	len = 0;
	while (split_arr[len] && split_arr[len][0] != '\n')
		len++;
	return (len);
}

t_bool	is_mid_dot(t_dot max, int width, int height)
{
	const int	mid_idx_x = (int)floorf(max.axis[X] / 2);
	const int	mid_idx_y = (int)ceilf(max.axis[Y] / 2);

	if (width == mid_idx_x && height == mid_idx_y)
		return (FT_TRUE);
	else
		return (FT_FALSE);
}
