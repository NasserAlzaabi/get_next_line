/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalzaab <naalzaab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:05:21 by naalzaab          #+#    #+#             */
/*   Updated: 2023/04/27 22:37:11 by naalzaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*delete_line(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	if (!str || str[0] == '\0')
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
		{
			temp = ft_substr(str, i + 1, ft_strlen(str));
			free (str);
			return (temp);
		}
		i++;
	}
	return (NULL);
}

char	*get_line(char *str)
{
	int	j;

	j = 0;
	if (!str || str[0] == '\0')
		return (NULL);
	while (str[j] != '\0')
	{
		if (str[j] == '\n')
			return (ft_substr(str, 0, j + 1));
		j++;
	}
	return (str);
}

char	*read_file(char *str, int fd)
{
	int		rd;
	char	*buff;

	buff = malloc((unsigned int)BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	rd = 1;
	while (!ft_strchr(str, '\n') && rd != 0)
	{
		rd = read(fd, buff, BUFFER_SIZE);
		if (rd == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rd] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = read_file(str, fd);
	if (!str)
		return (0);
	line = get_line(str);
	str = delete_line(str);
	return (line);
}
