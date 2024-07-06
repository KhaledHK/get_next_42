/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khkhaled <khkhaled@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-21 11:42:48 by khkhaled          #+#    #+#             */
/*   Updated: 2024-06-21 11:42:48 by khkhaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*st;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	count_read = 1;
	str = (char *)malloc(BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	while (!(ft_strchar(st, '\n')) && count_read != 0)
	{
		count_read = read (fd, str, BUFFER_SIZE);
		if (count_read == -1)
		{
			free(str);
			return (NULL);
		}
		str[count_read] = '\0';
		st = ft_strjoin(st, str);
	}
	free(str);
	str = getlinge(st);
	st = skipligne(st);
	return (str);
}

// #include <stdio.h>
// #include <fcntl.h>
// int main()
// {
// 	printf("%d\n\n", BUFFER_SIZE);
// 	int fd = open("test",O_RDONLY);
// 	char *s;
// 	s = get_next_line(fd);
// 	while (s)
// 	{
// 		printf("%s",s);
// 		s = get_next_line(fd);
// 	}
// 	close(fd);
// 	return 0;

// 	// char *s1 , *s2 , *s3;
// 	// s1 = "khaled";
// 	// s2 = "hassan";
// 	// s3 = ft_strjoin(s1,s2);
// 	// printf("%s",s3);
// }
