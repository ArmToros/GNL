/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhambard <vhambard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:15:27 by vhambard          #+#    #+#             */
/*   Updated: 2025/02/26 19:15:31 by vhambard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	i;
// 	size_t	len;

// 	i = 0;
// 	len = 0;
// 	if (dstsize == 0)
// 	{
// 		while (src[len] != '\0')
// 			len++;
// 		return (len);
// 	}
// 	while (src[i] != '\0' && i + 1 < dstsize)
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// 	while (src[len] != '\0')
// 		len++;
// 	return (len);
// }

// size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	len;
// 	size_t	l;
// 	size_t	i;

// 	l = 0;
// 	len = 0;
// 	i = 0;
// 	if ((!dst || !src) && !dstsize)
// 		return (0);
// 	while (dst[len] != '\0' && len < dstsize)
// 		len++;
// 	while (src[l] != '\0')
// 		l++;
// 	if (len < dstsize)
// 	{
// 		while (src[i] != '\0' && (len + i) < dstsize - 1)
// 		{
// 			dst[len + i] = src[i];
// 			i++;
// 		}
// 		dst[len + i] = '\0';
// 	}
// 	return (l + len);
// }

char	*ft_strchr(const char *s, int c)
{
	char	*res;

	res = (char *) s;
	while (*res != c && *res != '\0')
		res++;
	if (*res == c)
		return (res);
	else
		return (NULL);
}
// char	*ft_strdup(const char *s1)
// {
// 	char	*res;
// 	size_t	len;
// 	len = 0;
// 	while (s1[len] != '\0')
// 		len++;
// 	res = (char *) malloc(len + 1);
// 	if (res == NULL)
// 		return (NULL);
// 	ft_strlcpy(res, s1, len + 1);
// 	return (res);
// }

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len1;
	size_t	len2;
	size_t	len;

	len1 = 0;
	len2 = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *)malloc(len);
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[len1] != '\0')
	{
		res[len1] = s1[len1];
		len1++;
	}
	while (s2[len2] != '\0')
	{
		res[len1++] = s2[len2++];
	}
	res[len1] = '\0';
	return (res);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;
	size_t	i;
	size_t	len;

	len = count * size;
	mem = (char *)malloc(len);
	if (mem == NULL)
		return (0);
	i = 0;
	while (i < len)
		mem[i++] = 0;
	return ((void *) mem);
}

void	*ft_memset(void *b, int c, size_t len)
{
	char			*ptr;
	unsigned char	a;

	a = (unsigned char) c;
	ptr = b;
	while (len > 0)
	{
		*ptr++ = a ;
		len --;
	}
	return (b);
}

size_t	ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n] != '\0')
	{
		n++;
	}
	return (n);
}
