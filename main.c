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
	int	    da;

	laenn = (char**)malloc(sizeof(*laenn));
	fd2 = open("123test", O_RDONLY);
	fd = open("s_perenosom", O_RDONLY);
	//printf("%s\n", argv[1]);
	printf("fd: %d\n", fd);
	while ((da = get_next_line(fd, laenn)) > 0)
	{
        printf("%d: %s\n",da , *laenn);
    }
	printf("%d: %s\n", da, *laenn);
	i = 0;
	printf("fd2: %d\n", fd2);
    while ((da = get_next_line(fd2, laenn)) > 0)
    {
        printf("%d: %s\n", da, *laenn);
    }
    printf("%d: %s\n", da, *laenn);
    //get_next_line(fd, laenn);
    //printf("%s", *laenn);
	return (0);
}
