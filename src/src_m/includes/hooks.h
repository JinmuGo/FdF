/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:44:22 by jgo               #+#    #+#             */
/*   Updated: 2023/01/07 17:35:35 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

// key_hooks.c

int	key_press(int key, t_meta *param);

// mouse_hooks.c

int mouse_press(int button, int x, int y, t_meta *meta);
int mouse_release(int button, int x, int y, t_meta *meta);
int mouse_move(int x, int y, t_meta *meta);

// hooks_utils.c

int	success_terminate_program(t_meta *meta);

#endif