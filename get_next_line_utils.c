/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naalzaab <naalzaab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 18:05:44 by naalzaab          #+#    #+#             */
/*   Updated: 2023/04/30 17:39:11 by naalzaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *saved, char *buffer)
{
	int		i;
	int		j;
	char	*joined;

	i = 0;
	j = 0;
	if (!saved)
	{
		saved = (char *)malloc(1);
		saved[0] = '\0';
	}
	if (!buffer)
		return (NULL);
	joined = (char *)malloc((ft_strlen(saved) + ft_strlen(buffer) + 1));
	if (!joined)
		return (free(saved), NULL);
	while (saved[i])
		joined[j++] = saved[i++];
	i = 0;
	while (buffer[i])
		joined[j++] = buffer[i++];
	joined[j] = '\0';
	if (joined[0] == '\0')
		return (free(saved), free(joined), NULL);
	return (free(saved), joined);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == 0)
		return (s);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (s);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s[0] == '\0')
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	n;
	char	*str;

	n = 0;
	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (i >= start && n < len)
			str[n++] = s[i];
		i++;
	}
	str[n] = '\0';
	return (str);
}

char	*ft_strdup(char *s1)
{
	char	*r;
	int		i;
	int		j;

	j = 0;
	i = 0;
	r = malloc(ft_strlen(s1) + 1);
	if (!r)
		return (NULL);
	while (s1[i])
		r[j++] = s1[i++];
	r[j] = '\0';
	return (r);
}
