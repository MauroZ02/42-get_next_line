/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 19:06:59 by mzangaro          #+#    #+#             */
/*   Updated: 2024/11/02 20:34:34 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i++] && buffer[i++] != '\n')
	if (buffer[i] == '\n')
		line = ft_calloc(i + 2, sizeof(char *));
	else
		line = ft_calloc(i + 1, sizeof(char *));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i++] = buffer[i++];
	}
	if (buffer[i] == '\n')
	{
		line[i++] = '\n';
	}
	line[i] = '\0';
	return (line);
}

static char	*update_buffer(char *buffer, ssize_t *flag)
{
	char	*new_buffer;
	int		i;
	int		j;

	i = 0;
	while (buffer[i++] && buffer[i++] != '\n')
	if (!buffer[i])
	{
		free(buffer);
		*flag = 0;
		return (NULL);
	}
	new_buffer = ft_calloc(ft_strlen(buffer) - i, sizeof(char *));
	if (!new_buffer)
	{
		free(buffer)
		*flag = 1;
		return (NULL);
	}
	i++;
	j = 0;
	while (buffer[i] != '\0')
		new_buffer[j++] = buffer[i++];
	free(buffer);
	//*flag = 0;
	return (new_buffer);
}
