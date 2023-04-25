/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:46:11 by kgezgin           #+#    #+#             */
/*   Updated: 2023/04/25 11:56:20 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include"../ft_libft/libft.h"
# include"../ft_printf/ft_printf.h"
# include"../get_next_line/get_next_line.h"

typedef struct s_data
{
	pid_t	pid_1;
	pid_t	pid_2;
	char	**path_begining;
	char	**cmd;
	char	*path;
	int		ac;
	char	**av;
	int		fd_infile;
	int		fd_outfile;
	int		fd_pipe[2];
	int		error_infile;
	int		error_outfile;
	int		error_cmd;
	int		index;
}				t_data;

void	data_init(t_data *data, int ac, char **av);
void	ft_forks(t_data *data, char **envp);
void	ft_free_map(char **str);
void	ft_error(t_data *data, int error);

void	get_path(char **envp, t_data *data);
int		is_path(char *str);
char	*path_check(t_data *data);
void	ft_path(char **envp, t_data *data);
void	ft_error_path(t_data *data, char *temp);

void	exec(t_data *data, char **envp);
void	ft_first_cmd(t_data *data);
void	ft_middle_cmd(t_data *data);
void	ft_last_cmd(t_data *data);

void	here_doc(char *limiter, t_data *data);
void	open_infile(t_data *data);

void	ft_close(t_data *data);
void	ft_pid_1(t_data *data, char **envp);
void	ft_pid_2(t_data *data, char **envp);

#endif