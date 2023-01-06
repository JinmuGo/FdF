/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:50:02 by jgo               #+#    #+#             */
/*   Updated: 2023/01/01 16:02:26 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define ERR_ARGS "❌Incorrect number of arguments"
# define ERR_PATH_OPEN "❌Unable to open the file for that path"
# define ERR_LINE_LEN "❌Each line has a different length"
# define ERR_ALLOCATE "❌Memory allocation failed"
# define ERR_INVALID_MAP "❌This map is an invalid"
# define ERR_INVALID_PATH "❌This path is an invalid"


int err_terminate_process(char *str);

#endif