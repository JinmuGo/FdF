/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:51:14 by jgo               #+#    #+#             */
/*   Updated: 2023/05/13 19:32:57 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"
#include "hooks.h"

int	success_terminate_process(t_meta *meta)
{
	mlx_destroy_window(meta->mlx.mlx, meta->mlx.win);
	free(meta->map.dot);
	exit(EXIT_SUCCESS);
}

void	key_init(t_key *key)
{
	key->dot = true;
	key->line = true;
	key->planet = true;
	key->rotate = true;
	key->axis = false;
	key->extra_line = false;
	key->extra_line2 = false;
	key->shift = false;
}

void	mouse_init(t_mouse *mouse)
{
	mouse->left_click = false;
	mouse->right_click = false;
	ft_bzero(&mouse->prev.axis, 3 * sizeof(float));
}

void	hook_init(t_meta *meta)
{
	key_init(&meta->key);
	mouse_init(&meta->mouse);
}
