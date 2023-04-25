/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:14:24 by kgezgin           #+#    #+#             */
/*   Updated: 2023/04/25 11:55:46 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
}

void	ft_pid_1(t_data *data, char **envp)
{	
	data->pid_1 = fork();
	if (data->pid_1 == 0)
	{
		ft_first_cmd(data);
		get_path(envp, data);
		if (execve(data->path, data->cmd, envp) == -1)
		{
			ft_close(data);
			perror(data->path);
			if (data->cmd)
				ft_free_map(data->cmd);
			if (data->path)
				free(data->path);
			exit(EXIT_FAILURE);
		}
	}
}

void	ft_pid_2(t_data *data, char **envp)
{	
	data->pid_2 = fork();
	if (data->pid_2 == 0)
	{
		ft_last_cmd(data);
		get_path(envp, data);
		if (execve(data->path, data->cmd, envp) == -1)
		{
			ft_close(data);
			perror(data->path);
			if (data->cmd)
				ft_free_map(data->cmd);
			if (data->path)
				free(data->path);
			exit(EXIT_FAILURE);
		}
	}
}
