/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:51:14 by jgo               #+#    #+#             */
/*   Updated: 2023/04/10 14:11:38 by jgo              ###   ########.fr       */
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
	key->dot = FT_TRUE;
	key->line = FT_TRUE;
	key->planet = FT_TRUE;
	key->rotate = FT_TRUE;
	key->axis = FT_FALSE;
	key->extra_line = FT_FALSE;
	key->extra_line2 = FT_FALSE;
	key->shift = FT_FALSE;
}

void	mouse_init(t_mouse *mouse)
{
	mouse->left_click = FT_FALSE;
	mouse->right_click = FT_FALSE;
	ft_bzero(&mouse->prev.axis, 3 * sizeof(float));
}

void	hook_init(t_meta *meta)
{
	key_init(&meta->key);
	mouse_init(&meta->mouse);
}
