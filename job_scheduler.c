#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <strings.h>
#include <sys/stat.h>

typedef struct Jobs
{
	int id;
	char *desc;
	char *data;
	int time;
} jobs;

long int get_file_length(int fd)
{
	int l;
	struct stat buf;

	fstat(fd, &buf);
	l = buf.st_size + 1;
	return l;
}

int main ()
{
	int fd;
	char *tmp;
	jobs j1, j2, j3;

	fd = open("./Base/base.json", O_RDONLY);
	if (fd < 0)
	{
		printf("Error reading file\n");
		return (0);
	}
	tmp = (char *)malloc(get_file_length(fd) * sizeof(char));
	read (fd, tmp, get_file_length(fd) * sizeof(char));
	printf("%s", tmp);
	free(tmp);
	return (0);
}
