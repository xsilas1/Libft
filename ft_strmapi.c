/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaait-mo <zaait-mo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 08:12:53 by zaait-mo          #+#    #+#             */
/*   Updated: 2026/11/04 19:54:12 by zaait-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	size_t			s_len;
	unsigned int	counter;

	if (s == NULL || f == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	new_str = malloc(s_len + 1);
	if (new_str == NULL)
		return (NULL);
	counter = 0;
	while (s[counter] != '\0')
	{
		new_str[counter] = f(counter, s[counter]);
		counter++;
	}
	new_str[counter] = '\0';
	return (new_str);
}
