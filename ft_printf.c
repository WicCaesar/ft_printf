/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 21:51:16 by cnascime          #+#    #+#             */
/*   Updated: 2022/08/10 07:25:11 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "./libft/libft.h"

// write(fd, &"0123456789abcdef"[str[i] / 16], 1);
// write(fd, &("0123456789abcdef"[str[i] / 16]), 1); testar segundo ruchoa
int	treatment(int fd, char character, va_list listofarguments)
{
	if (character == 'c')
		return (ft_putchar_fd(fd, va_arg(listofarguments, int)));
	if (character == 's')
		return (ft_putstr_fd(fd, va_arg(listofarguments, char *)));
	/*if (character == 'p')
		return (função(va_arg(listofarguments, long long unsigned int)));*/
	if (character == 'd' || character == 'i')
		return (ft_putint(va_arg(listofarguments, int)));
	if (character == 'u')
		return (ft_putunsint(va_arg(listofarguments, unsigned int)));
	/*if (character == 'o')
		return (função(va_arg(listofarguments, unsigned int)));
	if (character == 'x')
		return (função(va_arg(listofarguments, unsigned int)));
	if (character == 'X')
		return (função(va_arg(listofarguments, unsigned int)));*/
	if (character == '%')
		return (ft_putchar_fd(fd, character));
	return (0);
}

/* Manage all the following flags:
- Left-justify within the given field width; Right justification is the default.
0 ~Left-pads~ the number with zeroes (0) instead of spaces.
. precision (displays only .X amount of characters)
# Used with o, x or X specifiers, the value is ~preceded~ with 0, 0x or 0X
respectively for values different from zero.
Used with e, E and f, it forces the written output to contain a decimal point
even if no digits would follow.
By default, if no digits follow, no decimal point is written.
Used with g or G the result is the same as with e or E,
but trailing zeros are not removed.
+ Forces to precede the result with a + or - sign, even for positive numbers.
space If no sign is going to be written, a space is inserted before the value.

• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.
• va_start, va_arg, va_copy, va_end
• malloc, free, write 

For specifiers d and i, precision is the minimum number of digits to be print.
For the specifier s, the precision is the maximum field width.
Stay tuned when:

Flag '0' is ignored when flag '-' is present.
Flag '0' is ignored when flag '.' is present (%d e %i)
Flag '0' result in undefined behavior with specifier c, s and p
FLag '.' result in undefined behavior with specifier c and p
Syntax to use printf:
%[flag][min-width].[precision][length modifier][conversion specifier]*/

// The prototype of va_start defines what is "fixed" on the process, i.e. what
// value is to be "ignored". From there on, everything else is considered part
// of the list. For every va_start, there must be a va_end in the same function.
/* E.g.:		int multiply (int howmanyfactors, ...)
				va_list factors;
				va_start (factors, howmanyfactors);
								...
				printf("8! = %d\n", multiply(7, 8, 7, 6, 5, 4, 3, 2));
The first 7 is ignored, not part of the list, useful for the while loop.
The other numbers are considered part of the list. */
int	ft_printf(const char *fixed, ...)
{
	int		index;
	int		count;
	int		fd;
	va_list	listofarguments;

	index = 0;
	count = 0;
	fd = 1;
	va_start(listofarguments, fixed);
	while (fixed[index] != '\0')
	{
		if (fixed[index] == '%' && ft_strchr("cspdiuoxX%", fixed[index + 1]))
		{
			count += treatment(fd, fixed[index + 1], listofarguments);
			index++;
		}
		else
			count += ft_putchar_fd(fd, fixed[index]);
		index++;
	}
	va_end(listofarguments);
	return (count);
}
