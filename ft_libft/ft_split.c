/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 14:13:08 by kgezgin           #+#    #+#             */
/*   Updated: 2022/11/15 14:09:43 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_isset(char c, char set)
{
	if (c == set)
		return (1);
	return (0);
}

static int	ft_word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && ft_isset(s[i], c))
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && !ft_isset(s[i], c))
			i++;
	}
	return (count);
}

static int	ft_wordlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && !ft_isset(s[i], c))
		i++;
	return (i);
}

static char	*ft_create_word(char const *s, char c)
{
	int		i;
	int		len_word;
	char	*word;

	i = 0;
	len_word = ft_wordlen(s, c);
	word = malloc(sizeof(*word) * (len_word + 1));
	if (!word)
		return (0);
	while (i < len_word)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**split;

	i = 0;
	split = malloc(sizeof(char *) * (ft_word_count(s, c) + 1));
	if (!split)
		return (NULL);
	while (*s != '\0')
	{
		while (*s != '\0' && ft_isset(*s, c))
			s++;
		if (*s != '\0')
		{
			split[i] = ft_create_word(s, c);
			i++;
		}
		while (*s != '\0' && !ft_isset(*s, c))
			s++;
	}
	split[i] = NULL;
	return (split);
}

/*
int main()
{
	int	i;
	char	**split = ft_split("undeucxtrois", 'c');

	i = 0;
	while (split[i] != 0)
  {
      printf("[%s]\n", split[i]);
      ++i;
  }

	return(0);
}
*/