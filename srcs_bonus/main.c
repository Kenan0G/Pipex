/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:12:51 by kgezgin           #+#    #+#             */
/*   Updated: 2023/04/25 11:35:37 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	t_data		data;

	data_init(&data, ac, av);
	if ((data.here_doc == 0 && ac < 5) || (data.here_doc == 1 && ac < 6))
		return (ft_putstr_fd("Error\narguments", 2), free(data.pid), 0);
	ft_loop(&data, envp);
	ft_close(&data);
	ft_wait(&data, ac);
	return (0);
}

void	data_init(t_data *data, int ac, char **av)
{
	ft_memset(data, 0, sizeof(t_data));
	data->pid = malloc (sizeof(pid_t) * (ac - 3));
	data->ac = ac;
	data->av = av;
	data->index = 0;
	if (strncmp("here_doc", av[1], 8) == 0)
		data->here_doc = 1;
	else
		data->here_doc = 0;
}

void	ft_loop(t_data *data, char **envp)
{
	while (data->index < data->ac - 3)
	{
		if (data->index + 1 < data->ac - 3)
		{
			data->fd_temp = data->fd_pipe[0];
			if (pipe(data->fd_pipe) == -1)
				ft_putstr_fd("fail_pipe\n", 2);
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
	(void)error;
	if (data->path_begining)
		ft_free_map(data->path_begining);
	if (data->cmd)
		ft_free_map(data->cmd);
	if (data->pid)
		free(data->pid);
	if (data->path)
		free (data->path);
	exit (EXIT_FAILURE);
}
