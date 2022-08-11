/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 05:48:08 by cnascime          #+#    #+#             */
/*   Updated: 2022/08/11 05:11:21 by cnascime         ###   ########.fr       */
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

int	ft_putunsint(unsigned int number)
{
	int		places;
	char	*convert;

	convert = ft_utoa(number);
	places = ft_putstr_fd(1, convert);
	free (convert);
	return (places);
}

int	ft_puthex(char lettercase, int number)
{
	int		places;
	char	*convert;

	convert = ft_htoa(lettercase, number);
	places = ft_putstr_fd(1, convert);
	free (convert);
	return (places);
}

int	ft_putpointer(unsigned long long number)
{
	int		places;
	char	*convert;
	char	*temp;

	convert = ft_ptoa(number);
	temp = ft_strjoin("0x", convert);
	places = ft_putstr_fd(1, temp);
	free (convert);
	free (temp);
	return (places);
}
