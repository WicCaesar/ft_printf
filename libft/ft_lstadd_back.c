/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnascime <cnascime@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 21:47:26 by cnascime          #+#    #+#             */
/*   Updated: 2022/06/14 19:18:39 by cnascime         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*penultimate;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	penultimate = ft_lstlast(*lst);
	penultimate->next = new;
}
