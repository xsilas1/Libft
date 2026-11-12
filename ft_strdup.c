/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaait-mo <zaait-mo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 22:00:00 by zaait-mo          #+#    #+#             */
/*   Updated: 2026/11/01 12:00:57 by zaait-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	length;
	size_t	counter;
	char	*copy;

	length = ft_strlen(s);
	counter = 0;
	copy = malloc(length + 1);
	if (copy == NULL)
		return (NULL);
	while (s[counter])
	{
		copy[counter] = s[counter];
		counter++;
	}
	copy[counter] = '\0';
	return (copy);
}
