/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:16:17 by kgezgin           #+#    #+#             */
/*   Updated: 2023/02/28 10:33:22 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	lst_cmd_init(t_lst_cmd **lst, char **envp, t_data *data)
{
	int	i;

	i = data->index + 2;
	data->path_begining = ft_split(envp[ft_path(envp)] + 5, ':');
	data->path_temp = ft_split(data->av[i], ' ');
	if (is_path(data->av[i]) == 0)
		data->path = path_check(data, lst);
	else
		data->path = ft_strdup(data->av[i]);
	my_lstadd_back(lst, my_lstnew(data->path, data->path_temp));
	ft_free_map(data->path_begining);
}

void	ft_error(t_data *data, t_lst_cmd **lst, int error)
{
	if (data->path_begining)
		ft_free_map(data->path_begining);
	if (data->path_temp)
		ft_free_map(data->path_temp);
	if (lst)
		ft_free_list(lst);
	exit (error);
}


int	is_path(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

char	*path_check(t_data *data, t_lst_cmd **lst)
{
	char	*good_path;
	char	*temp;
	int		i;

	i = 0;
	if (!data->path_temp[0])
	{
		ft_putstr_fd("Command '' not found", 1);
		ft_error(data, lst, 127);
	}
	temp = ft_strjoin("/", data->path_temp[0]);
	while (data->path_begining[i])
	{
		good_path = ft_strjoin(data->path_begining[i],temp);
		if (access(good_path, X_OK) == 0)
			return (free(temp), good_path);
		free(good_path);
		i++;
	}
	free(temp);
	return (NULL);
}

void	print_list(t_lst_cmd *lst)
{
	t_lst_cmd	*temp;
	int			i;

	temp = lst;
	i = 0;
	while (temp)
	{
		ft_printf("cmd = %s\n", temp->cmd[0]);
		ft_printf("path = %s\n", temp->path);
		temp = temp->next;
		i++;
	}
}