/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamuller <mamuller@student.42wolfsburg>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 00:18:58 by mamuller          #+#    #+#             */
/*   Updated: 2021/06/10 00:18:58 by mamuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dest_p;
	char	*src_p;

	if (!dest && !src)
		return (NULL);
	dest_p = (char *)dest;
	src_p = (char *)src;
	i = 0;
	if (dest_p < src_p)
	{
		while (i < n)
		{
			dest_p[i] = src_p[i];
			i++;
		}
		return (dest);
	}
	while (n >= 1)
	{
		n--;
		dest_p[i + n] = src_p[n];
	}
	return (dest);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (s[i] == c)
		return ((char *)&s[i]);
	else
		return (NULL);
}

size_t	ft_strlen(char *s)
{
	int	len;

	len = 0;
	if (!s || s[0] == 0)
		return (0);
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2, int j)
{
	char	*return_s;
	int		len_s1;
	int		len_s2[2];
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2[0] = ft_strlen(s2);
	len_s2[1] = len_s2[0] - (ft_strchr(s2, '\0') - ft_strchr(s2, '\n'));
	return_s = malloc(sizeof(char) * (len_s1 + len_s2[j] + 1) + 1);
	if (return_s == NULL)
		return (NULL);
	while (i < len_s1 + len_s2[j] + 1)
	{
		if (i < len_s1)
			return_s[i] = s1[i];
		else
			return_s[i] = s2[i - len_s1];
		i++;
	}
	return_s[(len_s1 + len_s2[j] + 1)] = '\0';
	free(s1);
	return (return_s);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
