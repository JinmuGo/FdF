/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 16:06:19 by jgo               #+#    #+#             */
/*   Updated: 2022/12/26 17:58:14 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# define DARK_OLIVE_GREEN   0x5F6F52
# define LAUREL_GREEN       0xA9B388
# define CORNSILK           0xFEFAE0
# define LEMON_MERINGUE     0xF9EBC7
# define CAMEL              0xB99470
# define ALLOY_ORANGE       0xC4661F
# define RUSSET             0x783D19
# define ENDLESS_SEA        0x32586E

# define TEXT_COLOR 0xEAEAEA
# define BACK_COLOR 0x242424
# define MENU_COLOR 0x424242

# define PEAK_COLOR LAUREL_GREEN
# define LAND_COLOR	LEMON_MERINGUE
# define BOTTOM_COLOR	ENDLESS_SEA

# define MIN 0
# define MID 1
# define MAX 2

int	gradient(int start_color, int end_color, const float arr[3]);

#endif