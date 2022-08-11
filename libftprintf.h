/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:13:09 by cnascime          #+#    #+#             */
/*   Updated: 2022/08/11 05:02:44 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_flags
{
	int	width;
	int	minus;
	int	zero;
	int	dot;
}	t_flags;

int	ft_printf(const char *fixed, ...);
int	ft_putint(int number);
int	ft_putunsint(unsigned int number);
int	ft_putoct(unsigned int number);
int	ft_puthex(char lettercase, int number);
int	ft_putpointer(unsigned long long number);
#endif
