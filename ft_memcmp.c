/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaait-mo <zaait-mo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 20:00:13 by zaait-mo          #+#    #+#             */
/*   Updated: 2026/11/07 10:11:28 by zaait-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr_s1;
	const unsigned char	*ptr_s2;
	size_t				counter;

	ptr_s1 = s1;
	ptr_s2 = s2;
	counter = 0;
	if (s1 == s2)
		return (0);
	while (counter < n)
	{
		if (ptr_s1[counter] != ptr_s2[counter])
			return (ptr_s1[counter] - ptr_s2[counter]);
		counter++;
	}
	return (0);
}
