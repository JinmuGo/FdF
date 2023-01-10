/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:51:14 by jgo               #+#    #+#             */
/*   Updated: 2023/01/10 16:56:34 by jgo              ###   ########.fr       */
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

void	mouse_init(t_mouse *mouse)
{
	mouse->left_click = FALSE;
	mouse->right_click = FALSE;
	ft_bzero(&mouse->prev.axis, 3 * sizeof(float));
}

void	hook_init(t_meta *meta)
{
	mouse_init(&meta->mouse);
}