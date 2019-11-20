#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int main(int argc, char **argv)
{
	char	**laenn;
	int		fd;
	int     i;
	int     fd2;

	laenn = (char**)malloc(sizeof(*laenn));
	fd = open("getme.txt", O_RDONLY);
	fd2 = open("getme2.txt", O_RDONLY);
	//printf("%s\n", argv[1]);
	printf("fd: %d\n", fd);
	while (get_next_line(fd, laenn))
	{
        printf("%d: %s\n",i++ , *laenn);
    }
	printf("%d: %s\n", i, *laenn);
	i = 0;
    while (get_next_line(fd2, laenn))
    {
        printf("%d: %s\n", i++, *laenn);
    }
    printf("%d: %s\n", i, *laenn);
    //get_next_line(fd, laenn);
    //printf("%s", *laenn);
	return (0);
}
