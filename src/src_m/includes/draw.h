/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:04:57 by jgo               #+#    #+#             */
/*   Updated: 2023/01/03 18:05:00 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

void	draw_process(t_meta *meta);


// draw_map.c

void draw(t_meta *meta, t_dot *projection);


// edit_map.c

void	edit_map(t_meta *meta, t_dot *projection);

#endif