/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: string <string>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 07:58:07 by kousuzuk          #+#    #+#             */
/*   Updated: 2023/07/03 08:07:10 by string           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *input, char *str)
{
	char	*str_concat;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!input)
		input = ft_calloc(1, sizeof(char));
	if (!input || !str)
		return (NULL);
	str_concat = malloc(sizeof(char) * (ft_strlen(input) + ft_strlen(str) + 1));
	if (!str_concat)
		return (NULL);
	while (input[i] != '\0')
	{
		str_concat[i] = input[i];
		i++;
	}
	while (str[j] != '\0')
		str_concat[i++] = str[j++];
	str_concat[ft_strlen(input) + ft_strlen(str)] = '\0';
	free(input);
	return (str_concat);
}

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*(unsigned char *)s++ = '\0';
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;
	size_t	t;

	if (size == 0 || nmemb == 0)
		return (ft_calloc(1, 1));
	if (nmemb > SIZE_MAX / size)
		return (NULL);
	t = nmemb * size;
	if (t / nmemb != size)
		return (NULL);
	s = malloc(sizeof(void) * t);
	if (!s)
		return (NULL);
	ft_bzero(s, nmemb * size);
	return (s);
}
