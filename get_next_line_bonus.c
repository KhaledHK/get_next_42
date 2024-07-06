/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khkhaled <khkhaled@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-22 10:35:29 by khkhaled          #+#    #+#             */
/*   Updated: 2024-06-22 10:35:29 by khkhaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*getlinge(char *st)
{
	int		i;
	char	*rt;

	if (!st || st[0] == '\0')
		return (NULL);
	i = 0;
	while (st[i] != '\n' && st[i])
		i++;
	if (st[i] == '\n')
		i++;
	rt = (char *)malloc(i + 1);
	if (!rt)
		return (NULL);
	i = 0;
	while (st[i] != '\n' && st[i])
	{
		rt[i] = st[i];
		i++;
	}
	if (st[i] == '\n')
		rt[i++] = '\n';
	rt[i] = '\0';
	return (rt);
}

char	*skipligne(char *st)
{
	int		i;
	int		j;
	char	*rt;

	i = 0;
	while (st[i] != '\n' && st[i])
		i++;
	if (st[i] == '\0')
	{
		free(st);
		return (NULL);
	}
	i += (st[i] == '\n');
	rt = (char *)malloc(ft_strlen(st) + 1 - i);
	if (!rt)
		return (NULL);
	j = 0;
	while (st[i + j])
	{
		rt[j] = st[i + j];
		j++;
	}
	rt[j] = '\0';
	free(st);
	return (rt);
}

char	*get_next_line(int fd)
{
	int			count_read;
	char		*str;
	static char	*st[1024] = {NULL};

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	count_read = 1;
	str = (char *)malloc(BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	while (!(ft_strchar(st[fd], '\n')) && count_read != 0)
	{
		count_read = read (fd, str, BUFFER_SIZE);
		if (count_read == -1)
		{
			free(str);
			return (NULL);
		}
		str[count_read] = '\0';
		st[fd] = ft_strjoin(st[fd], str);
	}
	free(str);
	str = getlinge(st[fd]);
	st[fd] = skipligne(st[fd]);
	return (str);
}
