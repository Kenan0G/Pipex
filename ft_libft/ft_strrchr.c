/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:56:38 by kgezgin           #+#    #+#             */
/*   Updated: 2022/11/18 10:03:26 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*pointer;

	i = ft_strlen(s);
	pointer = (char *)s;
	while (i != -1)
	{
		if (s[i] == (char)c)
			return (&pointer[i]);
		i--;
	}
	return (0);
}
