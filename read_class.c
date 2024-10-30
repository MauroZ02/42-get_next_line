
#include <fcntl.h>
#include "get_next_line.h"


int main(int argc, char const *argv[])
{
	int 	fd;
	char	*buffer;
	if (argc < 2)
		return(printf("bad arguments\n"), EXIT_FAILURE);

	fd = open(argv[1], O_RDONLY);

	buffer = calloc(BUFFER_SIZE + 1, sizeof(char));
	read(fd, buffer, BUFFER_SIZE);

	printf("%s\n", buffer);
	return EXIT_SUCCESS;
}


/* 
1.- Hacer este comando:
ssh-keygen

2.- entras a ~/.ssh y luego 
 cat id_rsa.pub



 */