/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaait-mo <zaait-mo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 20:28:33 by zaait-mo          #+#    #+#             */
/*   Updated: 2026/11/01 11:56:44 by zaait-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	big_c;
	size_t	little_c;

	if (*little == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	big_c = 0;
	while (big_c < len && big[big_c])
	{
		little_c = 0;
		while (big_c + little_c < len
			&& little[little_c] && big[big_c + little_c]
			&& big[big_c + little_c] == little[little_c])
			little_c++;
		if (little[little_c] == '\0')
			return ((char *)&big[big_c]);
		big_c++;
	}
	return (NULL);
}
