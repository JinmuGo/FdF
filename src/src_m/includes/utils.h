/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:01:25 by jgo               #+#    #+#             */
/*   Updated: 2023/01/14 13:09:53 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// utils.c

void	free_arr(char **arr);
float	rotate_angle(float angle, float value);
int		init_color(t_map *map, t_dot dot);
void	init_metadata(t_meta *meta);

// input_utils.c

void	cal_z(t_map *map, char **split_arr);
int		cal_line_len(char **split_arr);
t_bool	is_mid_dot(t_dot max, int width, int height);

// draw_utils.c

float	get_ratio(int min, int mid, int max);
int		lerp(int p1, int p2, float ratio);
void	my_dot_put(t_meta *meta, int x, int y, int color);

// map_utils.c

void	get_proper_scale(t_meta *meta, t_dot *projection);
void	copy_dot(t_dot *src, t_dot *dst, int len);
t_bool	invalid_dot(int x, int y);
void	init_map(t_map *map);

// print_status.c

void    print_status(t_meta *meta);

// print_utils.c

void	print_nbr(t_mlx mlx, int x, int y, int nbr);
void	print_str(t_mlx mlx, int x, int y, const char *str);
char	*make_bool_str(t_bool bool);

#endif