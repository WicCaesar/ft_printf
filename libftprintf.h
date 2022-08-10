/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 20:13:09 by cnascime          #+#    #+#             */
/*   Updated: 2022/08/10 07:29:08 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include "libft/libft.h"
# define BASEOCT "01234567"
# define BASEDEC "0123456789"
# define BASEHEX "0123456789abcdef"
# define BASEHEXUPPER "0123456789ABCDEF"

typedef struct s_flags
{
	int	width;
	int	minus;
	int	zero;
	int	dot;
}	t_flags;

int	ft_printf(const char *fixed, ...);
int	ft_putint(int number);
int	ft_putunsint(int number);
#endif
