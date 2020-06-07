#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <strings.h>
#include <sys/stat.h>

typedef struct	j_list
{
	int 			id;
	char 			*desc;
	char 			*data;
	int 			time;
	struct j_list	*next;
}				jobs;

long int get_file_length(int fd)
{
	int l;
	struct stat buf;

	fstat(fd, &buf);
	l = buf.st_size;
	return l;
}

int open_file (char *path)
{
	int			fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		printf("Error reading file\n");
	return (fd);
}

char *read_file(int fd)
{
	char 		*tmp;
	long int	len;

	len = get_file_length(fd);
	if (!(tmp = (char *)malloc((len + 1) * sizeof(char))))
	{
		printf("Error alocating buffer\n");
		return (NULL);
	}
	bzero(tmp, (len + 1));
	read (fd, tmp, len * sizeof(char));
	return (tmp);
}

jobs *new_job(int id, char *desc, char *data, char *time)
{
	jobs *j;

	if (!(j = (jobs *)malloc(sizeof(jobs))));
	{
		printf("Error alocating Job List\n");
		exit;
	}
	j->id = id;
	j->desc = desc;
	j->data = data;
	j->time = time;
	j->next = NULL;
	return (j);
}

jobs *add_job(jobs *j)
{
	jobs *current;

	current = j;
	while (current->next != NULL)
		current=current->next;
	current->next = j;
}

jobs *get_jobs(char *tmp)
{
	int 	i;

	while (tmp[i] != 0)
	{

	}
}

int main ()
{
	int			fd;
	char		*tmp;
	char		*path;
	long int	len;

	path = "../base/base.json";
	if (open_file(path) == -1)
		return (0);
	fd = open_file(path);
	tmp = read_file(fd);
	printf("%s", tmp);
	free(tmp);
	return (0);
}
