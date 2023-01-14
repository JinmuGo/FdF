/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:17:46 by jgo               #+#    #+#             */
/*   Updated: 2023/01/14 17:49:12 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "declaration_bonus.h"
#include "utils_bonus.h"
#include "error_bonus.h"

int	err_terminate_process(char *str)
{
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

void	input_error_handler(int ac, int init_fd)
{
	if (ac != 2)
		err_terminate_process(ERR_ARGS);
	if (init_fd < 2)
		err_terminate_process(ERR_PATH_OPEN);
}

void	allocate_error_handler(void	*ptr)
{
	if (!ptr)
		err_terminate_process(ERR_ALLOCATE);
}

static t_bool	verify_path(const char *path)
{
	const char	**split_arr = (const char **)ft_split(path, '/');
	char		**surfix_arr;
	t_bool		return_val;
	int			i;

	if (!split_arr)
		return (FALSE);
	i = 0;
	while (split_arr[i + 1])
		i++;
	surfix_arr = ft_split(split_arr[i], '.');
	i = 0;
	while (surfix_arr[i + 1])
		i++;
	if (ft_strncmp(surfix_arr[i], "fdf", 4) == 0)
		return_val = TRUE;
	else
		return_val = FALSE;
	free_arr((void *)split_arr);
	free_arr(surfix_arr);
	return (return_val);
}

void	path_error_handler(const char *path)
{
	if (!verify_path(path))
		err_terminate_process(ERR_INVALID_PATH);
}
