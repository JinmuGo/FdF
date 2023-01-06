/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:44:22 by jgo               #+#    #+#             */
/*   Updated: 2022/12/28 18:53:41 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

int	key_press(int key, t_meta *param);

// hooks_utils.c

int	success_terminate_program(t_meta *meta);

#endif