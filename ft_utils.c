/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 05:48:08 by cnascime          #+#    #+#             */
/*   Updated: 2022/08/10 07:24:55 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "./libft/libft.h"

// Converts number to string, calculates and returns the size of said string.
int	ft_putint(int number)
{
	int		places;
	char	*convert;

	convert = ft_itoa(number);
	places = ft_putstr_fd(1, convert);
	free (convert);
	return (places);
}

int	ft_putunsint(int number)
{
	int		places;
	char	*convert;

	convert = ft_utoa(number);
	places = ft_putstr_fd(1, convert);
	free (convert);
	return (places);
}