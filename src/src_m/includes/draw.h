/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:04:57 by jgo               #+#    #+#             */
/*   Updated: 2023/05/13 19:32:35 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

void	draw_process(t_meta *meta, bool init);

// draw_map.c

void	draw(t_meta *meta, t_dot *projection, bool init);
void	draw_dot_between(t_meta *meta, t_dot start, t_dot end);
int		delta_init(t_dot *delta, t_dot start, t_dot end);

// edit_map.c

void	edit_map(t_meta *meta, t_dot *projection, int len);
void	draw_planet(t_map *map, t_dot *projection, int idx);

#endif