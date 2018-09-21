/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmakgale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 11:40:15 by tmakgale          #+#    #+#             */
/*   Updated: 2017/08/17 15:43:43 by tmakgale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;
	char	char_pos;

	char_pos = c;
	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == char_pos)
			return (ptr);
		ptr++;
	}
	if (*ptr == char_pos)
		return (ptr);
	else
		return (NULL);
}
