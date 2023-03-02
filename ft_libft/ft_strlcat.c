/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:00:35 by kgezgin           #+#    #+#             */
/*   Updated: 2022/11/14 18:58:18 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dstsize;

	dstsize = ft_strlen(dst);
	i = dstsize;
	if (size == 0)
		return (ft_strlen(src));
	if (size < dstsize)
		return (size + ft_strlen(src));
	j = 0;
	if (size > i)
	{
		while ((size - i > 1) && src[j] != '\0')
		{
			dst[i] = src[j];
			i++;
			j++;
		}
	}
	dst[i] = '\0';
	while (src[j] != '\0')
		j++;
	return (dstsize + j);
}

/*
int	main()
{
	char	dest[50] = "4444";
	const	char *src = "333";
	int		n = 9;
	printf("[%ld]\n", ft_strlcat(dest, src, n));
	return (0);	
}
*/