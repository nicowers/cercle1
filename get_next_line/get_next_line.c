/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndebavel <ndebavel@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:45:43 by ndebavel          #+#    #+#             */
/*   Updated: 2025/11/12 15:23:11 by ndebavel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *save_rest(char *rest)
{
	int i;
	char *tab;

	i = 0;
	if (!rest)
		return (NULL);
	while (rest[i] != '\n' && rest[i])
		i++;
	if (rest[i] == '\0' || rest[i + 1] == '\0')
		return (free(rest), NULL);
	tab = malloc(sizeof(char) * (ft_strlen(&rest[i + 1]) + 1));
	if (!tab)
		return (free(rest), NULL);
	ft_strlcpy(tab , &rest[i + 1], (ft_strlen(&rest[i + 1]) + 1));
	free(rest);
	return (tab);
}

char *createline(char *str)
{
	int i;
	char *cpy;

	i = 0;
	if (!str || !str[0])
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	cpy = malloc(sizeof(char) * (i + (str[i] == '\n') + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		cpy[i] = '\n';
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char *readline(int fd, char *stock)
{
	char *str;
	int len;

	len = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 )
		return (free(stock), NULL);
	while ((!stock || !ft_strchr(stock, '\n')) && len > 0)
	{
		str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!str)
			return (free(stock), NULL);
		len = read(fd, str, BUFFER_SIZE);
		if (len < 0)
			return (free(stock), free(str), NULL);
		str[len] = '\0';
		if (!stock)
			stock = ft_strdup(str);
		else
			stock = ft_strjoin(stock, str);
		if (!stock)
			return (free(str), NULL);
		free(str);
		str = NULL;
	}
	return (stock);
}

char *get_next_line(int fd)
{
	static char *stash;
	char *temp;

	if (fd < 0 || BUFFER_SIZE <= 0 )
		return (NULL);
	stash = readline(fd, stash);
	if (!stash)
		return (NULL);
	temp = createline(stash);
	stash = save_rest(stash);
	return (temp);
}

int main(void)
{
    int fr;
    char *str;

    fr = open("fichier.txt", O_RDONLY);
    if (fr < 0)
        return (1);
    str = get_next_line(fr);
    while (str != NULL)
    {
        printf("%s", str);
        free(str);
        str = get_next_line(fr);
    }
    close(fr);
    return (0);
}