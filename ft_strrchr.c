/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaait-mo <zaait-mo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 15:39:33 by zaait-mo          #+#    #+#             */
/*   Updated: 2026/11/07 09:38:24 by zaait-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char				*saved_address;
	unsigned char		*ptr;

	saved_address = NULL;
	ptr = (unsigned char *)s;
	while (*ptr)
	{
		if (*ptr == (unsigned char)c)
			saved_address = (char *)ptr;
		ptr++;
	}
	if ((unsigned char)c == '\0')
		saved_address = (char *)ptr;
	return (saved_address);
}
