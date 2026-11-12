/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaait-mo <zaait-mo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:54:07 by zaait-mo          #+#    #+#             */
/*   Updated: 2026/11/06 20:44:29 by zaait-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	size_t				counter;

	ptr = s;
	counter = 0;
	while (counter < n)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		counter++;
		ptr++;
	}
	return (NULL);
}
