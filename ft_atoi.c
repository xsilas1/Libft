/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaait-mo <zaait-mo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/28 20:51:43 by zaait-mo          #+#    #+#             */
/*   Updated: 2026/11/06 15:54:58 by zaait-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long	result;
	int		sign;
	int		counter;

	result = 0;
	sign = 1;
	counter = 0;
	while ((nptr[counter] >= 9 && nptr[counter] <= 13) || nptr[counter] == ' ')
		counter++;
	if (nptr[counter] == '-' || nptr[counter] == '+')
	{
		if (nptr[counter] == '-')
			sign *= -1;
		counter++;
	}
	while (nptr[counter] >= '0' && nptr[counter] <= '9')
	{
		if (result > (LONG_MAX - (nptr[counter] - '0')) / 10)
			return (-(sign == 1));
		result = (result * 10) + nptr[counter] - '0';
		counter++;
	}
	return ((int)(result * sign));
}
