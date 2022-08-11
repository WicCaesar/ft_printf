/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 03:58:29 by cnascime          #+#    #+#             */
/*   Updated: 2022/08/11 08:02:36 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

// Same as itoa, but for positive values only.
char	*ft_utoa(unsigned int n)
{
	unsigned long	number;
	size_t			places;
	char			*string;

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

// Same as utoa, but in base 16. Different counting/handling of decimal places.
char	*ft_htoa(char lettercase, unsigned int n)
{
	unsigned long	number;
	size_t			places;
	char			*base;
	char			*string;

	if (lettercase >= 'A' && lettercase <= 'Z')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	number = n;
	places = 1;
	while (number > 15)
	{
		number /= 16;
		places++;
	}
	number = n;
	string = ft_calloc(sizeof(char) * (places + 1), 1);
	string[places] = '\0';
	while (places--)
	{
		string[places] = base[number % 16];
		number /= 16;
	}
	return (string);
}

// Same as utoa, but in base 16. Different counting/handling of decimal places.
char	*ft_ptoa(unsigned long long n)
{
	unsigned long long	number;
	size_t				places;
	char				*base;
	char				*string;

	base = "0123456789abcdef";
	number = n;
	places = 1;
	while (number > 15)
	{
		number /= 16;
		places++;
	}
	number = n;
	string = ft_calloc(sizeof(char) * (places + 1), 1);
	string[places] = '\0';
	while (places--)
	{
		string[places] = base[number % 16];
		number /= 16;
	}
	return (string);
}
