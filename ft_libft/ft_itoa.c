/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 15:19:59 by kgezgin           #+#    #+#             */
/*   Updated: 2022/11/15 14:46:55 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static char	*ft_convert(int n, int len, int sign)
{
	char			*str;
	unsigned int	x;

	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (sign)
	{
		*str = '-';
		x = -n;
	}
	else
		x = n;
	str[len] = '\0';
	len--;
	while (len >= sign)
	{
		str[len] = (x % 10) + 48;
		x = x / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	int		temp;
	int		sign;

	len = 0;
	sign = 0;
	if (n < 0)
	{
		len++;
		sign++;
	}
	temp = n;
	while (temp != 0)
	{
		temp = temp / 10;
		len++;
	}
	if (n == 0)
		len++;
	return (ft_convert(n, len, sign));
}

/*
int	main(void)
{
	printf("resultat :[%s]\n", ft_itoa(10));
	return (0);
}
*/