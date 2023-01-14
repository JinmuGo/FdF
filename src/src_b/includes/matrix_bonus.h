/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:18:29 by jgo               #+#    #+#             */
/*   Updated: 2023/01/14 18:42:54 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_BONUS_H
# define MATRIX_BONUS_H

t_dot	mul3_mat(float matrix[3][3], t_dot dot);
void	matrix3_init(float (*matrix)[3]);
void	radian_init(float *rad, float angle[3]);

#endif