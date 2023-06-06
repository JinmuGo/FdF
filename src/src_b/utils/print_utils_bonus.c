/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:24:23 by jgo               #+#    #+#             */
/*   Updated: 2023/06/06 15:43:40 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "declaration_bonus.h"
#include "color_bonus.h"

void	print_str(t_mlx mlx, int x, int y, const char *str)
{
	mlx_string_put(mlx.mlx, mlx.win, x, y, TEXT_COLOR, (char *)str);
}

void	print_nbr(t_mlx mlx, int x, int y, int nbr)
{
	char	*str;

	str = ft_itoa(nbr);
	mlx_string_put(mlx.mlx, mlx.win, x, y, TEXT_COLOR, str);
	free (str);
}

char	*make_bool_str(bool args)
{
	if (args)
		return ("ON");
	else
		return ("OFF");
}
