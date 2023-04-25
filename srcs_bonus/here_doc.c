/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 11:50:45 by kgezgin           #+#    #+#             */
/*   Updated: 2023/04/25 11:35:35 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	here_doc(char *limiter, t_data *data)
{
	char	*line;

	data->fd_infile = open(".here_doc_tmp", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (data->fd_infile == -1)
	{
		close(data->fd_pipe[1]);
		perror(data->av[1]);
		free(data->pid);
		exit (errno);
	}
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(1);
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
			break ;
		if (line)
			ft_putstr_fd(line, data->fd_infile);
		free(line);
	}
	close(data->fd_infile);
}
