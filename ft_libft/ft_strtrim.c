/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:00:04 by kgezgin           #+#    #+#             */
/*   Updated: 2022/11/18 10:13:56 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	int		len;
	char	*res;

	i = 0;
	j = 0;
	k = 0;
	len = ft_strlen(s1);
	while (s1[i] != '\0' && ft_isset(s1[i], set))
		i++;
	while (ft_isset(s1[len - j - 1], set) && i < len)
		j++;
	res = malloc(sizeof(*res) * (ft_strlen(s1) - (i + j) + 1));
	if (!res)
		return (NULL);
	while (i < (len - j))
	{
		res[k] = s1[i];
		k++;
		i++;
	}
	res[k] = '\0';
	return (res);
}
/*
int	main()
{
	char	const *s1 = "abcwdw";
	char 	const *set = "-";
	char	*str = ft_strtrim(s1, set);

	printf("[%s]\n", str);
	return (0);
}
*/