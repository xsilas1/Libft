/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaait-mo <zaait-mo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 08:07:13 by zaait-mo          #+#    #+#             */
/*   Updated: 2026/11/01 12:59:59 by zaait-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *s1, char const *s2)
{
	size_t	s2_len;
	size_t	counter1;
	size_t	counter2;

	s2_len = ft_strlen(s2);
	counter1 = ft_strlen(s1);
	counter2 = 0;
	while (counter2 < s2_len)
	{
		s1[counter1 + counter2] = s2[counter2];
		counter2++;
	}
	s1[counter1 + counter2] = '\0';
	return (s1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fullstr;
	size_t	s1_len;
	size_t	s2_len;
	size_t	counter;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	fullstr = malloc(s1_len + s2_len + 1);
	if (fullstr == NULL)
		return (NULL);
	counter = 0;
	while (s1[counter])
	{
		fullstr[counter] = s1[counter];
		counter++;
	}
	fullstr[counter] = '\0';
	return (ft_strcat(fullstr, s2));
}
