/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndebavel <ndebavel@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:26:15 by ndebavel          #+#    #+#             */
/*   Updated: 2025/11/11 11:26:36 by ndebavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line_bonus.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size >= 1)
	{
		while (src[i] && i + 1 < size)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char *ft_strchr(const char *str, int searchchar)
{
	int c;
	int i;

	i = 0;
	c = (char) searchchar;
	while (str[i])
	{
		if (str[i] == c)
		{
			return ((char *) &str[i]);
		}
		i++;
	}
	if (str[i] == c)
		return ((char *) &str[i]);
	return (NULL);
}
char	*ft_strdup(const char *s)
{
	char	*tab;
	size_t	i;

	i = 0;
	tab = (char *) malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!tab)
	{
		return (NULL);
	}
	while (s[i])
	{
		tab[i] = s[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*final_s;

	i = 0;
	j = 0;
	final_s = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!final_s)
	{
		return (free(s1), NULL);
	}
	while (s1[i])
	{
		final_s[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		final_s[i] = s2[j];
		i++;
		j++;
	}
	final_s[i] = '\0';
	free(s1);
	return (final_s);
}
