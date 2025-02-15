/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armtoros <armtoros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 16:59:08 by armtoros          #+#    #+#             */
/*   Updated: 2025/02/15 14:42:00 by armtoros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		*res;
	char		*buff;
	char		*dest;
	ssize_t		tmp;
	int			flag;
	int			currl;
	int			nullflag;

	res = "";
	flag = 0;
	currl = 0;
	nullflag = 0;
	if (!nullflag)
	while (!flag)
	{
		buff = (char *)malloc(31);
		if (!buff)
			return (NULL);
		buff[30] = '\0';
		tmp = read(fd, buff, 30);
		if (tmp == 30)
		{
			dest = ft_strchr(buff, '\n');
			if (!dest)
			{
				res = ft_strjoin(res, buff);
			}
			else
			{
				flag = 1;
				*dest = '\0';
				res = ft_strjoin(res, buff);
			}
		}
		else
		{
			buff[tmp] = '\0';
			dest = ft_strchr(buff, '\n');
			if (!dest)
			{
				res = ft_strjoin(res, buff);
			}
			else
			{
				flag = 1;
				*dest = '\0';
				res = ft_strjoin(res, buff);
			}
			flag = 1;
		}
		free(buff);
	}
	//line++;
	if (nullflag)
		return (NULL);
	return (ft_strdup(res));
}

int main()
{
	int i =0;
	int fd = open("text.txt", O_RDONLY);
	while (i++ < 3)
	{
		char *p = get_next_line(fd);
		write(1, p, ft_strlen(p));
		printf("\n");
	}
}