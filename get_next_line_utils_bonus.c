/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarture <lbarture@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 20:07:09 by lbarture          #+#    #+#             */
/*   Updated: 2021/11/29 19:32:18 by lbarture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *string)
{
	size_t	a;

	if (!string)
		return (0);
	a = 0;
	while (string[a] != '\0')
	{
		a++;
	}
	return (a);
}

size_t	ft_strlcpy(char *dst, const	char *src, size_t dstsize)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	if (!src)
		return (0);
	while (src[x] != '\0')
		x++;
	if (dstsize != 0)
	{
		while (src[y] != '\0' && (dstsize - 1) > y)
		{
			dst[y] = src[y];
			y++;
		}
		dst[y] = '\0';
	}
	return (x);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	y;
	size_t	x;
	size_t	count;

	x = 0;
	y = ft_strlen(dst);
	while (src[x] != '\0')
		x++;
	if (y < dstsize && dstsize != 0)
	{
		dstsize = dstsize - y - 1;
		count = y + x;
		x = 0;
		while (src[x] != '\0' && dstsize != 0)
		{
			dst[y++] = src[x++];
			dstsize--;
		}
		dst[y] = '\0';
		return (count);
	}
	else
		return (dstsize + x);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count])
	{
		if (s[count] == (char)c)
			return ((char *)&s[count]);
		else
			count++;
	}
	if ((char)c == '\0')
		return ((char *)&s[count]);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	s_len;
	size_t	total;

	if (!s || !len)
		return (0);
	total = 0;
	s_len = ft_strlen((char *)s);
	total = len;
	if (start >= ft_strlen(s))
	{
		p = malloc(1);
		p[0] = '\0';
		return (p);
	}
	p = (char *)malloc(sizeof(char) * (total + 1));
	if (p)
	{
		ft_strlcpy (p, &s[start], total + 1);
		return (p);
	}
	else
		return (NULL);
}
