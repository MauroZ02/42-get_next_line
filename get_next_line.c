/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:23:56 by mzangaro          #+#    #+#             */
/*   Updated: 2024/10/30 19:21:57 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_from_file(int fd)
{
	int			bytes_read;
	char		*buf;
	
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read (fd, buf, BUFFER_SIZE);
		buf[bytes_read] = '\0';
		buffer = append_buffer(buffer, buf);
	}
	if (bytes_read == -1)
		return (free (buf), NULL);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	buffer = ft_calloc(1, sizeof(char));
	if	(!ft_strchr(buffer, '\n'))
		return (free(buffer), NULL);
	buffer = obtain_remaining(buffer);
	return (line);
}

char *append_buffer(char *buffer, char *read_buffer)
{
 char *temp;

 temp = ft_strjoin(basin_buffer, read_buffer);
 free(basin_buffer);
 return (temp);
}

int main()
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open("example.txt", O_RDONLY);
	if (fd == -1)
	{
		write (1, "Error opening file", 18);
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		count++;
		printf("[%d]:%s\n", count, line); //count is to show the line numbers
		free(line);
		line = NULL;
	}
	close(fd);
	return 0;
}

// int read_file(int fd)
// {
// 	int		fd;
// 	char	buf[27];
// 	ssize_t	nr_bytes;

// 	fd = open("/home/mzangaro/Desktop/Common Course/Milestone 1/get_next_line/hola.txt", O_RDONLY);
// 	if (fd == -1)
// 		write (1, "Error opening the file", 22);
// 	else
// 	{
// 		nr_bytes = read(fd, buf, 27);
// 		if (nr_bytes == 0)
// 			write (1, "Empty file", 15);
// 		if (nr_bytes != "\n")
// 			return (fd);
// 			printf("number of chars: %d, content: %s", (int)nr_bytes, buf);
// 		if (nr_bytes == "\n")

// 	close(fd);
// 	}
// 	return 0;
// }
