/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khkhaled <khkhaled@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-22 07:43:46 by khkhaled          #+#    #+#             */
/*   Updated: 2024-06-22 07:43:46 by khkhaled         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

size_t	ft_strlen(char *str);
char	*ft_strchar(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_join(char *s3, char *s1, char *s2);
char	*getlinge(char *st);
char	*skipligne(char *st);
char	*get_next_line(int fd);

#endif
