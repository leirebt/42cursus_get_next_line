/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarture <lbarture@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 21:09:54 by lbarture          #+#    #+#             */
/*   Updated: 2021/12/01 18:58:13 by lbarture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line.h"

char	*update_holder(char *holder, char *line)
{
	char	*up;

	if (!ft_strchr(holder, '\n') || ft_strlen(holder) == 0)
	{
		free(holder);
		return (NULL);
	}	
	up = ft_substr(holder, ft_strlen(line), ft_strlen(holder));
	free(holder);
	return (up);
}

char	*create_line(char *holder)
{
	char	*end_line;
	char	*line;

	if (ft_strchr(holder, '\n'))
	{
		end_line = ft_strchr(holder, '\n');
		line = (char *)malloc((ft_strlen(holder) - ft_strlen(end_line) + 2));
		ft_strlcpy(line, holder, (ft_strlen(holder) - ft_strlen(end_line) + 2));
	}
	else
	{
		line = (char *)malloc((ft_strlen(holder) + 1));
		ft_strlcpy(line, holder, ft_strlen(holder) + 1);
	}
	return (line);
}

char	*create_holder(char *buf, char *holder)
{
	int		pos;
	char	*temp;
	size_t	total_len;

	pos = -1;
	if (!holder)
	{
		temp = (char *)malloc(((ft_strlen((char *)buf)) + 1));
		if (!temp)
			return (NULL);
		while (buf[++pos])
			temp[pos] = (char)buf[pos];
		temp[pos] = '\0';
	}
	else
	{
		total_len = ft_strlen(holder) + ft_strlen(buf);
		temp = (char *)malloc(total_len + 1);
		ft_strlcpy(temp, holder, ft_strlen(holder) + 1);
		ft_strlcat(temp, buf, total_len + 1);
		free(holder);
	}
	return (temp);
}

char	*read_fd(char *holder, int fd, int buffer)
{
	int		bytes;
	char	*buf;

	bytes = 1;
	buf = (char *)malloc(buffer + 1);
	if (!buf)
		return (NULL);
	while (!ft_strchr(holder, '\n') && bytes)
	{
		bytes = read(fd, buf, buffer);
		if (bytes < 0 || (bytes == 0 && ft_strlen(holder) == 0))
		{
			free(buf);
			if (bytes == 0 && ft_strlen(holder) == 0)
				free(holder);
			return (NULL);
		}
		buf[bytes] = '\0';
		holder = create_holder(buf, holder);
	}
	free(buf);
	return (holder);
}

char	*get_next_line(int fd)
{
	static char	*holder;
	char		*line;

	line = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	holder = read_fd(holder, fd, BUFFER_SIZE);
	if (!holder)
		return (0);
	line = create_line (holder);
	holder = update_holder (holder, line);
	return (line);
}
