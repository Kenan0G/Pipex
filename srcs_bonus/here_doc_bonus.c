/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:50:45 by kgezgin           #+#    #+#             */
/*   Updated: 2023/05/02 10:16:12 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	here_doc(char *limiter, t_data *data)
{
	char	*line;

	data->fd_infile = open_here_doc(data);
	while (1)
	{
		write(1, "> ", 1);
		line = get_next_line(1, 0);
		if ((ft_strlen(line) - 1 == ft_strlen(limiter))
			&& ft_strncmp(line, limiter, ft_strlen(line) - 1) == 0)
			break ;
		if (line)
			ft_putstr_fd(line, data->fd_infile);
		free(line);
	}
	get_next_line(1, 1);
	if (line)
		free(line);
	close(data->fd_infile);
}

int	open_here_doc(t_data *data)
{
	int	fd;

	fd = open(".here_doc_tmp", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		unlink(".here_doc_tmp");
		fd = open(".here_doc_tmp", O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
		{
			close(data->fd_pipe[1]);
			perror(data->av[1]);
			free(data->pid);
			exit (EXIT_FAILURE);
		}
	}
	return (fd);
}
