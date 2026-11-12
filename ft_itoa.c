/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaait-mo <zaait-mo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 08:12:04 by zaait-mo          #+#    #+#             */
/*   Updated: 2026/11/07 09:41:29 by zaait-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

static void	fill_nbr(long n, char *dest, int stop, int digit_nbr)
{
	int	counter;

	counter = digit_nbr - 1;
	if (n < 0)
		n *= -1;
	while (counter >= stop)
	{
		dest[counter] = (n % 10) + '0';
		n /= 10;
		counter--;
	}
}

char	*ft_itoa(int n)
{
	long	nb;
	int		stop;
	int		digit_nbr;
	char	*nbr_string;

	nb = n;
	if (nb >= 0)
		digit_nbr = count_digits(nb);
	else
		digit_nbr = count_digits(nb) + 1;
	nbr_string = malloc(digit_nbr + 1);
	if (nbr_string == NULL)
		return (NULL);
	nbr_string[digit_nbr] = '\0';
	if (nb < 0)
		nbr_string[0] = '-';
	if (nb >= 0)
		stop = 0;
	else
		stop = 1;
	fill_nbr(nb, nbr_string, stop, digit_nbr);
	return (nbr_string);
}
