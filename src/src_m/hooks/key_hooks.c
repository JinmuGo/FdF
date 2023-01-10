/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:43:22 by jgo               #+#    #+#             */
/*   Updated: 2023/01/10 16:51:25 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"
#include "key_map.h"
#include "hooks.h"
#include "utils.h"
#include "draw.h"
#include "event.h"

int	key_press(int key, t_meta *meta)
{
    const int angle = 10;

    if (key == KEY_ESC)
        success_terminate_process(meta);
    if (key == KEY_Q)
        meta->map.angle[Z] = rotate_angle(meta->map.angle[Z], angle);
    if (key == KEY_W)
        meta->map.angle[Z] = rotate_angle(meta->map.angle[Z], -angle);
    draw_process(meta, FALSE);
    return (0);
}


// int key_release(int key, t_meta *meta)
// {

//     return (0);
// }

void    key_hooks(t_meta *meta)
{
    mlx_hook(meta->mlx.win, KEY_PRESS, 0, key_press, meta);
	mlx_hook(meta->mlx.win, DESTROY_NOTIFY, 0, success_terminate_process, meta);
	// mlx_hook(meta->mlx.win, KEY_RELEASE, 0, key_release, &meta);
}