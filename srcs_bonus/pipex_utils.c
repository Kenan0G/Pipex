/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:14:24 by kgezgin           #+#    #+#             */
/*   Updated: 2023/04/25 11:35:41 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_close(t_data *data)
{
	if (data->fd_infile)
		close(data->fd_infile);
	if (data->fd_outfile)
		close(data->fd_outfile);
	if (data->fd_pipe[0])
		close(data->fd_pipe[0]);
	if (data->fd_pipe[1])
		close(data->fd_pipe[1]);
	if (data->fd_temp)
		close(data->fd_temp);
	if (data->fd_temp_last)
		close(data->fd_temp_last);
}

void	ft_wait(t_data *data, int ac)
{
	int	i;

	i = 0;
	if (data->here_doc == 1)
	{
		while (i < ac - 4)
		{
			waitpid(data->pid[i], NULL, 0);
			i++;
		}
	}
	else
	{
		while (i < ac - 3)
		{
			waitpid(data->pid[i], NULL, 0);
			i++;
		}
	}
	free(data->pid);
}
