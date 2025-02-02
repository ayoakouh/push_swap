// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   get_next_line_utils.c                              :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ayoakouh <ayoakouh@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/11/28 03:25:55 by ayoakouh          #+#    #+#             */
// /*   Updated: 2024/12/09 11:12:47 by ayoakouh         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "get_next_line.h"

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	int		i;
// 	size_t	len1;
// 	char	*new;

// 	if (!s1 && !s2)
// 		return (NULL);
// 	if (!s1)
// 		return (ft_strdup(s2));
// 	if (!s2)
// 		return (ft_strdup(s1));
// 	len1 = ft_strlen(s1);
// 	new = malloc((len1 + ft_strlen(s2) + 1) * sizeof(char));
// 	if (!new)
// 		return (NULL);
// 	i = -1;
// 	while (s1[++i])
// 		new[i] = s1[i];
// 	i = -1;
// 	while (s2[++i])
// 	{
// 		new[len1] = s2[i];
// 		len1++;
// 	}
// 	new[len1] = '\0';
// 	return (free(s1), new);
// }

// int	ft_strchr(char *s)
// {
// 	int	i;

// 	i = 0;
// 	if (!s)
// 		return (0);
// 	while (s[i])
// 	{
// 		if (s[i] == '\n')
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// size_t	ft_strlen(const char *str)
// {
// 	int	i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// char	*ft_strdup(const char *s)
// {
// 	char	*ptr;
// 	int		i;

// 	i = 0;
// 	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
// 	if (ptr == NULL)
// 		return (NULL);
// 	while (s[i] != '\0')
// 	{
// 		ptr[i] = s[i];
// 		i++;
// 	}
// 	ptr[i] = '\0';
// 	return (ptr);
// }
