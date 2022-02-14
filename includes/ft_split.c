/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baubigna <baubigna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 14:11:54 by baubigna          #+#    #+#             */
/*   Updated: 2022/02/06 14:12:46 by baubigna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static unsigned int	ft_count_word(const char *s, char c)
{
	unsigned int	count;
	unsigned int	trigger;

	count = 0;
	trigger = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s != c && trigger == 0)
		{
			trigger = 1;
			count++;
		}
		else if (*s == c)
			trigger = 0;
		s++;
	}
	return (count);
}

static char	*ft_wordup(const char *s, int k, int i)
{
	char	*word;
	int		l;

	l = 0;
	word = (char *)malloc(sizeof(char) * (i - k + 1));
	while (k < i)
		word[l++] = s[k++];
	word[l] = '\0';
	return (word);
}

static char	**ft_write_word(char **split, char const *s, char c)
{
	size_t	i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && k == -1)
			k = i;
		else if ((s[i] == c || i == ft_strlen(s)) && k >= 0)
		{
			split[j++] = ft_wordup(s, k, i);
			k = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char			**split;
	unsigned int	word_count;

	if (!s)
		return (NULL);
	word_count = ft_count_word(s, c);
	split = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!split)
		return (NULL);
	split = ft_write_word(split, s, c);
	return (split);
}
