/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:24:06 by jgo               #+#    #+#             */
/*   Updated: 2023/01/04 19:27:16 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"
#include "fdf.h"
#include "error.h"
#include "utils.h"
#include "color.h"

void	init_map(t_map *map)
{
	map->max.axis[X] = 0;
	map->max.axis[Y] = 0;
	map->max.axis[Z] = 0;
	map->angle[X] = 50;
	map->angle[Y] = -30;
	map->angle[Z] = 0;
	map->z_min = 0;
	map->key.dot = TRUE;
	map->key.line = TRUE;
	map->color.back_color = BACK_COLOR;
	map->color.text_color = TEXT_COLOR;
	map->color.land_color = LAND_COLOR;
	map->color.peak_color = PEAK_COLOR;
	map->color.bottom_color = BOTTOM_COLOR;
	map->src.axis[X] = ((WIN_WIDTH) / 2);
	map->src.axis[Y] = WIN_HEIGHT / 2;
	map->src.axis[Z] = 0;
	map->scale = 1;
}

int	lerp(int p1, int p2, float ratio)
{
	return ((int)(1 - ratio) * p1 + ratio * p2);
}

float	get_ratio(int start, int mid, int end)
{
	if (start == end)
		return (1.0);
	return ((float)((mid - start) / (end - start)));
}

int	gradient(int start_color, int end_color, const float arr[3])
{
	float ratio;
	int rgb[3];
 
	if ((int)arr[0] == (int)arr[2])
		return (start_color);
	ratio = get_ratio(arr[0], arr[1], arr[2]);
	rgb[0] = lerp((start_color >> 16) & 0xFF, (end_color >> 16) & 0xFF, ratio);
	rgb[1] = lerp((start_color >> 8) & 0xFF, (end_color >> 8) & 0xFF, ratio);
	rgb[2] = lerp(start_color & 0xFF, end_color & 0xFF, ratio);
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

int	init_color(t_map *map, t_dot dot)
{
	const float *arr = get_color_array(map->z_min, dot.axis[Z], map->max.axis[Z]);

	if (arr[1] == 0)
		return (map->color.land_color);
	if (arr[1] == arr[2])
		return (map->color.peak_color);
	if (arr[0] == arr[1] && arr[0] != 0)
		return (map->color.bottom_color);
	if (arr[1] > 0)
		return (gradient(map->color.land_color, map->color.peak_color, arr));
	return (gradient(map->color.peak_color, map->color.land_color, arr));
}

void	init_dot(char *line, t_map *map, size_t height)
{
	char	**split_arr;
	size_t	i;

	split_arr = ft_split(line, ' ');
	i = 0;
	while (split_arr[i] && split_arr[i][0] != '\n')
	{
		map->dot[map->total_len].axis[X] = i - map->max.axis[X] / 2;
		map->dot[map->total_len].axis[Y] = height - map->max.axis[Y] / 2;
		map->dot[map->total_len].axis[Z] = ft_atoi(&split_arr[i][0]);
		map->dot[map->total_len].painted = TRUE;
		map->dot[map->total_len].color = init_color(map, map->dot[map->total_len]);
		i++;
		map->total_len++;
	}
	free_arr(split_arr);
}

size_t	cal_map(t_map *map, int fd)
{
	char	*line;
	char	**split_arr;
	size_t	line_len;
	size_t	total_len;

	total_len = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		split_arr = ft_split(line, ' ');
		cal_z(map, split_arr);
		line_len = cal_line_len(split_arr);
		if (map->max.axis[X] == 0)
			map->max.axis[X] = line_len;
		if (map->max.axis[X] != line_len) // 일단 int로 casting map->max.axis[X]가 0일 수도 있으니.
			err_terminate_process(ERR_LINE_LEN);
		total_len += line_len;
		map->max.axis[Y] += 1;
		free_arr(split_arr);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (total_len);
}

void    parsing_map(t_map *map, const char *path, int fd)
{
	const size_t	map_size = cal_map(map, fd);
	const int		reopen_fd = open(path, O_RDONLY);
	size_t			height;
	char			*line;

	if (reopen_fd < 2)
		err_terminate_process(ERR_PATH_OPEN);
	map->dot = ft_calloc(map_size, sizeof(t_dot));
	if (map->dot == NULL)
		err_terminate_process(ERR_ALLOCATE);
	map->total_len = 0;
	height = 0;
	line = get_next_line(reopen_fd);
	while (line != NULL)
	{
		height++;
		init_dot(line, map, height);
		free(line);
		line = get_next_line(reopen_fd);
	}
	close(reopen_fd);
}

t_bool	verify_path(const char *path)
{
	const char **split_arr = (const char **)ft_split(path, '/');
	char **	surfix_arr;
	t_bool	return_val;
	size_t	i;

	if (!split_arr)
		return (FALSE);
	i = 0;
	while (split_arr[i + 1])
		i++;
	surfix_arr = ft_split(split_arr[i], '.');
	i = 0;
	while (surfix_arr[i + 1])
		i++;
	if (ft_strncmp(surfix_arr[i], "fdf", 4) == 0)
		return_val = TRUE;
	else
		return_val = FALSE;
	free_arr((void *)split_arr);
	free_arr(surfix_arr);
	return (return_val);
}

void	input_process(t_map *map, const char *path, int fd)
{
	init_map(map);
	if(!verify_path(path))
		err_terminate_process(ERR_INVALID_PATH);
	parsing_map(map, path ,fd);
	
}