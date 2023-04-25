/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:43:59 by kgezgin           #+#    #+#             */
/*   Updated: 2023/04/25 11:48:36 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exec(t_data *data, char **envp)
{
	if (data->index == 0)
		ft_first_cmd(data);
	else
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

void	ft_first_cmd(t_data *data)
{
	data->fd_infile = open(data->av[1], O_RDONLY);
	if (data->fd_infile == -1)
	{
		close(data->fd_pipe[1]);
		perror(data->av[1]);
		exit(EXIT_FAILURE);
	}	
	if (dup2(data->fd_infile, STDIN_FILENO) == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	if (dup2(data->fd_pipe[1], STDOUT_FILENO) == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
}

void	ft_last_cmd(t_data *data)
{
	close(data->fd_pipe[1]);
	data->fd_outfile = open(data->av[4],
			O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (data->fd_outfile == -1)
	{
		close(data->fd_pipe[0]);
		perror("Error");
		exit(EXIT_FAILURE);
	}
	if (dup2(data->fd_pipe[0], STDIN_FILENO) == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	if (dup2(data->fd_outfile, STDOUT_FILENO) == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
}
