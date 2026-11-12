/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaait-mo <zaait-mo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 09:48:51 by zaait-mo          #+#    #+#             */
/*   Updated: 2026/11/04 11:55:09 by zaait-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;
	size_t				counter;

	ptr_dest = dest;
	ptr_src = src;
	counter = 0;
	while (counter < n)
	{
		ptr_dest[counter] = ptr_src[counter];
		counter++;
	}
	return (dest);
}
