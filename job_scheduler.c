#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <strings.h>

int main ()
{
	int fd;
	char *tmp;


	fd = open("./Base/base.json", O_RDONLY);
	if (fd < 0)
		printf("Error reading file\n");
	else
	{
		tmp = (char *)malloc(100 * sizeof(char));
		while (read (fd, tmp, 100 * sizeof(char)) != 0)
		{
			printf("%s\n", tmp);
			bzero(tmp,100);
		}
		free(tmp);
	}
	return (0);
}
