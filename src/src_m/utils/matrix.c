/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:49:17 by jgo               #+#    #+#             */
/*   Updated: 2023/01/04 19:24:23 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

t_dot	mul3_mat(float matrix[3][3], t_dot dot)
{
	int	i;
	int	j;
	t_dot   result;

	result = dot;
	i = 0;
	while (i < 3)
	{
		result.axis[i] = 0;
		result.color = dot.color;
		j = 0;
		while (j < 3)
		{
			result.axis[i] += matrix[i][j] * dot.axis[j];
			j++;
		}
		i++;
	}
	return (result);
}

void	matrix3_init(float (*matrix)[3])
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}

void    radian_init(float *rad, float angle[3])
{
    int i;

    i = 0;
    while (i < 3)
    {
        rad[i] = angle[i] * M_PI / 180;
        i++;
    }
}