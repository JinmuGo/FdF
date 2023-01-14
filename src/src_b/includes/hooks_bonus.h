/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:44:22 by jgo               #+#    #+#             */
/*   Updated: 2023/01/14 18:42:36 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_BONUS_H
# define HOOKS_BONUS_H

// key_hooks.c

int		key_press(int key, t_meta *param);

// mouse_hooks.c

int		mouse_press(int button, int x, int y, t_meta *meta);
int		mouse_release(int button, int x, int y, t_meta *meta);
int		mouse_move(int x, int y, t_meta *meta);
void	mouse_init(t_mouse *mouse);

// hooks_utils.c

void	hook_init(t_meta *meta);
int		success_terminate_process(t_meta *meta);

// hooks.c

void	hooks(t_meta *meta);

#endif