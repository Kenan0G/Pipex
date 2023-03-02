/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:12:51 by kgezgin           #+#    #+#             */
/*   Updated: 2023/03/02 09:48:59 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_loop(t_lst_cmd **lst, t_data *data, char **envp)
{
	data->index = 0;
	data->fd_temp = -1;
	while (data->index < data->ac - 3)
	{
		if (data->index + 1 < data->ac - 3)
		{
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
			exec(lst, data, envp);
		data->fd_temp = data->fd_pipe[1];
		data->index++;
	}
		close(data->fd_temp);
		close(data->fd_temp_last);
}

int	main(int ac, char **av, char **envp)
{
	t_data		data;
	t_lst_cmd	*lst;

	lst = NULL;
	if (ac <=  4)
		return (ft_printf("arguments < 4\n"), 0);
	ft_memset(&data, 0, sizeof(t_data));
	data.pid = malloc (sizeof(pid_t) * (ac - 3));
	data.ac = ac;
	data.av = av;

	ft_loop(&lst, &data, envp);

	close(data.fd_pipe[0]);
	close(data.fd_pipe[1]);
	int i = 0;
	while (i < ac - 3)
	{
		waitpid(data.pid[i], NULL, 0);
		i++;
	}
	ft_free_list(&lst);
	return (0);
}


int	ft_path(char **envp)
{
	int		i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	return (i);
}