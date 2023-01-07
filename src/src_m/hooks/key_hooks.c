/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 16:43:22 by jgo               #+#    #+#             */
/*   Updated: 2023/01/07 19:36:23 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "declaration.h"
#include "key_map.h"
#include "hooks.h"

int	key_press(int key, t_meta *meta)
{
    if (key == ESC)
        success_terminate_process(meta);

    return (0);
}