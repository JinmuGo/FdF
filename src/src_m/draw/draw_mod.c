/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:28:51 by jgo               #+#    #+#             */
/*   Updated: 2023/01/13 15:56:14 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "declaration.h"




/**
 * @brief flat to sphere
 * @link https://www.themathdoctors.org/making-a-sphere-from-flat-material/
 * @link https://m.blog.naver.com/junhyuk7272/221675164093
 * @link https://42born2code.slack.com/archives/CN9RHKQHW/p1669804421641049
 * 
 * @param meta 
 * @param projection 
 */

/*
For each (point i from 0 to 100)
{
     lat = map(i, 0, 100, -PI, PI)
    For each (point j from 0 to 100)
    {
          lon = map(j, 0, 100, -PI/2, PI / 2)
           x  = r * sin(lon) * cos(lat) // lon : 경도, lat : 위도 
           y  = r * sin(lon) * sin(lat)
        	z = r * cos(lon)y
           save(point data)
     }
}
*/



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
float map(int value, int istart, int iend, float fstart, float fend)
{
	return (fstart + (fend - fstart) * ((float)(value - istart) / (iend - istart)));
}

int	get_radius(int z, int max_z, int min_z)
{
	float	r;
	
	if (max_z == min_z)
		return (100);
	r = ((float)z - min_z) / (max_z - min_z);
	// printf("max: %d cur: %d min: %d\n", max_z, z, min_z);
	// printf("radius: %f\n", r);
	return (r * (150) + (1 - r) * (100));
}

void	draw_planet(t_meta *meta, t_dot *projection)
{
	int	axis[2];
	// int	rad3[3];
	float lat;
	float lon;

	// radian_init(rad3, angle);
	axis[X] = 0;
	while (axis[X] < meta->map.max.axis[X])
	{
		axis[Y] = 0;
		lon = map(axis[X],0, meta->map.max.axis[X], -M_PI, M_PI);
		while (axis[Y] < meta->map.max.axis[Y])
		{
			int idx = meta->map.max.axis[X] * axis[Y] + axis[X];
			lat = map(axis[Y], 0,meta->map.max.axis[Y], -(M_PI / 2) , M_PI / 2);
			int radius = get_radius(meta->map.dot[idx].axis[Z] , meta->map.max.axis[Z], meta->map.z_min);
			projection[idx].axis[X] = radius * cos(lat) * cos(lon); // lon : 경도, lat : 위도 
			projection[idx].axis[Y] = radius * cos(lat) * sin(lon); // lon : 경도, lat : 위도 
			projection[idx].axis[Z] = radius * sin(lat); // lon : 경도, lat : 위도 
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