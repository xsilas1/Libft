/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaait-mo <zaait-mo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 08:05:53 by zaait-mo          #+#    #+#             */
/*   Updated: 2026/11/01 12:50:50 by zaait-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	substr_len;
	size_t	counter;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	substr_len = 0;
	while (start < s_len && substr_len < len && s[start + substr_len])
		substr_len++;
	substr = malloc(substr_len + 1);
	if (substr == NULL)
		return (NULL);
	counter = 0;
	while (counter < substr_len && s[start + counter])
	{
		substr[counter] = s[start + counter];
		counter++;
	}
	substr[counter] = '\0';
	return (substr);
}
