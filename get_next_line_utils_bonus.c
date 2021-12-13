/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalio <sgalio@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:53:52 by sgalio            #+#    #+#             */
/*   Updated: 2021/12/13 15:53:54 by sgalio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	if (!s)
		return (0);
	i = ft_strlen(s) + 1;
	while (i)
	{
		if (*s == c)
			return (s);
		s++;
		i--;
	}
	return ((void *)0);
}

void	ft_strcpy(char *dst, char *src)
{
	size_t	i;

	i = 0;
	if (!src)
		return ;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strdup(char *s1)
{
	char	*str;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
	str = (char *)malloc(sizeof(*s1) * (len + 1));
	if (str != ((void *)0))
	{
		i = 0;
		while (i < len)
		{
			str[i] = s1[i];
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	else
		return ((void *)0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (str != ((void *)0))
	{
		ft_strcpy(str, s1);
		ft_strcpy(str + len1, s2);
		free((char *)s1);
		return (str);
	}
	else
		return ((void *)0);
}
