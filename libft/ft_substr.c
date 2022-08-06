/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 05:16:47 by cnascime          #+#    #+#             */
/*   Updated: 2022/06/08 19:41:31 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates with malloc and returns a substring from the string s.
// The string begins at index 'start' and is of maximum size 'len'.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (!s)
		return (NULL);
	if ((size_t)start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start >= len)
		substr = malloc(len + 1);
	else
		substr = malloc(ft_strlen(s) - start + 1);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, (s + start), (len + 1));
	return (substr);
}
