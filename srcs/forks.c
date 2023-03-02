/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:43:59 by kgezgin           #+#    #+#             */
/*   Updated: 2023/03/01 15:28:35 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exec(t_lst_cmd **lst, t_data *data, char **envp)
{
	fprintf(stderr, "	index = %d\n", data->index);
	if (data->index == 0)
		ft_first_cmd(data);
	else if (data->index != data->ac - 4 && data->ac > 5)
		ft_middle_cmd(data);
	else
		ft_last_cmd(data);

	lst_cmd_init(lst, envp, data);
	if (execve((*lst)->path, (*lst)->cmd, envp) == -1)
	{
		fprintf(stderr, "execve\n");
		perror((*lst)->next->path);
		ft_free_list(lst);
		exit (1);
	}
}

// void	next_cmd(t_data *data)
// {
// 	if (data->index == data->ac - 4)
// 	{
// 		fprintf(stderr, "next->last_command : %d\n", data->index);
// 		data->fd_outfile = open(data->av[data->ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
// 		if (data->fd_outfile == -1)
// 		{
// 			fprintf(stderr, "open out\n");
// 			perror("Error");
// 			exit (errno);
// 		}
// 		if (dup2(data->fd_outfile, STDOUT_FILENO) == -1)
// 		{
// 			fprintf(stderr, "dup out last\n");
// 			perror("Error");
// 			exit (errno);
// 		}
// 	}
// 	else
// 	{
// 		fprintf(stderr, "next->middle_command : %d\n", data->index);
// 		if (dup2(data->fd_pipe[1], STDOUT_FILENO) == -1)
// 		{
// 			fprintf(stderr, "dup out middle\n");
// 			perror("Error");
// 			exit (errno);
// 		}
// 	}
// }

void	ft_first_cmd(t_data *data)
{
	fprintf(stderr, "ft_first_cmd : %d\n", data->index);
	data->fd_infile = open(data->av[1], O_RDONLY);
	if (data->fd_infile == -1)
	{
			fprintf(stderr, "open in\n");
		perror("Error");
		exit (errno);
	}
	if (dup2(data->fd_infile, STDIN_FILENO) == -1)
	{
		fprintf(stderr, "dup in first\n");
		perror("Error");
		exit (errno);
	}
	if (dup2(data->fd_pipe[1], STDOUT_FILENO) == -1)
	{
		fprintf(stderr, "dup out middle\n");
		perror("Error");
		exit (errno);
	}
	// next_cmd(data);
}

void	ft_middle_cmd(t_data *data)
{
	fprintf(stderr, "ft_middle_cmd : %d\n", data->index);
	if (dup2(data->fd_temp, STDIN_FILENO) == -1)
	{
		fprintf(stderr, "dup in middle_1\n");
		perror("Error");
		exit (errno);
	}
	if (dup2(data->fd_pipe[1], STDOUT_FILENO) == -1)
	{
		fprintf(stderr, "dup out middle\n");
		perror("Error");
		exit (errno);
	}
	// next_cmd(data);
}

void	ft_last_cmd(t_data *data)
{
	fprintf(stderr, "ft_last_cmd : %d\n", data->index);
	// close(data->fd_pipe[1]);
	if (dup2(data->fd_temp_last, STDIN_FILENO) == -1)
	{
		fprintf(stderr, "dup in last\n");
		perror("Error");
		exit (errno);
	}
	if (dup2(data->fd_outfile, STDOUT_FILENO) == -1)
	{
		fprintf(stderr, "dup out last\n");
		perror("Error");
		exit (errno);
	}
}