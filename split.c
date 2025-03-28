/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavorapa <pavorapa@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-28 16:28:16 by pavorapa          #+#    #+#             */
/*   Updated: 2025-03-28 16:28:16 by pavorapa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(char *s, char c)
{
	int		count;
	bool	inside;

	count = 0;
	while (*s)
	{
		inside = false;
		while (*s == c)
			++s;
		while (*s != c && *s)
		{
			if (!inside)
			{
				++count;
				inside = true;
			}
			++s;
		}
	}
	return (count);
}

static char	*get_next_word(char *s, char c)
{
	static int	curse = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[curse] == c)
		++curse;
	while ((s[curse + len] != c) && s[curse + len])
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((s[curse] != c && s[curse++]))
		next_word[i++] = s[curse++];
	next_word[i] = '\0';
	return (next_word);
}

char	**split(char *s, char c)
{
	int words_count;
	char **res_array;
	int i;

	i = 0;
	words_count = count_words(s, c);
	if (!words_count)
		exit(1);
	res_array = malloc(sizeof(char *) * (size_t)(words_count + 2));
	if (!res_array)
		return (NULL);
	while (words_count-- >= 0)
	{
		if (i == 0)
		{
			res_array[i] = malloc(sizeof(char));
			if (!res_array[i])
				return (NULL);
			res_array[i++][0] = '\0';
			continue ;
		}
		res_array[i++] = get_next_word(s, c);
	}
	res_array[i] = NULL;
	return (res_array);
}