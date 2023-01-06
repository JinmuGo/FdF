/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:51:14 by jgo               #+#    #+#             */
/*   Updated: 2022/12/28 19:10:14 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"

int	success_terminate_program(t_meta *meta)
{
	mlx_destroy_window(meta->mlx.mlx, meta->mlx.win);
	free(meta->map.dot);

	exit(EXIT_SUCCESS);
}