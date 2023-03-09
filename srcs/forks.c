/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:43:59 by kgezgin           #+#    #+#             */
/*   Updated: 2023/03/09 09:56:49 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exec(t_data *data, char **envp)
{
	if (data->index == 0)
		ft_first_cmd(data, envp);
	else if (data->index != data->ac - 4 && data->ac > 5)
		ft_middle_cmd(data, envp);
	else
		ft_last_cmd(data, envp);

	if (execve(data->path, data->cmd, envp) == -1)
	{
		perror(data->path);
		ft_error(data, errno);
	}
}

void	ft_first_cmd(t_data *data, char **envp)
{
	close (data->fd_pipe[0]);
	data->fd_infile = open(data->av[1], O_RDONLY);
	if (data->fd_infile == -1)
	{
		perror(data->av[1]);
		exit (errno);
	}
	get_path(envp, data);
	if (dup2(data->fd_infile, STDIN_FILENO) == -1)
	{
		perror("Error");
		exit (errno);
	}
	if (dup2(data->fd_pipe[1], STDOUT_FILENO) == -1)
	{
		perror("Error");
		exit (errno);
	}
}

void	ft_middle_cmd(t_data *data, char **envp)
{
	close (data->fd_pipe[0]);
	get_path(envp, data);
	if (dup2(data->fd_temp, STDIN_FILENO) == -1)
	{
		perror("Error");
		exit (errno);
	}
	if (dup2(data->fd_pipe[1], STDOUT_FILENO) == -1)
	{
		perror("Error");
		exit (errno);
	}
}

void	ft_last_cmd(t_data *data, char **envp)
{

	data->fd_outfile = open(data->av[data->ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (data->fd_outfile == -1)
	{
		perror("Error");
		exit (errno);
	}
	get_path(envp, data);
	if (dup2(data->fd_temp_last, STDIN_FILENO) == -1)
	{
		perror("Error");
		exit (errno);
	}
	if (dup2(data->fd_outfile, STDOUT_FILENO) == -1)
	{
		perror("Error");
		exit (errno);
	}
}