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
	map->color.back_color = BACK_COLOR;
	map->color.text_color = TEXT_COLOR;
	map->src.axis[X] = ((WIN_WIDTH) / 2);
	map->src.axis[Y] = WIN_HEIGHT / 2;
	map->src.axis[Z] = 0;
	map->scale = 1;
}

void	assign_dot(char *line, t_map *map, size_t height)
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
		i++;
		map->total_len++;
	}
	free_arr(split_arr);
}

size_t	cal_map(t_dot *max, int fd)
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
		cal_z_max(max, split_arr);
		line_len = cal_line_len(split_arr);
		if (max->axis[X] == 0)
			max->axis[X] = line_len;
		if (max->axis[X] != line_len) // 일단 int로 casting max->axis[X]가 0일 수도 있으니.
			err_terminate_process(ERR_LINE_LEN);
		total_len += line_len;
		max->axis[Y] += 1;
		free_arr(split_arr);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (total_len);
}

void    parsing_map(t_map *map, const char *path, int fd)
{
	const size_t	map_size = cal_map(&map->max, fd);
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
		assign_dot(line, map, height);
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