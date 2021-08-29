/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebalgruu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 12:03:09 by ebalgruu          #+#    #+#             */
/*   Updated: 2021/08/27 12:03:11 by ebalgruu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *str1, char *str2)
{
	size_t	i;
	int		null_status;

	null_status = 0;
	i = 0;
	if (str1 == NULL)
	{
		null_status += 1;
		return (1);
	}
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (1);
		i++;
	}
	if (str1[i] == '\0' && i == 0)
		return (1);
	return (0);
}

char	*ft_strdup(char *s1)
{
	char	*s;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	s = (char *) malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	str = (char *) malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[j])
	{
		str[j] = s1[j];
		j++;
	}
	while (s2[i])
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
