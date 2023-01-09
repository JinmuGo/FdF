/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:44:22 by jgo               #+#    #+#             */
/*   Updated: 2023/01/07 19:35:00 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

// key_hooks.c

int	key_press(int key, t_meta *param);
int key_release(int key, t_meta *meta);
void    key_hooks(t_meta *meta);

// mouse_hooks.c

int mouse_press(int button, int x, int y, t_meta *meta);
int mouse_release(int button, int x, int y, t_meta *meta);
int mouse_move(int x, int y, t_meta *meta);
void	mouse_hooks(t_meta *meta);
void	mouse_init(t_mouse *mouse);

// hooks_utils.c

void	hook_init(t_meta *meta);
int	success_terminate_process(t_meta *meta);

#endif