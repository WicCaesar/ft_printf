/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 03:58:29 by cnascime          #+#    #+#             */
/*   Updated: 2022/08/10 07:18:26 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_places(unsigned long number);

// Same as itoa, but for positive values only.
char	*ft_utoa(unsigned int n)
{
	unsigned long	number;
	size_t	places;
	char	*string;

	number = n;
	places = ft_places(number);
	string = (char *)ft_calloc(sizeof(*string) * (places), 1);
	if (!string)
		return (NULL);
	while (places-- != 0)
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
static int	ft_places(unsigned long number)
{
	size_t	places;

	places = 0;
	if (number <= 0)
		places++;
	while (number > 0)
	{
		places++;
		number /= 10;
	}
	places++;
	return (places);
}
