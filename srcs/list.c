/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:19:08 by kgezgin           #+#    #+#             */
/*   Updated: 2023/02/23 15:02:31 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	my_lstadd_back(t_lst_cmd **lst, t_lst_cmd *new)
{	
	t_lst_cmd	*current_node;

	current_node = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (current_node->next != NULL)
		current_node = current_node->next;
	current_node->next = new;
}

t_lst_cmd	*my_lstnew(void *content, void *content_2)
{
	t_lst_cmd	*liste;

	liste = malloc(sizeof(*liste));
	liste->path = content;
	liste->cmd = content_2;
	liste->next = NULL;
	return (liste);
}

void	ft_free_list(t_lst_cmd **lst)
{
	t_lst_cmd	*temp;

	while (*lst)
	{
		temp = *lst;
		*lst = (*lst) -> next;
		ft_free_map(temp->cmd);
		free(temp->path);
		free(temp);
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
	free(str);
}
