/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaait-mo <zaait-mo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 10:54:01 by zaait-mo          #+#    #+#             */
/*   Updated: 2026/11/06 11:12:10 by zaait-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*ptr_src;
	unsigned char		*ptr_dest;
	size_t				counter;

	ptr_src = src;
	ptr_dest = dest;
	if (dest == src || n == 0)
		return (dest);
	if (dest > src)
	{
		counter = n;
		while (counter > 0)
		{
			counter--;
			ptr_dest[counter] = ptr_src[counter];
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
