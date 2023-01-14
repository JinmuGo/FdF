/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:51:14 by jgo               #+#    #+#             */
/*   Updated: 2023/01/14 12:53:26 by jgo              ###   ########.fr       */
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

void    key_init(t_key *key)
{
    key->dot = TRUE;
    key->line = TRUE;
	key->planet = TRUE;
	key->rotate = TRUE;
    key->axis = FALSE;
	key->extra_line = FALSE;
	key->extra_line2 = FALSE;
	key->shift = FALSE;
}

void	mouse_init(t_mouse *mouse)
{
	mouse->left_click = FALSE;
	mouse->right_click = FALSE;
	ft_bzero(&mouse->prev.axis, 3 * sizeof(float));
}

void	hook_init(t_meta *meta)
{
	key_init(&meta->key);
	mouse_init(&meta->mouse);
}