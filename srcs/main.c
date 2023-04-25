/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:12:51 by kgezgin           #+#    #+#             */
/*   Updated: 2023/04/25 11:56:02 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int ac, char **av, char **envp)
{
	t_data		data;

	data_init(&data, ac, av);
	if (ac != 5)
		return (ft_putstr_fd("Error\narguments", 2), 0);
	ft_forks(&data, envp);
	ft_close(&data);
	waitpid(data.pid_1, NULL, 0);
	waitpid(data.pid_2, NULL, 0);
	return (0);
}

void	data_init(t_data *data, int ac, char **av)
{
	ft_memset(data, 0, sizeof(t_data));
	data->ac = ac;
	data->av = av;
	data->index = 0;
}

void	ft_forks(t_data *data, char **envp)
{
	if (pipe(data->fd_pipe) == -1)
		ft_putstr_fd("fail_pipe\n", 2);
	ft_pid_1(data, envp);
	data->index += 1;
	ft_pid_2(data, envp);
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
	if (data->path)
		free (data->path);
	exit (EXIT_FAILURE);
}
