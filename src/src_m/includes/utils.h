/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:01:25 by jgo               #+#    #+#             */
/*   Updated: 2023/01/07 18:57:26 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// utils.c

void	free_arr(char **arr);
float	rotate_angle(float angle, float value);

// input_utils.c

void	cal_z_max(t_dot *max, char **split_arr);
size_t	cal_line_len(char **split_arr);

// draw_utils.c

int     get_color(t_meta *meta, int color);
void	set_color(char *offset, int endian, int color, int alpha);
int     get_offset(int x, int y, int line_length);
void	my_dot_put(t_meta *meta, int x, int y, int color);

// map_utils.c

void	edit_map(t_meta *meta, t_dot *projection);
void	get_proper_scale(t_meta *meta, t_dot *projection);
void	copy_map(t_dot *src, t_dot *dst, size_t len);
t_bool	invalid_dot(int x, int y);

#endif