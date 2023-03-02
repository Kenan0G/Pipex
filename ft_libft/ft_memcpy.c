/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:28:53 by kgezgin           #+#    #+#             */
/*   Updated: 2022/11/12 13:26:24 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*str;
	const char	*str2;

	i = 0;
	str = dest;
	str2 = src;
	while (i < n)
	{
		str[i] = str2[i];
		i++;
	}
	return (dest);
}
