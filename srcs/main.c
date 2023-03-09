/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:12:51 by kgezgin           #+#    #+#             */
/*   Updated: 2023/03/09 09:56:14 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_data		data;
	int i;
	
	i = 0;
	if (ac <=  4)
		return (ft_printf("arguments < 4\n"), 0);
	ft_memset(&data, 0, sizeof(t_data));
	data.pid = malloc (sizeof(pid_t) * (ac - 3));
	data.ac = ac;
	data.av = av;
	data.index = 0;
	data.fd_pipe[0] = -1;
	data.fd_temp = -1;
	ft_loop(&data, envp);
	close(data.fd_pipe[0]);
	close(data.fd_pipe[1]);
	while (i < ac - 3)
	{
		waitpid(data.pid[i], NULL, 0);
		i++;
	}
	free(data.pid);
	return (0);
}

void	ft_loop(t_data *data, char **envp)
{
	while (data->index < data->ac - 3)
	{
		if (data->index + 1 < data->ac - 3)
		{
			data->fd_temp = data->fd_pipe[0];
			if (pipe(data->fd_pipe) == -1)
				fprintf(stderr, "fail_pipe\n");
		}
		else
		{
			data->fd_temp_last = data->fd_pipe[0];
			close(data->fd_pipe[1]);
		}
		data->pid[data->index] = fork();
		if (data->pid[data->index] == 0)
			exec(data, envp);
		if (data->fd_temp > 0)
			close(data->fd_temp);
		if (data->fd_pipe[1] > 0)
			close(data->fd_pipe[1]);
		data->index++;
	}
}

void	ft_free_map(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	if (str)
		free(str);
}

void	ft_error(t_data *data, int error)
{
	if (data->path_begining)
		ft_free_map(data->path_begining);
	if (data->cmd)
		ft_free_map(data->cmd);
	if (data->pid)
		free(data->pid);
	if (data->path)
		free (data->path);
	exit (error);
}
