/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaait-mo <zaait-mo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 08:08:26 by zaait-mo          #+#    #+#             */
/*   Updated: 2026/11/01 13:07:05 by zaait-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set += 1;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmedstr;
	size_t	c_start;
	size_t	c_end;
	size_t	c_copy;

	if (s1 == NULL || set == NULL)
		return (NULL);
	c_start = 0;
	c_end = ft_strlen(s1);
	while (s1[c_start] && is_set(s1[c_start], set))
		c_start++;
	while (c_end > c_start && is_set(s1[c_end - 1], set))
		c_end--;
	trimmedstr = malloc(c_end - c_start + 1);
	if (trimmedstr == NULL)
		return (NULL);
	c_copy = 0;
	while (c_start < c_end)
	{
		trimmedstr[c_copy] = s1[c_start];
		c_start++;
		c_copy++;
	}
	trimmedstr[c_copy] = '\0';
	return (trimmedstr);
}
