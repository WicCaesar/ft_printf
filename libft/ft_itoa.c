/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 03:58:29 by cnascime          #+#    #+#             */
/*   Updated: 2022/06/09 21:01:38 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_places(long number);

// Simply counts the amount of decimal places there'll be in the final integer.
// Also checks if it's a negative and saves a space for the minus operator.
char	*ft_itoa(int n)
{
	long	number;
	size_t	places;
	char	*string;

	number = n;
	places = ft_places(number);
	string = (char *)ft_calloc(sizeof(*string) * (places), 1);
	if (!string)
		return (NULL);
	if (number < 0)
	{
		string[0] = '-';
		number *= -1;
	}
	while (places-- >= 0)
	{
		if (number / 10 < 1)
			break ;
		string[places - 1] = number % 10 + '0';
		number /= 10;
	}
	string[places - 1] = number + '0';
	return (string);
}

// Calculates how many decimal places the string'll need.
static int	ft_places(long number)
{
	size_t	places;

	places = 0;
	if (number <= 0)
	{
		places++;
		number *= -1;
	}
	while (number > 0)
	{
		places++;
		number /= 10;
	}
	places++;
	return (places);
}
