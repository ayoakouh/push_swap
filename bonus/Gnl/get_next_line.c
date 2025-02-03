/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoakouh <ayoakouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:02:12 by ayoakouh          #+#    #+#             */
/*   Updated: 2025/02/03 11:40:37 by ayoakouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *str)
{
	char	*store;
	ssize_t	n_byte;
	char	*temp;

	store = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!store)
		return (free(str), NULL);
	n_byte = 1;
	while (n_byte)
	{
		n_byte = read(fd, store, BUFFER_SIZE);
		if (n_byte == -1)
		{
			return (free(store), free(str), NULL);
		}
		store[n_byte] = '\0';
		temp = ft_strjoin2(str, store);
		if (!temp)
			return (free(str), str = NULL, free(store), NULL);
		str = temp;
		if (ft_strchr(str) == 1)
			break ;
	}
	return (free(store), str);
}

char	*extract_line(char *str)
{
	int		i;
	char	*new;

	i = 0;
	if (!str || str[0] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	new = malloc(i + 1);
	if (!new)
		return (str = NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		new[i] = str[i];
		i++;
	}
	return (new[i] = '\0', new);
}

char	*update_line(char *str)
{
	char	*ptr;
	int		i;
	int		j;

	ptr = NULL;
	i = 0;
	if (!str || str[0] == '\0')
		return (free(str), NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	ptr = (char *) malloc(ft_strlen(str) - i + 1);
	if (!ptr)
		return (free(str), str = NULL);
	j = 0;
	while (str[i])
	{
		ptr[j] = str[i];
		i++;
		j++;
	}
	ptr[j] = '\0';
	return (free(str), ptr);
}

char	*get_next_line(int fd)
{
	static char	*store;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store = read_line(fd, store);
	line = extract_line(store);
	if (!line)
		return (free(store), store = NULL, NULL);
	store = update_line (store);
	return (line);
}
