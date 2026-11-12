/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaait-mo <zaait-mo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 08:10:18 by zaait-mo          #+#    #+#             */
/*   Updated: 2026/11/06 15:05:53 by zaait-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char sep)
{
	int	in_word;
	int	word_count;
	int	counter;

	in_word = 0;
	word_count = 0;
	counter = 0;
	while (s[counter])
	{
		if (s[counter] == sep)
			in_word = 0;
		if (s[counter] != sep && in_word == 0)
		{
			in_word = 1;
			word_count++;
		}
		counter++;
	}
	return (word_count);
}

static void	fct_free(char **arr, int count)
{
	int	index;

	index = 0;
	while (index < count)
	{
		free(arr[index]);
		index++;
	}
	free(arr);
}

static void	copy_word(char *dest, const char *src, int len)
{
	int	index;

	index = 0;
	while (index < len)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
}

static char	*get_word(char const *s, int *pos, char sep)
{
	int		start;
	int		end;
	char	*word;

	while (s[*pos] && s[*pos] == sep)
		(*pos)++;
	if (s[*pos] == '\0')
		return (NULL);
	start = *pos;
	end = start;
	while (s[end] && s[end] != sep)
		end++;
	word = malloc(end - start + 1);
	if (word == NULL)
		return (NULL);
	copy_word(word, s + start, end - start);
	*pos = end;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		counter;
	int		pos;
	int		total_word;
	char	**arr;

	counter = 0;
	pos = 0;
	if (s == NULL)
		return (NULL);
	total_word = word_count(s, c);
	arr = malloc((total_word + 1) * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	while (counter < total_word)
	{
		arr[counter] = get_word(s, &pos, c);
		if (arr[counter] == NULL)
		{
			fct_free(arr, counter);
			return (NULL);
		}
		counter++;
	}
	arr[counter] = NULL;
	return (arr);
}
