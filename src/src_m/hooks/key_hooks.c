/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:43:22 by jgo               #+#    #+#             */
/*   Updated: 2023/01/11 16:38:31 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"
#include "key_map.h"
#include "hooks.h"
#include "utils.h"
#include "draw.h"
#include "event.h"

void    key_rotate(int key, t_meta *meta)
{
    const int angle = 10;
    
    if (key == KEY_Z)
        meta->map.angle[X] = rotate_angle(meta->map.angle[X], angle);
    if (key == KEY_X)
        meta->map.angle[X] = rotate_angle(meta->map.angle[X], -angle);
    if (key == KEY_A)
        meta->map.angle[Y] = rotate_angle(meta->map.angle[Y], angle);
    if (key == KEY_S)
        meta->map.angle[Y] = rotate_angle(meta->map.angle[Y], -angle);
    if (key == KEY_Q)
        meta->map.angle[Z] = rotate_angle(meta->map.angle[Z], angle);
    if (key == KEY_W)
        meta->map.angle[Z] = rotate_angle(meta->map.angle[Z], -angle);
}

void    key_option(int key, t_meta *meta)
{
    if (key == KEY_D)
        meta->key.dot = !meta->key.dot;
    if (key == KEY_L)
        meta->key.line = !meta->key.line;
    if (key == KEY_E)
        meta->key.axis = !meta->key.axis;
    if (key == KEY_P)
        meta->key.planet = !meta->key.planet;
}

int	key_press(int key, t_meta *meta)
{
    if (key == KEY_ESC)
        success_terminate_process(meta);
    key_rotate(key, meta);
    key_option(key, meta);
    draw_process(meta, FALSE);
    return (0);
}

void    key_hooks(t_meta *meta)
{
    mlx_hook(meta->mlx.win, KEY_PRESS, 0, key_press, meta);
	mlx_hook(meta->mlx.win, DESTROY_NOTIFY, 0, success_terminate_process, meta);
	// mlx_hook(meta->mlx.win, KEY_RELEASE, 0, key_release, &meta);
}


// int key_release(int key, t_meta *meta)
// {

//     return (0);
// }