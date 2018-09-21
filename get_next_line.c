/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmakgale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 10:02:51 by tmakgale          #+#    #+#             */
/*   Updated: 2017/06/23 11:57:04 by tmakgale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		read_to_stack(int const fd, char **stack)
{
	char	*buff;
	int		value;
	char	*temp;

	if (!(buff = (char *)malloc(sizeof(*buff) * (BUFF_SIZE + 1))))
		return (-1);
	value = read(fd, buff, BUFF_SIZE);
	if (value > 0)
	{
		buff[value] = '\0';
		temp = ft_strjoin(*stack, buff);
		free(*stack);
		*stack = temp;
	}
	free(buff);
	return (value);
}

int				get_next_line(int const fd, char **line)
{
	static char	*stack = NULL;
	char		*bn;
	int			value;

	if ((!stack && (stack = (char *)malloc(sizeof(*stack))) == NULL) || !line
			|| fd < 0 || BUFF_SIZE < 0)
		return (-1);
	bn = ft_strchr(stack, '\n');
	while (bn == NULL)
	{
		value = read_to_stack(fd, &stack);
		if (value == 0)
		{
			if (ft_strlen(stack) == 0)
				return (0);
			stack = ft_strjoin(stack, "\n");
		}
		if (value < 0)
			return (-1);
		else
			bn = ft_strchr(stack, '\n');
	}
	*line = ft_strsub(stack, 0, ft_strlen(stack) - ft_strlen(bn));
	stack = ft_strdup(bn + 1);
	return (1);
}
