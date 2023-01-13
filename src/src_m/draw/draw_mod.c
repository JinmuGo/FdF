/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:28:51 by jgo               #+#    #+#             */
/*   Updated: 2023/01/13 23:18:45 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "declaration.h"
#include "utils.h"

/**
 * @brief 
 * 
 * @param value 
 * @param iend 
 * @param fstart 
 * @param fend 
 * 
 * map(value, istart, iend, fstart, fend)
        return (fstart +(fend - fstart) * ((value - istart) / (iend - istart))
 * @return float 
 */
float mapping(int value, int iend, float fstart, float fend)
{
	return (fstart + (fend - fstart) * ((float)(value) / (iend)));
}

int	get_radius(t_map *map, t_dot dot)
{
	const int min_z = map->min_z;
	const int max_z = map->max.axis[Z];
	
	const	float	r = get_ratio(min_z, dot.axis[Z], max_z);

	if (map->max.axis[X] > map->max.axis[Y])
		return (lerp(map->max.axis[Y], map->max.axis[X], r));
	else
		return (lerp(map->max.axis[X], map->max.axis[Y], r));
}


/**
 * @brief flat to sphere
 * @link https://www.themathdoctors.org/making-a-sphere-from-flat-material/
 * @link https://m.blog.naver.com/junhyuk7272/221675164093
 * @link https://42born2code.slack.com/archives/CN9RHKQHW/p1669804421641049
 * 
 * @param meta 
 * @param projection 
 */
void	draw_planet(t_map *map, t_dot *projection)
{
	float angle[2];
	int	axis[2];
	float	radius;
	int	idx;

	axis[X] = 0;
	while (axis[X] < map->max.axis[X])
	{
		axis[Y] = 0;
		angle[LON] = mapping(axis[X], map->max.axis[X], -M_PI, M_PI);
		while (axis[Y] < map->max.axis[Y])
		{
			idx = map->max.axis[X] * axis[Y] + axis[X];
			angle[LAT] = mapping(axis[Y], map->max.axis[Y], -(M_PI / 2) , M_PI / 2);
			radius = get_radius(map, projection[idx]);
			projection[idx].axis[X] = (radius + projection[idx].axis[Z]) * cos(angle[LAT]) * cos(angle[LON]);
			projection[idx].axis[Y] = (radius + projection[idx].axis[Z]) * cos(angle[LAT]) * sin(angle[LON]);
			projection[idx].axis[Z] = (radius + projection[idx].axis[Z]) * sin(angle[LAT]);
			axis[Y]++;
		}
		axis[X]++;
	}
}

// steps_x = (M_PI * 2) / (map->limits.axis[X] - 1);
// steps_y = M_PI / (map->limits.axis[Y]);

// while (i < map->len)
// {
// 	map->points[i].polar[LONG] = -(map->points[i].axis[X]) * steps_x;
// 	if (map->points[i].axis[Y] > 0)
// 		map->points[i].polar[LAT] = ((map->points[i].axis[Y]) + (map->limits.axis[Y] / 2)) * steps_y - 0.5 * steps_y;
// 	else
// 		map->points[i].polar[LAT] = (map->points[i].axis[Y] + (map->limits.axis[Y] / 2) - 1) * steps_y + 0.5 * steps_y;
// 	i++;
// }

/*
void	spherize(t_map *map, t_dot *points)
{
	int	i;
	int	rad[3];

	rad[X] = map->angle[X] * M_PI / 180;
	rad[Y] = map->angle[Y] * M_PI / 180;
	rad[Z] = map->angle[Z] * M_PI / 180;
	i = 0;
	while (i < map->total_len)
	{
		// points[i].axis[X] = (map->radius + points[i].axis[Z]) * \
		// cos(points[i].polar[LONG]) * sin(points[i].polar[LAT]);
		// points[i].axis[Y] = (map->radius + points[i].axis[Z]) * \
		// sin(points[i].polar[LONG]) * sin(points[i].polar[LAT]);
		// points[i].axis[Z] = (map->radius + points[i].axis[Z]) * \
		// cos(points[i].polar[LAT]);
		i++;
	}
}*/