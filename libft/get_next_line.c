/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-qori <ael-qori@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:07:00 by ael-qori          #+#    #+#             */
/*   Updated: 2024/02/01 15:21:15 by ael-qori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_line(char *str, int fd)
{
	ssize_t	bytes;
	char	*buff;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(str, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		str = ft_strjoin_next(str, buff);
	}
	free(buff);
	return (str);
}

static char	*ft_put_str(char *str, char *s, size_t j)
{
	while (str[j])
	{
		if (str[j] == '\n')
		{
			s[j++] = '\n';
			s[j] = 0;
			return (s);
		}
		s[j] = str[j];
		j++;
	}
	s[j] = 0;
	return (s);
}

static char	*ft_get_return_line(char *str)
{
	size_t	i;
	size_t	j;
	char	*s;

	if (!*str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	s = malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	s = ft_put_str(str, s, j);
	return (s);
}

static char	*ft_move_to_other_line(char *str)
{
	size_t	i;
	size_t	j;
	char	*s;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	s = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!s)
		return (NULL);
	while (str[i])
		s[j++] = str[i++];
	s[j] = '\0';
	free(str);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buffer;

	buffer = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	str = ft_get_line(str, fd);
	if (str == NULL)
		return (NULL);
	buffer = ft_get_return_line(str);
	str = ft_move_to_other_line(str);
	return (buffer);
}
