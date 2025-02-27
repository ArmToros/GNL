/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:15:47 by vhambard          #+#    #+#             */
/*   Updated: 2025/02/26 19:17:21 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

//kpcnum enq irar toxery
static char	*ft_join_free(char *res, char *buff)
{	
	char	*temp;

	temp = ft_strjoin(res, buff);
	free(res);
	return (temp);
}

//bufferic hanum/grum enq mek tox
static char	*ft_extract_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc (i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

//buferic kardacac toxi vrov ancnum enq hajordin hasnelu hamar
static char	*ft_next_line(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	while (buffer[i])
		line[j++] = buffer [i++];
	free(buffer);
	return (line);
}

//reading from file to buffer/(res)
static	char	*read_file(int fd, char *res)
{
	char	*buff;
	int		byte_readed;

	if (!res)
		res = ft_calloc(1, 1);
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_readed = 1;
	while (byte_readed > 0)
	{
		byte_readed = read (fd, buff, BUFFER_SIZE);
		if (byte_readed == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[byte_readed] = 0;
		res = ft_join_free(res, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_extract_line(buffer);
	buffer = ft_next_line(buffer);
	return (line);
}
// int main()
// {
// 	int i =0;
// 	int fd = open("text.txt", O_RDONLY);
// 	while (i < 11)
// 	{
// 		char *p = get_next_line(fd);
// 		printf ("%s", p);
// 		i++;
// 	}
// }