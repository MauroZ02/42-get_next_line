/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:40:03 by mzangaro          #+#    #+#             */
/*   Updated: 2024/11/10 14:52:43 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t n, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = malloc(n * size);
	if (ptr == NULL)
		return (NULL);
	while (i < n * size)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size <= len_dst)
		return (size + len_src);
	i = 0;
	while (src[i] != '\0' && size > (len_dst + 1))
	{
		dst[len_dst] = src[i];
		i++;
		len_dst++;
	}
	dst[len_dst] = '\0';
	return (len_dst + ft_strlen(&src[i]));
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!(size == 0))
	{
		while (src[i] != '\0' && i < size -1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	i = 0;
	j = 0;
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	join = ft_calloc(i + j + 1, sizeof(char));
	if (!join)
		return (NULL);
	ft_strlcpy(join, (char *)s1, i + 1);
	ft_strlcat(join, s2, i + j + 1);
	return (join);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
