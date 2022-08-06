/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 16:08:08 by cnascime          #+#    #+#             */
/*   Updated: 2022/08/06 16:56:27 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main(void)
{
	char	character;
	char	*string;

	string = "Hello, World!%%%%\n";
	character = 'W';
	ft_printf(string);
	ft_printf("Hello, World!%%%%\n");
	ft_printf("%c\n", character);
	printf("%c\n", character);
	return (0);
}
