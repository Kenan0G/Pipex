/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:16:17 by kgezgin           #+#    #+#             */
/*   Updated: 2023/03/09 09:52:01 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	get_path(char **envp, t_data *data)
{
	int	i;

	i = data->index + 2;
	ft_path(envp, data);
	data->cmd = ft_split(data->av[i], ' ');
	if (is_path(data->av[i]) == 0)
		data->path = path_check(data);
	else
		data->path = ft_strdup(data->av[i]);
	if (data->path_begining)
		ft_free_map(data->path_begining);
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

char	*path_check(t_data *data)
{
	char	*good_path;
	char	*temp;
	int		i;

	i = 0;
	if (!data->cmd[0])
	{
		ft_putstr_fd("Command '' not found", 1);
		ft_error(data, 127);
	}
	temp = ft_strjoin("/", data->cmd[0]);
	if (access(data->av[data->index + 2], X_OK) == 0)
		return (ft_strdup(data->av[data->index + 2]));
	while (data->path_begining && data->path_begining[i])
	{
		good_path = ft_strjoin(data->path_begining[i],temp);
		if (access(good_path, X_OK) == 0)
			return (free(temp), good_path);
		free(good_path);
		i++;
	}
	free(temp);
	ft_putstr_fd("Command '", 2);
	ft_putstr_fd(data->cmd[0], 2);
	ft_putstr_fd("' not found \n", 2);
	ft_error(data, 127); 
	return (NULL);
}

void	ft_path(char **envp, t_data *data)
{
	int		i;

	i = 0;
	while (envp && envp[i] && ft_strncmp(envp[i], "PATH=", 5))
		i++;
	if (envp && !envp[i])
		return ;
	data->path_begining = ft_split(envp[i] + 5, ':');
}