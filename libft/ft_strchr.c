/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 18:23:17 by cnascime          #+#    #+#             */
/*   Updated: 2022/08/06 15:37:56 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Locates the first occurrence of a char in a given string. The terminating
// NUL-character is considered to be part of the string; therefore if c == \0,
// the function returns the pointer to the terminating \0.
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (0);
}
