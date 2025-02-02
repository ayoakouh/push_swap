/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoakouh <ayoakouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:33:19 by ayoakouh          #+#    #+#             */
/*   Updated: 2025/01/30 17:33:28 by ayoakouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	**free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static char	*ft_strncpy(char *dest, char const *src, int len)
{
	int	i;

	i = 0;
	while (src[i] && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	fill_array(char const *s, char **array, char c, int count)
{
	int	len;
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (s[i] && j < count)
	{
		while (s[i] == c)
			i++;
		len = i;
		while (s[i] != c && s[i])
			i++;
		array[j] = (char *)malloc(sizeof(char) * (i - len + 1));
		if (!array[j])
			return (0);
		array[j] = ft_strncpy(array[j], &s[len], (i - len));
		j++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		count;
	int		checker;
	char	**p;

	if (!*s || !s[0])
		return (NULL);
	count = count_word(s, c);
	array = (char **)malloc(sizeof(char *) * (count + 1));
	if (!array)
		return (NULL);
	array[count] = 0;
	checker = fill_array(s, array, c, count);
	if (checker == 0)
	{
		p = free_array(array);
		return (p);
	}
	return (array);
}
