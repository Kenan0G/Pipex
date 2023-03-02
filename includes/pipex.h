/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 10:46:11 by kgezgin           #+#    #+#             */
/*   Updated: 2023/03/01 18:27:08 by kgezgin          ###   ########.fr       */
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

typedef struct	s_lst_cmd
{
	char				**cmd;
	char				*path;
	struct s_lst_cmd	*next;
}				t_lst_cmd;

typedef struct	s_data
{
	pid_t	*pid;
	char	**path_begining;
	char	**path_temp;
	char 	*path;
	int 	ac;
	char	**av;
	int		fd_infile;
	int		fd_outfile;
	int		fd_temp;
	int		fd_temp_last;
	int		fd_pipe[2];
	int		error_infile;
	int		error_outfile;
	int		error_cmd;
	int		index;
}				t_data;

void		my_lstadd_back(t_lst_cmd **lst, t_lst_cmd *new);
t_lst_cmd	*my_lstnew(void *content, void *content_2);
void		ft_free_list(t_lst_cmd **lst);
void		ft_free_map(char **str);

void		next_cmd(t_data *data);
void	ft_first_cmd(t_data *data);
void	ft_middle_cmd(t_data *data);
void	ft_last_cmd(t_data *data);


void	ft_loop(t_lst_cmd **lst, t_data *data, char **envp);
int		ft_path(char **envp);

void	lst_cmd_init(t_lst_cmd **lst, char **envp, t_data *data);
void	ft_error(t_data *data, t_lst_cmd **lst, int error);
int		is_path(char *str);
char	*path_check(t_data *data, t_lst_cmd **lst);
void	print_list(t_lst_cmd *lst);

void	exec(t_lst_cmd **lst, t_data *data, char **envp);


#endif