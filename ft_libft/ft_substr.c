/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:35:38 by kgezgin           #+#    #+#             */
/*   Updated: 2022/11/21 13:15:31 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static char	*ft_malloc(char const *s, unsigned int start, size_t len)
{
	char	*new_str;

	if (len > ft_strlen(s))
		new_str = malloc(sizeof(*new_str) * (ft_strlen(s) + 1));
	else if (len > start && len > ft_strlen(&s[start]))
		new_str = malloc(sizeof(*new_str) * ft_strlen(&s[start]) + 1);
	else
		new_str = malloc(sizeof(*new_str) * (len + 1));
	return (new_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (len == 0 || start > ft_strlen(s))
	{
		new_str = malloc (sizeof(char));
		new_str[0] = '\0';
		return (new_str);
	}
	new_str = ft_malloc(s, start, len);
	if (!new_str)
		return (NULL);
	while (s[start + i] && i < len)
	{
		new_str[i] = s[start + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

/*
int main()
{
	printf("[%s]\n", ft_substr("aaabbbccc", 4, 2));
	return (0);
}
*/