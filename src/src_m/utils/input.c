/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 14:24:06 by jgo               #+#    #+#             */
/*   Updated: 2023/01/14 12:36:13 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"
#include "fdf.h"
#include "error.h"
#include "utils.h"
#include "color.h"

void	assign_dot(char *line, t_map *map, int height)
{
	char	**split_arr;
	int	i;

	split_arr = ft_split(line, ' ');
	i = 0;
	while (split_arr[i] && split_arr[i][0] != '\n')
	{
		map->dot[map->total_len].axis[X] = i - map->max.axis[X] / 2;
		map->dot[map->total_len].axis[Y] = height - map->max.axis[Y] / 2;
		map->dot[map->total_len].axis[Z] = ft_atoi(&split_arr[i][0]);
		map->dot[map->total_len].painted = TRUE;
		map->dot[map->total_len].color = init_color(map, map->dot[map->total_len]);
		if (!map->mid.painted && is_mid_dot(map->max , i, height))
			map->mid = map->dot[map->total_len];
		i++;
		map->total_len++;
	}
	free_arr(split_arr);
}

int	cal_map(t_map *map, int fd)
{
	char	*line;
	char	**split_arr;
	int	line_len;
	int	total_len;

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
	const int	map_size = cal_map(map, fd);
	const int	reopen_fd = open(path, O_RDONLY);
	int			height;
	char		*line;

	input_error_handler(2, reopen_fd);
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

char	*get_map_name(const char *path)
{
	const char **path_arr = (const char **)ft_split(path, '/');
	char *name;
	int	i;
	int	len;

	i = 0;
	while (path_arr[i])
		i++;
	len = ft_strlen(path_arr[i - 1]);
	name = malloc(sizeof(char) * len);
	allocate_error_handler(name);
	ft_memcpy(name, path_arr[i - 1], len);
	free_arr((void *)path_arr);
	return (name);
}


void	input_process(t_map *map, const char *path, int fd)
{
	map->name = get_map_name(path);
	init_map(map);
	path_error_handler(path);
	parsing_map(map, path ,fd);
	ft_printf("success map parsing! :)\n");
}